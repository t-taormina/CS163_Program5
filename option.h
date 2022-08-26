// Tyler Taormina 
// taormina@pdx.edu
// August 2022
// Program 5

// Option Class

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include <string>
#include <algorithm>
#include <tuple>
using namespace std;

const int FAIL = 3333;

class Intersection 
{

  public:
    // Default constructor to create an instance of an option with integers set to 0 and
    // character arrays set to nullptrs.
    Intersection();

    // Deconstructor that deletes character arrays and sets them to nullptrs, and sets all
    // integer values to 0.
    ~Intersection();
    
    // Parameterized constructor that can be used to create item instance with the passed
    // arguments used in the corresponding data fields.
    Intersection(string name, string street1, string street2);

     // Uses values passed as aruments to change the data members of the calling item.
    int set_intersection(string name, string street1, string street2);

    // Copy data from argument to calling instance.
    int copy(Intersection& copy_from);
    
    // Displays private data members to the console. 
    int display(void);

    int is_match(string to_match);
  // =====================================================================================
  private:
    string name;
    string street1;
    string street2;
};



