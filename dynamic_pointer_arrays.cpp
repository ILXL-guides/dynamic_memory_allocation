#include <iostream>
#include "student.hpp"
using namespace std;

int main() {
  int** value_locations = new int*[10];
  student** cpsc121_locations = new student*[10];
  int i = 1;

  value_locations[0] = new int;
  *value_locations[0] = 5;

  *(value_locations + i) = new int;
  *(*(value_locations + i)) = 10;

  delete value_locations[0];
  delete value_locations[1];
  delete[] value_locations;

  cpsc121_locations[0] = new student;
  (*cpsc121_locations[0]).set_name("Julian");
  cpsc121_locations[0]->set_id(12345);
  cpsc121_locations[0]->display();

  *(cpsc121_locations + i) = new student;
  (*(*(cpsc121_locations + i))).set_name("Adriana");
  (*(cpsc121_locations + i))->set_id(6789);
  (*(cpsc121_locations + i))->display();

  delete cpsc121_locations[0];
  delete cpsc121_locations[1];
  delete[] cpsc121_locations;

  return 0;
}
