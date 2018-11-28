#include <iostream>
using namespace std;

class pen {
public:
  virtual void write() {
    cout << "      Pen: __________\n";
  }
};

class thick_pen : public pen {
public:
  virtual void write() {
    cout << "Thick pen: ==========\n";
  }
};

class marker : public pen {
public:
  virtual void write() {
    cout << "   Marker: ██████████\n";
  }
};
