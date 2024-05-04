/*
 * author: inkXu
 * date:   2022.8.5
 *
 * 类模板成员函数的类内和类外实现
 *
 * 总结，不建议在类外实现，在类外实现一定要写成函数模板
 */
#include<iostream>
using namespace std;

template <class T1, class T2>
class Dog
{
public:
  Dog(T1 name, T2 age): name(name), age(age){}
  void show()
  {
    cout << "in class: name = " << name << ", age = " << age << endl;
  }
  T1 name;
  T2 age;
};
template <class T1, class T2>
class Cat
{
public:
  //这里可以不用写成模板的样子
  //Cat<T1, T2>(T1 name, T2 age);
  Cat(T1 name, T2 age);
  //void set(T1 name, T2 age);
  void show();
  T1 name;
  T2 age;
};
//类的成员方法在类外实现，需要注意，作用域得加上模板的类型，模板类的类外实现只能写成模板函数
template <class T1, class T2>
Cat<T1, T2>::Cat(T1 name, T2 age)
{
  this->name = name;
  this->age = age;
}
template <class T1, class T2>
void Cat<T1, T2>::show()
{
  cout << "out of class: name = " << this->name << ", age = " << this->age << endl;
}

void test1();

int main()
{
  test1();
  return 0;
}

void test1()
{
  Dog<string, int> dog("bob", 18);
  dog.show();
  Cat<string, int> cat("kiti", 12);
  cat.show();
}







