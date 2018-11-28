#include <iostream>
#include "student.hpp"
using namespace std;

int main() {
  int* values = new int[10]; // dynamic array of int
  student* cpsc121 = new student[60]; // dynamic array of student
  int i = 1;

  values[0] = 5; // assigning values using bracket notation
  *(values + i) = 6; // assigning values using pointer arithmetic

  // calling object member functions using bracket notation
  cpsc121[0].set_name("Julian");
  cpsc121[0].set_id(12345);
  cpsc121[0].display();

  // calling object member functions using pointer arithmetic
  (*(cpsc121+i)).set_name("Adrianna");
  (*(cpsc121+i)).set_id(5678);
  (*(cpsc121+i)).display();

  i = 2;
  // calling object member functions using pointer arithmetic and the arrow
  // notation
  (cpsc121+i)->set_name("Dimeji");
  (cpsc121+i)->set_id(91011);
  (cpsc121+i)->display();

  // deallocating the array
  delete[] values;
  delete[] cpsc121;
  values = nullptr;
  cpsc121 = nullptr;

  return 0;
}
