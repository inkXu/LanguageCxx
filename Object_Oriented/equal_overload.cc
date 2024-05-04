/*
 * author: inkXu
 * date:   2022.8.2
 *
 * ==和!=号的重载
 */
#include<iostream>
#include<string>
using namespace std;

class Book
{
public:
  Book(string id, string name)
  {
    this->id = id;
    this->name = name;
  }
  bool operator==(Book &b)
  {
    return this->id == b.id && this->name == b.name;
  }
  bool operator!=(Book &b)
  {
    return !(this->id == b.id && this->name == b.name);
    //return this->id != b.id || this->name != b.name);
  }
  string id;
  string name;
};

void test1();

int main()
{
  test1();
  return 0;
}

void test1()
{
  Book b1("x1002", "mike");
  Book b2("x1009", "mike");
  if(b1 == b2)
    cout << "b1 == b2" << endl;
  else
    cout << "b1 != b2" << endl;
  if(b1 != b2)
    cout << "b1 != b2" << endl;
  else
    cout << "b1 == b2" << endl;
}







