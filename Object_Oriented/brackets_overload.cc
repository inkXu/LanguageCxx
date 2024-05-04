/*
 * author: inkXu
 * date:   2022.8.2
 *
 * 括号的重载，函数对象
 * 一个类中重载了()使得能直接调用函数对象
 */
#include<iostream>
#include<string.h>
using namespace std;

class My
{
public:
  int operator()(int x, int y)
  {
    return x + y;
  }
  int Add(int x, int y)
  {
    return x + y;
  }
};

void test1();

int main()
{
  test1();
  return 0;
}

void test1()
{
  My m;
  cout << "7 + 5 = " << m.Add(7, 5) << endl;

  My m1;
  cout << "12 + 5 = " << m1(12, 5) << endl;

  cout << "80 + 23 = " << My()(80, 23) << endl;   //My() 为匿名对象  My()(80, 23)匿名对象调用()操作
}







