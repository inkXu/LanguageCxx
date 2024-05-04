/*
 * author: inkXu
 * date:   2022.8.2
 *
 * 继承
 *
 * 继承可以使代码冗余度降低
 * 被继承的类称作父类或基类，继承了其它类的类称作子类或派生类
 * 派生类继承基类的写法：class 派生类:访问权限 基类(class A: protected B{})
 * 当创建子类对象时，必须先构造父类对象，所以要调用父类的构造，若是父类只有有参构造函数，那么
 * 子类的构造方法要使用初始化列表的方式
 */
#include<iostream>
using namespace std;

class Base
{
public:
  Base()
  {
  }
  Base(int a, int b, int c)
  {
    cout << "Base's structure is used" << endl;
    this->a = a;
    this->b = b;
    this->c = c;
  }
  ~Base()
  {
    cout << "Base's destruct is used" << endl;
  }
  int a;
protected:
  int b;
private:
  int c;
};
class Subclass1: public Base
{
public:
  int d;
  void show()
  {
    //成员函数访问不了父类的成员变量c，因为它是私有的
    cout << "a = " << a << "b = " << b << "d = " << d << endl;
  }
};
class Subclass2: protected Base
{
public:
  int d;
  void show()
  {
    //成员函数访问不了父类的成员变量c，因为它是私有的
    cout << "a = " << a << "b = " << b << "d = " << d << endl;
  }
};
class Subclass3: private Base
{
public:
  int d;
  void show()
  {
    //成员函数访问基类的成员变量主要看基类的访问权限，除了私有其它都能访问
    //成员函数访问不了父类的成员变量c，因为它是私有的
    cout << "a = " << a << "  b = " << b << "  d = " << d << endl;
  }
};
class Subclass4: public Base
{
public:
  int d;
  //使用初始化列表调用父类的有参构造完成初始化
  Subclass4(int a, int b, int c, int d):Base(a, b, c)
  {
    cout << "Subclass4's structure is used" << endl;
    this->d = d;
  }
#if 0
  Subclass4(int a, int b, int c, int d):Base(a, b, c), d(d)
  {
  }
#endif
  ~Subclass4()
  {
    cout << "Subclass4's destruct is used" << endl;
  }
  void show()
  {
    cout << "a = " << a << "  b = " << b << "  d = " << d << endl;
  }
};

void test1();       //访问权限的区别
void test2();       //当继承了仅有有参构造函数的父类时，子类的构造函数需要使用初始化列表的方法
void test3();       //继承后的子类和父类的关系

int main()
{
  test3();
  return 0;
}

void test3()
{
  cout << "Base have one less integer variable than Subclass3" << endl; 
  cout << "sizeof(Base) = " << sizeof(Base) << endl;
  cout << "sizeof(Subclass3) = " << sizeof(Subclass3) << endl;
}
void test2()
{
  Subclass4 sub(1, 2, 3, 4);
  sub.show();
}
void test1()
{
  Subclass1 aa;
  aa.a = 100;
  //访问不了父类的成员变量b，和普通的类访问不了protected类型的成员变量一样
  //aa.b = 100;
  //访问不了父类的成员变量b，和普通的类访问不了pvivate类型的成员变量一样
  //aa.c = 100;
  aa.d = 100;
  aa.show();

  Subclass2 bb;
  //a、b、c都不可访问，因为是通过protected方式继承的，父类中使用public权限修饰的成员变量的访问权限变为protected
  //bb.a = 100;
  //bb.b = 100;
  //bb.c = 100;
  bb.d = 100;
  bb.show();

  Subclass3 cc;
  //a、b、c都不可访问，因为是通过private方式继承的，相当于将父类的成员变量访问权限全部改为privete
  //cc.a = 100;
  //cc.b = 100;
  //cc.c = 100;
  cc.d = 100;
  cc.show();
}







