// Tyler Taormina 
// taormina@pdx.edu
// August 2022
// Program 5

// Option Class
// - This class stores 5 data fields that are meant to represent an item in a collection.
// The data fields are a name for an item, the type of the item (or what it is), the year
// the item was made, a description or condition of the item, and how much the item is
// worth. 

#include "option.h"


// Default constructor.
Intersection::Intersection() : name(""), street1(""), street2("") {}

// Deconstructor
Intersection::~Intersection()
{
  name = "";
  street1 = "";
  street2 = "";
}

// Parameterized constructor
Intersection::Intersection(string named, string street_1, string street_2)
{
  name  = named;
  street1 = street_1;
  street2 = street_2;
}

// @DEV
// Args -> character arrays: name, type, and description
//         integers: year and worth
// Returns -> 0 if the item we are trying to set is already holding valid values
//            1 if the function runs successfully
int Intersection::set_intersection(string named, string street_1, string street_2)
{
  name  = named;
  street1 = street_1;
  street2 = street_2;
  return 0;
}


// @DEV
// Args -> character arrays: name, type, and description
//         integers: year and worth
// Returns -> 0 if the item we are trying to set is already holding valid values
//            1 if the function runs successfully
int Intersection::copy(Intersection& copy_from)
{
  name = copy_from.name;
  street1 = copy_from.street1;
  street2 = copy_from.street2;
  return 0;
}


// @DEV
// Args -> character arrays: name, type, and description
//         integers: year and worth
// Returns -> 0 if the item we are trying to set is already holding valid values
//            1 if the function runs successfully
int Intersection::display()
{
  cout << "Name: " << name << endl;
  cout << "Cross street 1: " << street1 << endl;
  cout << "Cross street 2: " << street2 << endl;
  return 0;
}


// @DEV
// Args -> character arrays: name to compare with data members for a match.
// Returns -> 0 if there is no match
//            1 if there is a match
int Intersection::is_match(string to_match)
{
  // Default success indicates that the name is not a match. 
  int success = 0;
  // Success only changes if we find a match.
  if (to_match == name)
    success = 1;
  return success;
}


