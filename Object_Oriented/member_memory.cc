/*
 * author: inkXu
 * date:   2022.7.31
 *
 * 成员变量的存储
 * static关键字修饰的变量在静态全局区，在类中只是声明一下它的作用域
 * 类中的成员方法都在代码区放着
 */
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
};
class Point
{
public:
  int x;
  int y;
  static string instruct;
  void show()
  {
    cout << x << "   " << y << endl;
  }
  static void show_static()
  {
    cout << "instruct " << instruct << endl;
  }
};

void test1();                   //Person类大小为1，不为0，因它至少要有一个地址的内存，这样指针才能指向它
void test2();

int main()
{
  test1();
  test2();
  return 0;
}

void test2()
{
  //8
  //static关键字修饰的变量在静态全局区，这里只是声明一下它的作用域
  //成员方法都在代码区放着
  cout << "sizeof(Point) = " << sizeof(Point) << endl;
}
void test1()
{
  //1
  cout << "sizeof(Person) = " << sizeof(Person) << endl;
}
