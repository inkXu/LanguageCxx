/*
 * author: inkXu
 * date:   2022.7.24
 *
 * 类中的对象具有权限(private、protected、public),结构没有权限
 * 类中定义的变量默认为private私有的，结构体为公有的
 * public 在类的里面和外部都能访问
 * protected 在类的里面能访问，子类能访问
 * private 只能在该类的里面能访问，子类不能访问
 */
#include<iostream>
#include<string.h>
using namespace std;

class Person
{
  public:
    int age;
    char name[32];
  private:
    int money;
  public:
    void show()
    {
      cout<< "my name is " << name << ", age is " << age\
          << ", money = " << money <<endl;
    }
};

void test1();

int main()
{
  test1();
  return 0;
}

void test1()
{
  Person p1;
  p1.age = 32;
  strcpy(p1.name, "bob");
  //出现私有变量的错误
  //p1.money = 100;
  p1.show();
}
