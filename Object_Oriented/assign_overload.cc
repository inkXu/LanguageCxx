/*
 * author: inkXu
 * date:   2022.8.2
 *
 * 等号的重载
 *
 * 在一个类中，默认会写四个函数，分别为：无参构造、析构函数、拷贝函数、=重载(p1.operator=(Person p2))
 * 其中=的重载和拷贝类似，只是进行了浅拷贝，若是其内有指针类型，那么指针之间会指向同一地址，若重写了析构
 * 函数，其内释放了指针成员变量的地址，那么使用拷贝或是=操作得来了另一个对象，那么程序会崩溃
 */
#include<iostream>
#include<string.h>

class Person
{
public:
  Person()
  {
  }
  Person(char *name, int age)
  {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->age = age;
  }
  ~Person()
  {
    delete name;
  }
#if 1
  Person &operator=(Person &p)
  {
    this->name = new char[strlen(p.name) + 1];
    strcpy(this->name, p.name);
    this->age = p.age;
    //返回是为了使做完该操作还能继续进行其它操作
    return *this;
  }
#endif
  char *name;
  int age;
};

void test1();

int main()
{
  test1();
  return 0;
}

void test1()
{
  char name[5] = "mike";
  Person p1(name, 23);
  Person p2;
  Person p3;
  p3 = p2 = p1;
  std::cout << p2.name << "    " << p2.age << std::endl;
  std::cout << p3.name << "    " << p3.age << std::endl;
}







