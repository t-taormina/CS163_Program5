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
  /*
  node* temp = adjacency_list[vertex_index].head;
  while(temp)
    temp = temp->next;
    */
  node* temp = new node;
  temp->adjacent = &adjacency_list[attach_index];
  temp->next = adjacency_list[vertex_index].head;
  adjacency_list[vertex_index].head = temp;
  //temp->adjacent->intersection->display();
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
      cout << endl;
      if (adjacency_list[i].head)
      {
        node* temp = adjacency_list[i].head;
        while (temp)
        {
          temp->adjacent->intersection->display();
          cout << endl;
          temp = temp->next;
        }
      }
    }
  }
  return 0;
}

int Graph::display_adjacent(string key)
{
  if (!adjacency_list)
    return FAIL;
  int index = find_index(key);
  if (index >= list_size)
    return FAIL;
  node* temp = adjacency_list[index].head;
  int count = 0;
  adjacency_list[index].intersection->display();
  while (temp)
  {
    temp->adjacent->intersection->display();
    count++;
    temp = temp->next;
  }
  return count;
}

int Graph::find_index(string key)
{
  if (!adjacency_list)
    return FAIL;
  for (int i = 0; i < list_size; i++)
  {
    if (adjacency_list[i].intersection->is_match(key))
      return i;
  }
  return FAIL;
}

