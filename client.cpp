// Tyler Taormina 
// taormina@pdx.edu
// August 2022
// Program 5

#include "client.h"


// Program runner.
int run() {
  Graph graph = Graph(3);

  int flag = 1;
  
  while(flag > 0)
    {
      displayMenu();
      int menu_choice = validate_menu_choice();
      processChoice(flag, menu_choice, graph);
    }
  return 0;
}

// Displays the menu of functions for the user to choose from.
// Returns-> the integer value for the menu choice 
int displayMenu() {
    std::cout << "==================================================================\n";
    std::cout << "                         MENU" << std::endl;
    std::cout << "==================================================================\n";

    std::cout << "===============================\n";
    std::cout << "1) Display all\n"; //working
    std::cout << "2) Insert Vertex\n"; //working
    std::cout << "3) Insert edge\n";//working
    std::cout << "4) Display adjacent\n";//working
    std::cout << std::endl;
    std::cout << "0) Exit Program\n";
    std::cout << "Enter: ";
    return 0;
}


// Provides option processing for the menu 
void processChoice (int& flag, int menu_choice, Graph& graph)
{
  // Takes in user input for menu choice and calls the appropriate function.
  int no = 0;
  int proceed = 1;
  switch(menu_choice)
    {
      case 0:
        {
          cout << "Are you sure you want to exit?" << endl;
          proceed = no;
          break;
        }

      // Display full graph 
      case 1: 
        {
          int count = graph.display_all();
          cout << "Number of items: " << count << endl;
          break;
        }

      // Insert Vertex
      case 2:
        {
          Intersection add;
          make_intersection(add);
          int index = graph.insert_vertex(add);
          cout << "Vertex added at index: " << index << endl;
          break;         
        }

      // Insert edge
      case 3: 
        {
          string input1;
          string input2;
          cout << "Enter the name of the landmark the you would like to add to: ";
          get_input(input1);
          cout << "Enter the name of the landmark the you would like to attach to your previous entry: ";
          get_input(input2);
          int index = graph.insert_edge(input1, input2);
          cout << "Edge added at index: " << index << endl;
          break;
        }

      // Display adjacent
      case 4: 
        {
          string input;
          cout << "Enter the name of the vertex to display edges for: ";
          get_input(input);
          int index = graph.display_adjacent(input);
          break;
        }


      // Provide a backstop for out of bounds menu choices.
      default:
          break;
    }

    if (proceed == no)
    {
      std::cout << "Enter 0 to end program.\n" << std::endl;
      std::cout << "Enter any other number to continue program.\n" << std::endl;
      std::cin >> flag;
      std::cin.ignore(100, '\n');
    }
}


// Returns-> Integer value for the menu choice
int validate_menu_choice()
{
  int menu_choice_int = 0;
  cin >> menu_choice_int;
  std::cin.ignore(100, '\n');
 
  while (menu_choice_int > 4 || menu_choice_int < 0) {
    cout << "Please select a valid menu item." << endl;
    cin >> menu_choice_int;
    std::cin.ignore(100, '\n');
  }
  return menu_choice_int;
}


// Create an item using user input.
int make_intersection(Intersection& intersection)
{
  cout << "Please enter a landmark for the name of the intersection: ";
  string name;
  get_input(name);
  cout << "Please enter crosstreet 1: ";
  string street1;
  get_input(street1);
  cout << "Please enter crosstreet 2: ";
  string street2;
  get_input(street2);
 
  intersection.set_intersection(name, street1, street2);
  return 1;
}


// Gets user input from console and stores in character array.
int get_input(string& input)
{
  getline(cin, input);
  return 1;
}

