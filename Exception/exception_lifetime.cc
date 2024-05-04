/*
 * author: inkXu
 * date:   2022.8.6
 *
 * 异常的生命周期
 */
#include<iostream>
using namespace std;

class Exception
{
public:
  Exception(string data)
  {
    cout << "structure is used" << endl;
    this->data = data;
  }
  ~Exception()
  {
    cout << "Exception class destruct is used" << endl;
  }
  void error()
  {
    cout << this->data << " error" << endl;
  }
private:
  string data;
};

void test1();
void fun1();
void fun2();

int main()
{
  test1();
  return 0;
}

void fun2()
{
  cout << "This is the code block for the function fun2()" << endl;
  //使用显示法创建一个对象，这个对象会因为栈解旋的原因在throw关键字处释放掉，和隐式法比多出了几步
  Exception exception("invaild arrangement");
  throw exception;
}
void fun1()
{
  cout << "This is code block for the function fun1()" << endl;
  //使用隐式法创建一个Exception对象
  throw Exception("out of range");
}
void test1()
{
  try{
    cout << "This is the code block for the try" << endl;
    //fun1();
    fun2();
  }
  //catch这里不能写成(Exception e)，这样相当于又新建了一个对象
  catch(Exception &e){
    cout << "This is the code block for the catch" << endl;
    e.error();
  }
}







