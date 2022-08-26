// Tyler Taormina
// taormina@pdx.edu
// August 2022
// Program 5

// GITHUB : https://github.com/till-t/CS163-Program5.git

#include "graph.h"


Graph::Graph(int size)
{
  adjacency_list = new vertex [size];
  list_size = size;
  for (int i = 0; i < size; i++)
  {
    adjacency_list[i].head = nullptr;
    adjacency_list[i].intersection = nullptr;
    adjacency_list[i].visited = false;
  }
}

Graph::~Graph()
{
  delete [] adjacency_list;
}


int Graph::insert_vertex(Intersection& to_copy)
{
  if (!adjacency_list)
    return FAIL;
  for (int i = 0; i < list_size; i++)
  {
    if (adjacency_list[i].intersection == nullptr)
    {
      adjacency_list[i].intersection = new Intersection;
      adjacency_list[i].intersection->copy(to_copy);
      return i;
    }
  }
  return FAIL; 
}


int Graph::insert_edge(string current_vertex, string to_attach)
{
  if (!adjacency_list)
    return FAIL;
  int vertex_index = find_index(current_vertex);
  int attach_index = find_index(to_attach);
  if (vertex_index >= list_size || attach_index >=list_size)
    return FAIL;
  node* temp = adjacency_list[vertex_index].head;
  while(temp->adjacent)
    temp = temp->next;
  temp = new node;
  temp->adjacent = &adjacency_list[attach_index];
  return vertex_index;
}


int Graph::display_all()
{
  if (!adjacency_list)
    return FAIL;
  for (int i = 0; i < list_size; i++)
  {
    if (adjacency_list[i].intersection)
    {
      adjacency_list[i].intersection->display();
      if (adjacency_list[i].head)
      {
        node* temp = adjacency_list[i].head;
        while (temp->next)
        {
          temp->adjacent->intersection->display();
          temp = temp->next;
        }
        temp->adjacent->intersection->display();
      }
    }
  }
  return 0;
}

int Graph::display_adjacent(string key)
{
}

int Graph::find_index(string key)
{
  int success = FAIL;
  if (!adjacency_list)
    return success;
  for (int i = 0; i < list_size; i++)
  {
    if (adjacency_list[i].intersection->is_match(key))
      success = i;
  }
  return success;
}

