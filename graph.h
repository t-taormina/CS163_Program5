// Tyler Taormina
// taormina@pdx.edu
// August 2022
// Program 5

#include "option.h"

enum direction {
  NORTH = 0, 
  EAST = 1, 
  SOUTH = 2,
  WEST = 3
};

struct vertex
{
  Intersection* intersection;
  struct node* head;
  bool visited;
};

struct node
{
  vertex* adjacent;
  direction cardinal_direction;
  node* next;
};

class Graph 
{
  public: 
    Graph(int size);
    ~Graph();

    int insert_vertex(Intersection& intersection_add);
    int insert_edge(string current_vertex, string to_attach);
    int display_all();
    int display_adjacent(string key);
    int find_index(string key);

  private:
    vertex * adjacency_list;
    int list_size;
};
