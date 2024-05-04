/*
 * author: inkXu
 * date:   2022.8.4
 *
 * 纯虚函数和抽象类
 *
 * 一个类中若是存在纯虚函数，那么该类为抽象类
 * 抽象类不能实例化对象，继承了抽象类的子类，若没有重写虚函数，那么该类也为抽象类
 * 纯虚函数写法为虚函数等于0，这样的意义是指让虚函数指针指向NULL，虚函数表值置为NULL
 * 纯虚函数的应用，将写有纯虚函数的类看作接口，该类只有函数的声明，没有数据的定义，接口只是功能声明
 * 除了析构函数外都是纯虚函数，析构函数也能写成纯虚析构函数
 */
#include<iostream>
using namespace std;

class Animal
{
public:
  //纯虚函数，没有
  virtual void show(int a, int b) = 0;
};
class Dog: public Animal
{
public:
  void show(int a, int b)
  {
    cout << "a = " << a << ", b = " << b << endl;
  }
};

void test1();

int main()
{
  test1();
  return 0;
}

void test1()
{
  //报错，为抽象函数
  //Animal animal;
  Dog dog;
  dog.show(3, 5);
}







