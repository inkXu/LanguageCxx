/*
 * author: inkXu
 * date:   2022.8.6
 *
 * 重新解释转换
 *
 * reinterpret_cast，主要用于指针类型给的强制转换
 */
#include<iostream>
using namespace std;

void test1();

int main()
{
  test1();
  return 0;
}

void test1()
{
  int a = 100;
  double b = 3.14159;
  int *pa = &a;
  double *pb = &b;
  char *pc = reinterpret_cast<char *>(pa);
  int *pd = NULL;
  pd = reinterpret_cast<int *>(pb);
  cout << "pa = " << pa << endl;
  cout << "pc = " << &pc << endl;
  cout << "pb = " << pb << endl;
  cout << "pd = " << pd << endl;

  cout << "*pa = " << *pa << endl;
  cout << "*pb = " << *pb << endl;
  cout << "*pc = " << *pc << endl;
  cout << "*pd = " << *pd << endl;
}







