#include <iostream>
using namespace std;

class student {
private:
  string _name;
  int _id;
public:
  void set_name(string name) { _name = name; }
  void set_id(int id) { _id = id; }
  string name() { return _name; }
  int id() { return _id; }
  void display() {
    cout << "Name: " << _name << "\n" << "ID: " << _id << "\n";
  }
};
