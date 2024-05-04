/*
 * author: inkXu
 * date:   2022.8.6
 *
 * 常量转换
 *
 * const_cast，主要用来给指针变量、引用类型、自定义类型指针加const和删const
 * const_cast<const int *>(b) 返回值为一个const修饰的int类型，b还是原来的类型
 */
#include<iostream>
using namespace std;

void test1();
void test2();

int main()
{
  test2();
  return 0;
}

void test2()
{
  int a = 100;
  int b = 999;
  int *pa = &a;
  const int *pb = &b;

  cout << "*pa = " << *pa << endl;
  cout << "*pb = " << *pb << endl;
  cout << "pa = " << pa << endl;
  cout << "pb = " << pb << endl;
  pb = const_cast<const int *>(pa);
  cout << "*pa = " << *pa << endl;
  cout << "*pb = " << *pb << endl;
  cout << "pa = " << pa << endl;
  cout << "pb = " << pb << endl;
  //报错
  *pa = 999;
  //*pb = 888;
}
void test1()
{
  int a = 100;
  int b = 999;
  int *pa = &a;
  const int *pb = &b;

  cout << "*pa = " << *pa << endl;
  cout << "*pb = " << *pb << endl;
  cout << "pa = " << pa << endl;
  cout << "pb = " << pb << endl;
  pa = const_cast<int *>(pb);
  cout << "*pa = " << *pa << endl;
  cout << "*pb = " << *pb << endl;
  cout << "pa = " << pa << endl;
  cout << "pb = " << pb << endl;

  *pa = 999;
  //*pb = 888;
}







