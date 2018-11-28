#include <iostream>
#include "student.hpp"
using namespace std;

int main() {
  // dynamic array of int pointers
  int** value_locations = new int*[10];
  // dynamic array of student pointers
  student** cpsc121_locations = new student*[10];
  int i = 1;

  // dynamic creation of int stored as an element of the array that is necessary
  // before assigning or retrieving values
  value_locations[0] = new int;
  *value_locations[0] = 5;

  // pointer arithmetic version of dynamically creating an int and assigning
  // values
  *(value_locations + i) = new int;
  *(*(value_locations + i)) = 10;

  // Each element is an address that needs to be deleted. We only delete 2
  // because we only allocated 2 ints
  delete value_locations[0];
  delete value_locations[1];
  // The array should be deleted only after its individual elements are deleted
  delete[] value_locations;

  // dynamic creation of a student stored as an element of the array that is
  // necessary before calling its methods
  cpsc121_locations[0] = new student;
  // The following are variations for accessing the student object's methods

  // pointer arithmetic and bracket notations
  (*cpsc121_locations[0]).set_name("Julian");
  // bracket notations and arrow notation
  cpsc121_locations[0]->set_id(12345);
  cpsc121_locations[0]->display();

  // using pointer arithmetic to store the dynamically created object
  *(cpsc121_locations + i) = new student;
  // using pointer arithmetic and the dot notation to access the student
  // object's methods
  (*(*(cpsc121_locations + i))).set_name("Adriana");
  // using pointer arithmetic and the arrow notation to access the student
  // object's methods
  (*(cpsc121_locations + i))->set_id(6789);
  (*(cpsc121_locations + i))->display();


  cpsc121_locations[i] = new student;
  (*cpsc121_locations[i]).set_name("Julian"); // bracket notation and dereferencing to call method
  cpsc121_locations[i]->set_id(12345); // bracket notation and arrow notation to call method
  (*(*(cpsc121_locations+i))).display(); // pointer arithmetic and dereferencing to call method
  (*(cpsc121_locations+i))->display(); // pointer arithmetic and arrow notation to call method

  // Each element is an address that needs to be deleted. We only delete 2
  // because we only allocated 2 student objects
  delete cpsc121_locations[0];
  delete cpsc121_locations[1];
  // The array should be deleted only after its individual elements are deleted
  delete[] cpsc121_locations;

  return 0;
}
