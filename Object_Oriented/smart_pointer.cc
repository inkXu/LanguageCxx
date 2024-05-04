/*
 * author: inkXu
 * date:   2022.8.2
 *
 * 智能指针 重载* 和 重载-> 运算符
 *
 * 因为总可能忘记释放new出来的空间，所以出现了智能指针
 * 个人认为，本质上是将一个对象当指针来使用
 * 这个局部对象的析构函数中会帮忙释放掉new出来的对象地址
 * 该指针重载了*和->使得这个对象能够像普通指针一样使用
 */
#include<iostream>
#include<string.h>
using namespace std;

class Person
{
public:
  Person(char *name, int age)
  {
    this->age = age;
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
  }
  char *name;
  int age;
};
class Smartpoint
{
public:
  Smartpoint(Person *p)
  {
    this->p = p;
  }
  ~Smartpoint()
  {
    delete p;
  }
  Person *operator->()
  {
    return p;
  }
  Person &operator*()
  {
    return *p;
  }
  Person *p;
};

void test1();           //正常情况下使用
void test2();           //使得Smartpoint和普通指针无异时，重载*和->
void test3();           //最常用的用法

int main()
{
  test3();
  return 0;
}

void test3()
{
  char name[5] = "mike";
  Smartpoint sp(new Person(name, 32));
  cout << sp->name << "   " << sp->age << endl;
  cout << (*sp).name << "   " << (*sp).age << endl;
}
void test2()
{
  char name[5] = "mike";
  Person *p = new Person(name, 32);
  //这里使用new来新建一个对象时，下面这句话表示是一个指针，运算符需要使用对象来调用，不推荐这样，更麻烦了
  //Smartpoint *sp = new Smartpoint(p);
  //cout << (*sp)->name << "    " << (*sp)->age << endl;
  //cout << (*(*sp)).name << "    " << (*(*sp)).age << endl;

  //下面这样定义实际上是将一个对象当指针来使用
  Smartpoint sp(p);
  cout << (*sp).name << "    " << (*sp).age << endl;
  cout << sp->name << "    " << sp->age << endl;
}
void test1()
{
#if 0
  char name[5] = "mike";
  Person p(name, 32);
  Smartpoint *sp = new Smartpoint(p);
  cout << sp->p->name << "  " << sp->p->age << endl;
#endif
}









