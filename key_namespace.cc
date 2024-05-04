/*
 * author: inkXu
 * date:   2022.7.16
 *
 * 命名空间的定义
 * 
 * 命名空间的定义必须在全局范围
 * 命名空间可以存放 变量 函数 结构体 类
 * 命名空间可以重名，相当于合并操作
 * 命名空间可以嵌套命名空间
 * 未命名的命名空间相当于其内的变量加了static关键字，即仅能本文件访问
 * 命名空间内的函数可以直接申明，不定义，在外部定义时得加上作用域
 * 命名空间可以取别名(namespace newname = oldname)
 */
#include<iostream>
using namespace std;

namespace A
{
  //变量a本质是个全局变量
  int a = 100;
}
namespace B
{
  int a = 10;
  int b = 66;
}
//对命名空间B取个newB的别名
namespace newB = B;
namespace B
{
  int c = 88;
  namespace C
  {
    void fun()
    {
      cout<< "namespace C fun()" <<endl;
    }
    //定义个抽象方法
    void fun1(int year);
  }
}
//对抽象方法添加定义
void B::C::fun1(int year)
{
  cout<< "I love you " << year << " years" <<endl;
}

void test1();
void test2();
void test3();

int main()
{
  //test1();
  //test2();
  test3();
  return 0;
}

void test1()
{
  cout << A::a <<endl;
  cout << B::a <<endl;
  cout << B::b <<endl;
}
void test2()
{
  cout<< "B::a = " << B::a <<endl;
  cout<< "B::b = " << B::b <<endl;
  cout<< "B::c = " << B::c <<endl;
  B::C::fun();
}

void test3()
{
  B::C::fun1(100);
  newB::C::fun1(999);
}


