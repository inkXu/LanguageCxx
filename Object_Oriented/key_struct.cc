/*
 * author: inkXu
 * date:   2022.7.24
 *
 * struct的C与C++区别
 *
 * C中不能写函数，C++中可以
 * C中的面向对象编程使用struct意会一下，C因为不能在struct中写函数，所以
 * 对象的行为要另写函数，这个函数可能会被其它成员调用，这是个bug
 * strcpy在C++中显示不安全，要用strcpy_s，或加一个宏编译的啥警告
 */
#include<iostream>
#include<string.h>
using namespace std;

struct Person
{
  int age;
  char name[32];
  void show()
  {
    cout<< "name = " << name << ",age = " << age <<endl;
  }
};

int main()
{
  Person p1;
  p1.age = 21;
  strcpy(p1.name, "bob");
  p1.show();
  return 0;
}
