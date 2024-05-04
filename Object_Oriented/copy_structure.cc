/*
 * author: inkXu
 * date:   2022.7.24
 *
 * 拷贝构造的使用
 *
 * 旧对象初始化新对象时，test1()
 * 函数的形参为一个对象时，test2()
 * 函数的返回值为一个对象时，test3()
 */
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
  int age;
  Person()
  {
    cout<< "no parameter structure" <<endl;
  }
  Person(int a)
  {
    age = a;
    cout<< "have parameter structure" <<endl;
  }
  Person(const Person &person)
  {
    cout<< "copy structure" <<endl;
  }
  ~Person()
  {
    cout<< "destruct" <<endl;
  }
};

void test1();
void test2();
void creaPerson(Person p);
void test3();
//Person & retuPerson();
Person retuPerson();

int main()
{
  test3();
  return 0;
}

void test3()
{
  //不知到是不是优化了，这么p的地址还是局部变量的地址，没有调用拷贝构造
  //vs会调用拷贝函数，我的g++不会，qt(写C的软件)也不调用
  Person p = retuPerson();
  cout<< "&p = " << &p <<endl;
  cout<< "p.age = " << p.age <<endl;
}
#if 1
Person retuPerson()
{
  Person p(3);
  cout<< "&p = " << &p <<endl;
  return p;
}
#endif
#if 0
Person & retuPerson()
{
  //还是函数内开辟空间问题，没有static会直接释放内存
  //static Person p(3);
  Person p(3);
  Person &pp = p;
  return pp;
}
#endif
void test2()
{
  Person p(4);
  creaPerson(p);
}
void creaPerson(Person p)
{
}
void test1()
{
  Person p(4);
  Person p1(p);
  Person p2 = p;
  Person p3 = Person(p);
}
