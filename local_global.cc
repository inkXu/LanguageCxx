#include<iostream>

//cout对象所在的命名空间
//namespace本质是作用域，可以更好的控制标识符的作用域
using namespace std;

//全局变量
int a = 100;

void test();

//main函数返回值一定得是int，C语言可以不写
int main()
{
  test();
  return 0;
}

void test()
{
  //局部变量
  int a = 10;
  //就近原则，输出局部变量
  cout<< "local variable a = " << a <<endl;
  //输出全局变量，'::'为作用域的意思，C语言不能这样
  cout<< "global variable a = " << ::a <<endl;
  //下面表示std命名空间中的cout，cout在std的作用域有效，若没有std，
  //那么cout可能在其它地方也有定义
  std::cout<< "welcome to china!" <<endl;
}




