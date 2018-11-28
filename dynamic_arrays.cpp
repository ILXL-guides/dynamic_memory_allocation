#include <iostream>
#include "student.hpp"
using namespace std;

int main() {
  int* values = new int[10];
  student* cpsc121 = new student[60];
  int i = 1;

  values[0] = 5;
  *(values + i) = 6;

  cpsc121[0].set_name("Julian");
  cpsc121[0].set_id(12345);
  cpsc121[0].display();

  (*(cpsc121+i)).set_name("Adrianna");
  (*(cpsc121+i)).set_id(5678);
  (*(cpsc121+i)).display();

  i = 2;

  (cpsc121+i)->set_name("Dimeji");
  (cpsc121+i)->set_id(91011);
  (cpsc121+i)->display();

  delete[] values;
  delete[] cpsc121;

  return 0;
}
