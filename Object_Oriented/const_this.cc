/*
 * author: inkXu
 * date:   2022.8.6
 *
 * const关键字在类的成员函数后作用
 */
#include<iostream>
#include<string>
using namespace std;

class Animal
{
public:
  string name;
  //将类的成员函数后加上const关键字，表示const Animal * const this = animal;不能对this指向的对象内容进行更改
  void set_name(string name);
  void show_name() const;
};
void Animal::set_name(string name)
{
  this->name = name;
}
void Animal::show_name() const
{
  //报错，函数后有const关键字，不能对this指向的内容进行修改
  //this->name = "xier";
  cout << "this->name = " << this->name << endl;
}

void test1();

int main()
{
  test1();
  return 0;
}

void test1()
{
  Animal animal;
  animal.set_name("mini");
  animal.show_name();
}
