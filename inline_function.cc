/*
 * author: inkXu
 * date:   2022.7.22
 *
 * 内联函数
 *
 * 内联函数的定义
 *    在函数前加上inline即可，注意，inline要写在定义的函数上才有用，即，
 *    有花括号的地方，如果只写在申明的地方则还是普通函数
 * 内联函数的一些限制
 *    函数内不能存在任何形式的循环语句
 *    不能存在太多的条件判断语句
 *    函数体不能过于庞大
 *    不能对函数进行取地址操作
 * 预处理宏在C和C++中会出现一些难察觉的错误，如下面程序
 * 对于C++而言，预处理器不允许访问类的成员
 * 内联函数解决了上面的问题，也继承了宏的高效
 * 宏函数和内联函数
 *    宏函数的替换是在预处理阶段
 *    联函数的替换是在编译阶段
 *    宏函数和内联函数都省去了调用函数的开销(压栈、跳转、返回)以空间换时间
 * 类里面的函数默认都是内联函数，不需要再加inline关键字
 */
#include<iostream>
using namespace std;

void test1();        //宏定义的bug
void test2();        //内联函数解决宏定义的bug

int main()
{
  test1();
  cout<< "*****************************" <<endl;
  test2();
  return 0;
}
inline int myadd(int a, int b)
{
  return a + b;
}
inline int judge(int a, int b)
{
  return a < b ? a : b;
}
void test2()
{
  int a = 10, b = 100;
  //对应宏定义的bug 1
  int c = myadd(a, b) * 5;
  cout<< "myadd(a, b) * 5 = " << c <<endl;
  //对应宏定义的bug 2
  c = judge(++a, b);
  cout<< "judge(++a, b) = " << c <<endl;
}
#define MYADD(a, b) a+b
#define JUDGE(a, b) a < b ? a : b
void test1()
{
  int a = 10, b = 100;
  cout<< "a = " << a << "  b = " << b <<endl;
  cout<< "*****************************" <<endl;
  int c =  MYADD(a, b);
  cout<< "MYADD(a, b) = " << c <<endl;
  //bug 1，需要进行定义时对a+b加上括号
  c =  MYADD(a, b) * 5;
  cout<< "MYADD(a, b) * 5 = " << c <<endl;

  //bug 2，宏定义时不管怎么修改都没用，会出错，达不到预期值
  c = JUDGE(++a, b);
  cout<< "JUDGE(++a, b) = " << c <<endl;
}




