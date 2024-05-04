/*
 * author: inkXu
 * date:   2022.7.23
 *
 * 引用作为形参
 */
#include<iostream>
#include<stdlib.h>
using namespace std;

void swap(int &a, int &b);
void test1();                        //普通变量使用引用当形参
void get_mem(int **q, int num);      //获取num个整型数据的数组
void get_mem_ref(int * &q, int num); //获取num个整型数据的数组
void test2();                        //指针使用引用当形参
int & ref();
void test3();                        //函数返回值为引用类型时

int main()
{
  test3();
  return 0;
}

void test3()
{
  cout<< "ref() = " << ref() <<endl;
  //相当于变量了
  ref() = 1000;
  cout<< "ref() = " << ref() <<endl;
}
int & ref()
{
  //函数结束申请的内存会释放掉（栈区），static关键字申请的内存不在（栈区）
  static int cc = 66;
  int &b = cc;
  //return cc;
  return b;
}
void get_mem(int **q, int num)
{
  *q = (int *)malloc(num * sizeof(int));
}
void get_mem_ref(int * &q, int num)
{
  q = (int *)malloc(num * sizeof(int));
}
void test2()
{
  int *p = NULL, *q = NULL;

  cout<< "&p = " << p <<endl;
  get_mem(&p, 5);
  cout<< "&p = " << p <<endl;

  cout<< "&q = " << q <<endl;
  get_mem_ref(q, 5);
  cout<< "&q = " << q <<endl;
}
//引用类型作为参数，可用指针作为参数完成
void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}
void test1()
{
  int x = 10, y = 66;
  cout<< "x = " << x <<endl;
  cout<< "y = " << y <<endl;
  //传入该函数相当于int &a = x;int &b = y;
  swap(x, y);
  cout<< "x = " << x <<endl;
  cout<< "y = " << y <<endl;
}
