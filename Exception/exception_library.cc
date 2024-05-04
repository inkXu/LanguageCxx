/*
 * author: inkXu
 * date:   2022.8.7
 *
 * C++自带异常库
 *
 * 头文件stdexcept
 * exception 所有标准异常类的父类
 * bad_alloc 当operator new and operator new[]请求分配内存失败时
 * bad_typeid  使用typeid操作符，操作一个NULL指针，而该指针是带有虚函数的类，这时抛出该异常
 * bad_cast  使用dynamic_cast转换引用失败时的时候
 * ios_base::failure  io操作过程出现的错误
 * logic_error  逻辑错误，可以在运行前检测的错误
 * runtime_error  运行时错误，仅在运行时才可以检测的错误
 * ...
 */
#include<iostream>
#include<stdexcept>
using namespace std;

void test1();
void fun();

int main()
{
  test1();
  return 0;
}

void fun()
{
  throw out_of_range("越界错误");
  //throw invalid_argument("段错误");
}
void test1()
{
  try{
    fun();
  }
  catch(exception &e){
    //C++异常库中，返回值为错误信息
    cout << e.what() << endl;
  }
}







