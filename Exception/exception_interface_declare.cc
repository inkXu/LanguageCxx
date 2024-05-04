/*
 * author: inkXu
 * date:   2022.8.6
 *
 * 异常接口声明
 *
 * 给函数声明可以抛出哪些异常
 * vs测试不好使，qt可linux测试这个都行
 */
#include<iostream>
#include<string>
using namespace std;

//可以抛出所有类型异常
void TestException1();
//只能抛出int和char异常
void TestException2() throw(int, char, char *);
//不能抛出任何异常
void TestException3() throw();
void test1();

int main()
{
  try{
    test1();
  }
  catch(string){
    cout << "抛出了string类型的异常" << endl;
  }
  catch(...){
    cout << "抛出了其它类型的异常" << endl;
  }
  return 0;
}

void test1()
{
  //TestException1();
  TestException2();
  //TestException3();
}

void TestException1()
{
  string exception = "error";
  throw exception;
}
//抛出了指定类型以外的类型，程序能成功编译，但是运行时会崩溃
void TestException2() throw(int, char, char *)
{
  //崩溃
  //string exception = "error";
  //throw exception;

  //throw 1;
  //throw 'a';
  char a = 'a';
  char *pa = &a;
  throw pa;
}
void TestException3() throw()
{
  //string exception = "error";
  //throw exception;
  //throw 1;
  //throw 3.14;
  //throw 'a';
}





