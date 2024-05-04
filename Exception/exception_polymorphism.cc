/*
 * author: inkXu
 * date:   2022.8.7
 *
 * 异常与多态
 *
 * 若是和普通的那样抛出异常，那么就要写好多catch，将抛出的异常一一写出了，为了不这样，与多态一起使用，
 * 子类继承抽象类，重写抽象类中的虚函数，这样只需写一个catch，将父类的引用写到catch中即可
 */
#include<iostream>
#include<string.h>
using namespace std;

class Exception
{
public:
  //纯虚函数
  virtual void error() = 0;
};
//越界错误
class Out_of_range: public Exception
{
public:
  void error()
  {
    cout << "out of range error" << endl;
  }
};
//段错误
class Invaild_management: public Exception
{
public:
  void error()
  {
    cout << "invaild management error" << endl;
  }
};

void test1();
void fun();

int main()
{
  test1();
  return 0;
}

void fun()
{
  //throw Out_of_range();
  throw Invaild_management();
}
void test1()
{
  try{
    fun();
  }
  catch(Exception &e){
    e.error();
  }
}







