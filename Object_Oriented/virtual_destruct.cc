/*
 * author: inkXu
 * date:   2022.8.4
 *
 * 纯虚析构函数
 *
 * 在使用父类指针指向一个子类对象时，对该指针进行delete操作时，只会调用父类的析构函数，子类的析构函数未被调用
 * 若想使得子类中析构函数也被调用，父类的析构函数要写成虚析构函数
 * 不知道为啥我在子类中重写不了纯虚析构，未重写时实例化子类对象报的是析构函数未定义的错误，而不是抽象类问题
 */
#include<iostream>
using namespace std;

class Animal
{
public:
  ~Animal()
  {
    cout << "Animal destruct is used" << endl;
  }
};
//哺乳动物
class Mammal
{
public:
  //使用了虚析构函数，子类会调用自身的析构和所有继承的父类的析构函数
  virtual ~Mammal()
  {
    cout << "Mammal destruct is used" << endl;
  }
};
class Dog: public Animal, public Mammal
{
public:
  ~Dog()
  {
    cout << "Dog destruct is used" << endl;
  }
};

//抽象类
class Abstract
{
public:
  //virtual ~Abstract() = 0;
  virtual void show() = 0;
};
class B: public Abstract
{
public:
  void show()
  {
    cout << "rewrite void show()" << endl;
  }
#if 0
  virtual ~Abstract()
  {
    cout << "rewirte ~Abstract" << endl;
  }
#endif
};

void test1();
void test2();
void test3();          //纯虚析构函数

int main()
{
  //只调用了Animal的析构函数
  //test1();
  //调用了Animal、Mammal、Dog的析构
  //test2();
  test3();
  return 0;
}

void test3()
{
  B b;
  b.show();
}
void test2()
{
  Mammal *mammal = new Dog;
  delete mammal;
}
void test1()
{
  Animal *animal = new Dog;
  delete animal;
}







