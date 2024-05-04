/*
 * author: inkXu
 * date:   2022.7.22
 *
 * 全局变量的检测增强
 * 类型转换增强(C中警告的强制转化，C++报错)
 * 对结构体使用的增强，定义变量时可以不加struct，可直接使用结构体名
 * 新增bool类型关键字
 *    (bool flag = true;)true(1) 和 false(0)，在C中使用bool类型得加头文件stdbool.h，C++中不用
 * 三目运算符功能增强
 * 老师使用vs编译报错，我的linux下会报错，下面的特点基本中C和C++一样的
 */

#include<stdio.h>
#include<iostream>
using namespace std;

//注意定义的是全局变量
//C语言中可以这样写，表示一个定义，两个是声明，检测没有那么严格
//int a;   //若有赋值操作，则这个a为定义，若a都没有赋值，声明和定义是随机的
//int a;
//int a;
#if 0
  //C语言中形参类型不写默认为int类型，编译不报错
  void fun(int x, int y)
  {
    //无返回值的函数有返回值编译不报错
    return 1;
  }
#endif

//C++中写成上面这种形式编译会报错，得写声明的关键字extern
int a;
extern int a;
extern int a;

//void test1(); 
void test2();   //三目运算符的增强

int main()
{
  //cout<< "yes" <<endl;
  test2();
  return 0;
}
void test2()
{
  int a = 100;
  int b = 30;
  //下面使用的三目运算符，在C++中返回的是变量a，而在C语言中，返回的是常量100
  (a > b ? a : b) = 1;
  printf("a = %d\n", a);
  printf("b = %d\n", b);
  //printf("a > b ? a : b == %d\n", b);
}
#if 0
void test1()
{
  fun(1);
  fun(1, 2);
  fun(1, 2, 3);
}
#endif
