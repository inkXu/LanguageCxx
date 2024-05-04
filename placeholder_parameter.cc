/*
 * author: inkXu
 * date:   2022.7.23
 *
 * 占位参数
 *
 * 只有符号重载(++)会用到，还没学
 */
#include<iostream>
using namespace std;

//int为占位参数，实际函数内没有使用，这两个参数都要传
void test1(int a, int);
//test2内的占位参数设置了默认值，使用该函数时不用传第二个参数
void test2(int a, int = 1);

int main()
{
  test1(6, 9);
  test2(6);
  return 0;
}

void test1(int a, int)
{
  cout<< "a = " << a <<endl;
}
void test2(int a, int)
{
  cout<< "a = " << a <<endl;
}
