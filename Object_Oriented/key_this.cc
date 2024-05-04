/*
 * author: inkXu
 * date:   2022.7.31
 *
 * this关键字
 *
 * 编译器默认会在类的方法中添加一个this指针，该指针是隐藏的，它指向的是调用该方法的实例化对象(类名 const * this)
 * 表示样式是Person const * this = &p;所以在其方法内可以使用this关键字来调用其成员
 */
#include<iostream>
#include<string>
using namespace std;

class Person
{
public: 
  string name;
  int age;
  Person(int age, string name)
  {
    this->age = age;
    this->name = name;
  }
  void show()
  {
    this->name = "liu";
    cout << "my name is " << name << " and my age is " << age << endl;
  }
  //相当于const Person const * this，为常量指针常量，第一个表示不能修改对象中的数据，第二个表示不能修改this的指向
  void no_change_show()const
  {
    //这里是错的，会报错，因为方法后加了const
    //this->name = "xiao";
    cout << "my name is " << name << " and my age is " << age << endl;
  }
};

void test1();
void test2();
void test3();        //使用常量指针常量使得在方法中不能修改对象中的值

int main()
{
  test3();
  return 0;
}

void test3()
{
  Person *p = new Person(34, "sun");
  p->no_change_show();
}
void test2()
{
  Person p(34, "xiu");
  cout << "change before" << endl;
  cout << "p.name = " << p.name << " p.age = " << p.age << endl;
  //通过this指针修改了对象中成员变量的值
  cout << "change after" << endl;
  p.show();
}
void test1()
{
  Person p(23, "mike");
  cout << &p << endl;
}
