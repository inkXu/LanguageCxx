/*
 * author: inkXu
 * date:   2022.7.21
 *
 * using的使用
 *
 * 关于using引用时会出现的同名的标识符而导致二义性时，建议直接使用(命名空间::标识符)
 */

#include<iostream>
using namespace std;

namespace A
{
  float PI = 3.1415926;
  int a = 100;
  int c = 10;
}

void test1();      //using的好处
void test2();      //二义性
void test3();      //using编译指令使整个命名空间标识符可用

int main()
{
  //test1();
  //test2();
  test3();
  return 0;
}

void test3()
{
  int a = 999;
  //编译申明
  using namespace A;
  cout<< "PI = " << PI <<endl;
  cout<< "c = " << c <<endl;
  //编译申明时，和其他同名的局部标识符有冲突时，优先使用的是局部变量的值
  cout<< "a = " << a <<endl;
}
void test2()
{
  //注意:若是申明了标识符，和其他同名的标识符有作用域冲突时，会产生二义性，报错
  //float PI = 3.14;
  using A::PI;
  cout<< "PI = " << PI <<endl;
}
void test1()
{
  std::cout<< "welcome to china" <<endl;
  //有using的好处，不用加作用域std
  cout<< "welcome to china" <<endl;
}






