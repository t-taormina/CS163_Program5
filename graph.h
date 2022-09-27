// Tyler Taormina
// taormina@pdx.edu
// August 2022
// Program 5


#include "intersection.h"

// Vertex struct- object that holds a intersection and a head pointer node(see node struct below). The head pointer is
// used to create a linear linked list. This linear linked list represents adjacent
// intersections. 
struct vertex
{
  Intersection* intersection;
  struct node* head;
};

// node struct- object that holds a pointer to an adjacent vertex as well as a node
// pointer to the next adjacent node.
struct node
{
  vertex* adjacent;
  node* next;
};


// Graph class- The graph class is designed to provide access to directions by linking
// intersections (see intersection.h) that the user inputs. The graph data structure is
// constructed using an array of vertex objects and head pointers. The head pointers point
// to a linear linked list which is used to provide connections (edges) to other
// vertexes (and in turn intersections). 

class Graph 
{
  public: 
    // Constructor
    Graph(int size);

    // Deconstructor
    ~Graph();

    // Takes an intersection object and adds it to the graph. If there is no space in the
    // array, a FAIL will be returned in the form of an integer 3333.
    int insert_vertex(Intersection& intersection_add);

    // Takes two strings that are designed to be the names of intersections (see
    // intersection.h for more info on "names"). Using the names, an attempt is made to
    // find the indexes by comparing strings provided and names of present vertex
    // intersections. If indexes are found, edges are added to each of the matched
    // intersections. Otherwise, a FAIL is returned in the form of an integer 3333.
    int insert_edge(string current_vertex, string to_attach);

    // Displays all intersections in the graph. 
    int display_all();

    // Displays all adjacent intersections for a vertex specified by the the key provided
    // as an argument. If the key doesn't match any existing intersections in the graph
    // a FAIL is returned -> 3333.
    int display_adjacent(string key);

    // Determines if the key provided as an arument matches a name for any of the present
    // intersections in the graph. If there is a match, the corresponding index is
    // returned. Otherwise a FAIL is returned -> 3333
    int find_index(string key);

  private:
    vertex * adjacency_list;
    int list_size;
};

