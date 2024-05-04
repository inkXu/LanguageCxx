/*
 * author: inkXu
 * date:   2022.7.23
 *
 * 函数重载实验
 */
#include<iostream>
using namespace std;

//函数可以通过给函数形参赋默认参数作为条件写重载函数
//但是有极大的可能出现二义性
//使用引用的方法作为条件来重载函数会出现歧义

void fun(int &a);
void fun(int* &q);

int main()
{
  int a = 999;
  int *p = &a;
  int &b = a;
  fun(b);
  fun(p);
  return 0;
}

void fun(int &a)
{
  cout << "void fun(int &a) a = " << a <<endl;
}
void fun(int* &p)
{
  cout << "void fun(int * &p) a = " << *p <<endl;
}
