#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Signal {
private:
  string name;
  static Signal *signal;
  Signal() {}
  ~Signal() {
    free(signal);
  }
  Signal &operator=(Signal &s) {}
public:
  void setName(string name) {
    this->name = name;
  }
  string &getName() {
    return this->name;
  }
  static Signal *instance() {
    return signal;
  }
};
Signal *Signal::signal = new Signal;

int main(int argc, char *argv[])
{
  Signal *signal = Signal::instance();
  signal->setName("mike");
  cout << signal->getName() << endl;
  return 0;
}
