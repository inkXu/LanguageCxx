/*
 * author: inkXu
 * date:   2022.8.5
 *
 * 类模板的创建时机
 *
 * 函数的创建时机在调用该函数时
 */
#include<iostream>
using namespace std;

template <class T>
class Animal
{
public:
  Animal(T id): id(id){}
  void show();
  void view();
  T id;
};
void test1();

int main()
{
  test1();
  return 0;
}

void test1()
{
  Animal<string> animal("x10023");
  //类模板的函数在调用了该函数的时候才会报错，运行时会报错，所以函数的创建时机在调用该函数时
  //animal.show();
}







