/*
 * author: inkXu
 * date:   2022.7.30
 *
 * 静态成员变量与方法
 *
 * 静态成员变量
 * 在程序编译阶段就分配了内存，存在静态全局区，全局能调用
 * 静态成员变量不能在类内初始化(赋值)，只能申明，该变量的存在是为了限制其作用域
 * 该变量只有一份，与其它对象共用
 *
 * 静态成员方法
 * 类似变量，静态成员方法只能调用静态成员变量，不能使用非静态成员方法(因其在编译阶段就分配内存)
 */
#include<iostream>
using namespace std;

class Person
{
public:
  int a;
  static int b;
  //和前面一样const，保存在文字常量区，不能更改，只读，所以需要直接赋值初始化
  const static int c = 666;
  static void show()
  {
    cout << "b = " << b << endl;
  }
};
//类中成员变量的定义，注意要加类型
int Person::b = 100;

void test1();         //使用方法
void test2();         //共用

void test3();

int main()
{
  test3();
  return 0;
}

void test3()
{
  //通过对象调用
  Person p;
  p.show();
  //通过作用域直接调用
  Person::show();
}
void test2()
{
  Person *p1 = new Person;
  cout << p1->b << endl;
  p1->b = 999;
  cout << p1->b << endl;
  Person *p2 = new Person;
  cout << p2->b << endl;
  delete p1;
  delete p2;
}
void test1()
{
  //创建一个对象，直接调用
  Person *p1 = new Person;
  cout << p1->b << endl;
  delete p1;
  //通过类的作用域直接访问
  cout << Person::b << endl;
}







