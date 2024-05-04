/*
 * author: inkXu
 * date:   2022.8.6
 *
 * C++异常
 */
#include<iostream>
using namespace std;

void test1();         //C++异常的基本语法
int divide(int x, int y);

int main()
{
  try{
    test1();
  }
  catch(int){
    cout << "捕获到一个int类型的异常" << endl;
  }
  //抛出的异常的类型是严格匹配的，若是上一级内抛出了int类型的异常，那么一定要写捕获int类型的异常或是其它异常(...)，
  //若都没有写那么程序会崩溃
  catch(char){
    cout << "捕获到一个char类型的异常" << endl;
  }
  //...表示其它类型的异常
  catch(...){
    cout << "其它类型的异常" << endl;
  }
  return 0;
}

void test1()
{
  try{
    cout << divide(4, 2) << endl;
    //测试的是捕获到异常后下面的代码就不再继续执行
    cout << divide(8, 0) << endl;
    cout << divide(6, 2) << endl;
    cout << divide(9, 0) << endl;
  }
  catch(int){
    //异常可以逐层抛出，若是在该层不想处理，可以再用throw抛出一个类型的异常，在下一层中的try catch中进行处理
    throw 1.1;
  }
}
//在C语言中，该函数报错时只能返回int类型的值，但也有可能正确的结果也是该值，那么在下一级进行该函数是否正常运行时，
//将不能正确判断
int divide(int x, int y)
{
  if(y == 0)
    throw 1;
  return x / y;
}






