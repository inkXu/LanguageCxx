/*
 * author: inkXu
 * date:   2022.7.22
 *
 * 引用
 *
 * 本质是指针常量(Type &ref = val;)<==>(Type * const ref = &val;)
 * 引用的用法：引用类型 &引用名 = 需要引用的变量
 * 本质就是对变量取个别名，让这个别名标识变量的地址
 * 引用类型引用时一定得初始化
 * 引用初始化后不能改变其引用
 */
#include<iostream>
using namespace std;

void test1();
void test2();    //数组的引用
void test3();    //常量引用，不能通过引用去修改引用空间的值

int main()
{
  test3();
  return 0;
}

void test3()
{
  //不能通过引用去修改引用空间的值，和指针常量一样
  int a = 100;
  const int &a_ref = a;
  //error!
  //a_ref = 66;
  cout<< "a = " << a <<endl;
  cout<< "a_ref = " << a_ref <<endl;

#if 0
  //直接对常量进行引用，error
  int &c = 100;
  cout<< "c = " << c <<endl;
#endif

  //加了const关键字可以引用常量，因为加了const关键字时，编译器
  //先开辟了个临时变量来存放888(int temp = 888;)，而后对temp进行引用
  const int &b = 888;
  cout<< "b = " << b <<endl;
  cout<< "&b = " << &b <<endl;
}
void test2()
{
  int a[3] = { 1,2,3 };
  //第一种方式
  int (&nums)[3] = a;
  //第二种方式
  //typedef int ARR[3];
  //ARR &nums = a;
  for(int i = 0; i < 3; i++)
  {
    cout<< "nums[" << i << "] = " << nums[i] <<endl;
  }
}
void test1()
{
  int a = 100;
  int &num_a = a;
  cout<< "a = " << a <<endl;
  cout<< "num_a = " << num_a <<endl;
  num_a = 666;
  cout<< "a = " << a <<endl;
  cout<< "num_a = " << num_a <<endl;
}


