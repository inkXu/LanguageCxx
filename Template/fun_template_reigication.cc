/*
 * author: inkXu
 * date:   2022.8.5
 *
 * 模板具体化
 *
 * 特别不常用，格式:template<> 返回值类型 函数名<模板类型>(参数1,参数2....){}
 * 用不了，大概就下面这样写，会报一些奇怪的错误
 */
#include<iostream>
#include<string>
using namespace std;

class Person
{
  friend ostream& operator<<(ostream& out, Person &p);
public:
  Person(){ }
  Person(int age, string name): age(age), name(name){ }
  int age;
  string name;
};
ostream& operator<<(ostream& out, Person &p)
{
  out << p.age << "   " << p.name;
  return out;
}

#if 1
template <>
void myswap<Person>(const Person &p1, const Person &p2)
{
#if 1
  Person tmp;
  tmp.age = p1.age;
  tmp.name = p1.name;
  p1.age = p2.age;
  p1.name = p2.name;
  p2.age = tmp.age;
  p2.name = tmp.name;
#endif
  //因为类中默认有operator=操作，所以可以使用下面写法，若类中有指针类型，则不能这样写，因为默认的operator=
  //只是浅拷贝，若是重写了operator=，将之写成了深拷贝，那么可以这么写
  #if 0
    Person tmp = p1;
    p1 = p2;
    p2 = tmp;
  #endif
}
#endif

void test1();

int main()
{
  test1();
  return 0;
}

void test1()
{
  Person p1(23, "mike");
  Person p2(26, "sun");
  cout << p1 << endl;
  cout << p2 << endl;
  mySwap(p1, p2);
  cout << p1 << endl;
  cout << p2 << endl;
}







