// Tyler Taormina 
// taormina@pdx.edu
// August 2022
// Program 5

#include "graph.h"

// ===============================================================================================
// CLIENT FUNCTIONALITY TO TEST THE ADT AND DATA STRUCTURE
// This Header file contains the prototypes for the code designed to test the Data structures and abstract data
// type. It consists of a run function for entry into the program and a menu interface
// that allows the user to test all methods implemented by the ADT. 

int run();
int displayMenu();
int validate_menu_choice();
void processChoice (int& flag, int menu_choice, class Graph& graph);
int get_input(string& input);
int make_intersection(Intersection& intersection);

