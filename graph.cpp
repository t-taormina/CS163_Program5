// Tyler Taormina
// taormina@pdx.edu
// August 2022
// Program 5

// GITHUB : https://github.com/till-t/CS163-Program5.git

// Graph class- The graph class is designed to provide access to directions by linking
// intersections (see intersection.h) that the user inputs. The graph data structure is
// constructed using an array of vertex objects and head pointers. The head pointers point
// to a linear linked list which is used to provide connections (edges) to other
// vertexes (and in turn intersections). 


#include "graph.h"

// Constructor 
// Takes an integer size that is used to determine the length of the array. Initializes
// all vertex data fields to nullptr.
Graph::Graph(int size)
{
  adjacency_list = new vertex [size];
  list_size = size;
  for (int i = 0; i < size; i++)
  { adjacency_list[i].head = nullptr;
    adjacency_list[i].intersection = nullptr;
  }
}


// Deconstructor
Graph::~Graph()
{
  node* temp;
  for (int i = 0; i < list_size; i++)
  {
    while (adjacency_list[i].head)
    {
      temp = adjacency_list[i].head->next;
      delete adjacency_list[i].head;
      adjacency_list[i].head = temp;
    }
    adjacency_list[i].head = nullptr;
    if (adjacency_list[i].intersection)
    {
      delete adjacency_list[i].intersection;
      adjacency_list[i].intersection = nullptr;
    }
  }
  if (adjacency_list)
  {
    delete [] adjacency_list;
    adjacency_list = nullptr;
  }
}

// @DEV
// Args -> Intersection object to add to graph
// Returns -> Index of location that the passed Intersection was added.
//            FAIL if there is no empty indexes in the array
int Graph::insert_vertex(Intersection& to_add)
{
  if (!adjacency_list)
    return FAIL;
  for (int i = 0; i < list_size; i++)
  {
    if (adjacency_list[i].intersection == nullptr)
    {
      adjacency_list[i].intersection = new Intersection;
      adjacency_list[i].intersection->copy(to_add);
      return i;
    }
  }
  return FAIL; 
}

// @DEV
// Args -> String of vertex to match
//         String of another vertex to match
// Returns -> Index of location that an edge was added.
//            FAIL if the adjacency list is empty,
//                 if the strings passed are not found
int Graph::insert_edge(string current_vertex, string to_attach)
{
  if (!adjacency_list)
    return FAIL;
  int vertex_index = find_index(current_vertex);
  int attach_index = find_index(to_attach);
  if (vertex_index >= list_size || attach_index >=list_size)
    return FAIL;
  if (!adjacency_list[vertex_index].head)
  {
    adjacency_list[vertex_index].head = new node;
    adjacency_list[vertex_index].head->adjacent = &adjacency_list[attach_index];
    adjacency_list[vertex_index].head->next = nullptr;
  } else 
  {
    node* temp = adjacency_list[vertex_index].head;
    while(temp->next)
      temp = temp->next;
    node* add = new node;
    add->adjacent = &adjacency_list[attach_index];
    temp->next = add;
  }
  return vertex_index;
}

// @DEV
// Args -> None 
// Returns ->     if the strings passed are not found
int Graph::display_all()
{
  if (!adjacency_list)
    return FAIL;
  for (int i = 0; i < list_size; i++)
  { 
    cout << "VERTEX " << i+1 << " ==================" << endl;
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
  int count = 0;
  if (adjacency_list[index].intersection)
  {
    adjacency_list[index].intersection->display();
    count++;
    cout << endl;
    node* temp = adjacency_list[index].head;
    while (temp)
    {
      cout << "is connected to ... " << endl;
      temp->adjacent->intersection->display();
      cout << endl;
      count++;
      temp = temp->next;
    }
  }
  return count;
}


int Graph::find_index(string key)
{
  if (!adjacency_list)
    return FAIL;
  for (int i = 0; i < list_size; i++)
  {
    if (adjacency_list[i].intersection)
    {
      if (adjacency_list[i].intersection->is_match(key))
        return i;
    }
  }
  return FAIL;
}

