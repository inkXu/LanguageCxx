/*
 * author: inkXu
 * date:   2022.7.22
 *
 * C++中的const关键字
 *
 * 1、const修饰的全局变量和C相比，C++中为默认为内部连接属性，在其他文件中不能访问，
 *   若一定要进行访问，那需要被访问的const常量需要加上extern关键字
 * 2、const修饰的局部变量，在C++中不能使用地址修改其数值，因为C++中使用const定义的局部变量
 *   是存放在符号表中，是一个常量，不能修改，对其取地址时会临时在栈区开辟个空间存放其值，
 *   取得的地址是这个临时变量的地址，所以修改值时并不是const定义的变量的值(赋值为常量时)，
 * 3、若const修饰的变量赋值的为一个变量，那么对其取地址可以修改其值
 * 4、const修饰的自定义变量时，保存在栈区，可以使用指针进行值的修改
 */
#include<iostream>
#include<string.h>
using namespace std;

void test1();        //C++相对于C的局部变量的不同
void test2();        //C++中对const变量赋值为变量时
void test3();        //const修饰自定义变量

int main()
{
  test3();
  return 0;
}

void test1()
{
  const int a = 100;
  int *p = NULL;
  //强制转换的原因是因为a为const类型，而*p为int类型
  p = (int *)&a;
  //int tmp = a;*p = &tmp;
  *p = 1;
  cout<< "*p = " << *p <<endl;
  cout<< "a = " << a <<endl;
}
void test2()
{
  int a = 100;
  const int b = a;
  int *p = (int *)&b;
  *p = 666;
  cout<< "*p = " << *p <<endl;
  cout<< "a = " << a <<endl;
  cout<< "b = " << b <<endl;
}
void test3()
{
  struct stu
  {
    int a;
    char name[32];
  };
  const stu liu = {1, "yes"};
  cout<< "liu.a = " << liu.a <<endl;
  cout<< "liu.name = " << liu.name <<endl;
  stu *p = (stu *)&liu;
  p->a = 20;
  strcpy(p->name,"none");
  cout<< "liu.a = " << liu.a <<endl;
  cout<< "liu.name = " << liu.name <<endl;
  cout<< "p->a = " << p->a <<endl;
  cout<< "p->name = " << p->name <<endl;
}





