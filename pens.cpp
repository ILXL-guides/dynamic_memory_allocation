#include <iostream>
#include "pens.hpp"
using namespace std;

int main() {
  // dynamically created array that contains pen pointers
  pen** assorted_pens = new pen*[3];

  // the array can contain pointers to pens or any of its derived classes due to
  // polymorphism
  assorted_pens[0] = new pen;
  assorted_pens[1] = new thick_pen;
  assorted_pens[2] = new marker;

  // all pens and its derived classes will have an implementation of the write()
  // function so they can all easily be called using a loop
  for (int i = 0; i < 3; i++) {
    assorted_pens[i]->write();
  }

  // all addresses of the objects stored in the array need to be deleted first
  for (int i = 0; i < 3; i++) {
    delete assorted_pens[i];
    assorted_pens = nullptr;
  }
  // after deleting each element then the array can be deleted
  delete[] assorted_pens;
  assorted_pens = nullptr;

  return 0;
}
