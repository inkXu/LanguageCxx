/*
 * author: inkXu
 * date:   2022.7.22
 *
 * 函数的默认参数
 *
 * 函数设置默认参数时，若有默认参数设置默认值，那么从这个参数开始，
 * 后面的每一个参数都得设置默认值
 * 函数的声明和定义处只能有一处设置默认参数，自己试的得写在声明处
 */
#include<iostream>
using namespace std;

void test1(int a = 1, int b = 3);
void test2(int a, int b = 333);

int main()
{
  test1();
  test1(5);
  test1(5, 8);
  cout<< "************************" <<endl;
  test2(222);
  test2(22, 33);
  return 0;
}
void test2(int a, int b)
{
  cout<< "a = " << a << "  b = " << b <<endl;
}
void test1(int a, int b)
{
  cout<< "a = " << a << "  b = " << b <<endl;
}




