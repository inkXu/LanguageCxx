/*
 * author: inkXu
 * date:   2022.8.7
 *
 * 继承异常类的基类编写自己的异常类
 * 
 * vs能用，linux不能，不知道为啥
 */
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdexcept>
#include<string>
using namespace std;

class Input_error: public exception
{
public:
  Input_error(string data)
  {
    this->data = data;
  }
#if 0
  //因为string类中重载了=，所以可以通过this->data = data;
  Input_error(char *data)
  {
    this->data = data;
  }
#endif
  //exception类中，what是虚函数，可进行重写，并不是纯虚函数
  const char *what() const
  {
    return data.c_str();
  }
  string data;
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
  throw Input_error("输入错误");
}
void test1()
{
  try{
    fun();
  }
  catch(exception &e){
    cout << e.what() << endl;
  }
}







