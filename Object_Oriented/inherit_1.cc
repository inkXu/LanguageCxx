/*
 * author: inkXu
 * date:   2022.8.3
 *
 * 继承
 *
 * 1.继承中，若是父类和子类有同名的成员变量或成员函数，那么子类对象调用的是其内的对象，父类中同名的变量和
 * 函数被隐藏了
 * 2.在继承操作中，子类不会继承父类中的构造函数、析构函数和operator=这些函数(可以想会自动生成的这几种都不会继承)
 * 3.继承中有同名的静态成员和普通的成员一样的调用特性
 * 4.多继承，若是同时继承两个父类，两个父类有相同的成员，子类没有，那么子类调用父类时需要声明作用域
 * 5.虚继承，在继承类的时候加了virtual关键字，主要是发生菱形继承的时候，子类继承的两个父类都继承了同一个父类，
 * 子类访问父类的父类内的成员时，会产生歧义，使用了virtual就不会有歧义了，但是发生虚继承时，该类所占用的内存
 * 会更大，使用了虚继承的类中有一个虚基指针(vbptr)，这个指针大小受系统影响，这个指针在构造函数被调用时会初始化，
 * 指向的是虚基类表，这个虚基类表有两个参数，第一个是0，第二个是父类成员变量的偏移量，偏移量计算是虚基类指针的大小
 * 加上当前类所有成员的大小，编译其在你调用了父类的对象时进行操作为 *((char *)&p + ((int *)(*(int *)&p)+1))
 */
#include<iostream>
using namespace std;

//基类Base
class Base
{
public:
  Base(){ }
  Base(int a)
  {
    this->a = a;
  }
  Base(int a, int age)
  {
    this->a = a;
    this->age = age;
  }
  void show()
  {
    cout << "class Base: show()" << endl;
  }
  void show(int)
  {
    cout << "class Base: show(int)" << endl;
  }
  static void static_show()
  {
    cout << "class Base: stataic_show()  cout << b = " << b << endl;
  }
  int a;
  static int b;
  int age;
};
int Base::b = 10086;

//子类A
class A:virtual public Base
{
public:
  A(){ }
  A(int a1,int a2): Base(a1)
  {
    this->a = a2;
  }
  void show(int, int)
  {
    cout << "class A: show(int, int)" << endl;
  }
  static void static_show()
  {
    cout << "class A: stataic_show()  cout << b = " << b << endl;
  }
  int a;
  static int b;
  int c;
};
int A::b = 10011;

//子类B
class B:virtual public Base
{
public:
  B(){ }
  B(int a, int c):Base(a), c(c){ }
  int c;
};

//该继承为一个菱形继承
class multi_inherit: public A, public B
{
public:
  multi_inherit(){ }
  multi_inherit(int a, int age):Base(a, age){ }
  //a1为传到Base中的参数，a2为传到A中的参数，c为传到B中的参数
  multi_inherit(int a1, int a2, int c): A(a1, a2), B(a1, c){ }
  void show()
  {
    //这里全有歧义，报错，a、b是Base和A有歧义，c是A和B有歧义
    //cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    //cout << "Base::a = " << Base::a << endl;     //这里会有歧义
    cout << "Base::b = " << Base::b << endl;
    cout << "A:a = " << A::a << endl;
    cout << "A::b = " << A::b << endl;
    cout << "A::c = " << A::c << endl;
    cout << "B::c = " << B::c << endl;
  }
};

void test1();            //子父类有同名成员变量和函数时
void test2();            //静态成员和函数的使用
void test3();            //多继承
void test4();            //菱形继承
void test5();            //虚继承，一般发生在菱形继承中

int main()
{
  test5();
  return 0;
}

void test5()
{
  //test4中要想使得可以直接调用，不会产生歧义，继承类时要在继承的类前加virtual关键字
  //这样访问的就是最基类的age
  multi_inherit mi(32, 19);
  cout << "mi.age = " << mi.age << endl;
  mi.age = 100;
  cout << "mi.age = " << mi.age << endl;

  A a;
  B b;
  Base base;
  //注意这里的大小问题，和结构体一样，成员变量哪个大就用哪个来开辟空间，这里有一个虚基指针(virtual base ptr)，
  //我用的是64位的系统，所以指针是8个字节，所以他会以8个字节来开辟空间，就是在virtual类内有3个int类型的变量，
  //它以8字节来开辟空间，第三个int在第三次开辟的空间内，还有4个字节的空间没有使用
  cout << "sizeof(A::b) = " << sizeof(A::b) << endl;
  cout << "sizeof(int) = " << sizeof(int) << endl;
  cout << "sizeof(int *) = " << sizeof(int *) << endl;
  cout << "Base: int a, age; static int b;" << endl;
  cout << "A: int a, c; static int b;" << endl;
  cout << "B: int c;" << endl;
  cout << "multi_inherit: no variable" << endl;
  cout << "sizeof(Base) = " << sizeof(base) << endl;
  cout << "sizeof(A) = " << sizeof(a) << endl;
  cout << "sizeof(B) = " << sizeof(b) << endl;
  cout << "sizeof(multi_inherit) = " << sizeof(mi) << endl;
}
void test4()
{
  multi_inherit mi(1, 2, 3);
  //会产生歧义，因为A和B都继承类Base类，所以要使用作用域的方式调用
  //cout << mi.age << endl;
  cout << mi.A::age << endl;
  cout << mi.B::age << endl;
}
void test3()
{
  multi_inherit mi(1, 2, 3);
  mi.show();
}
void test2()
{
  A variable(1, 2);
  cout << "static Base::b = 10086, static A::b = 10011" << endl;
  cout << "static b = " << variable.b << endl;
  variable.static_show();
}
void test1()
{
  A variable(666, 888);
  //输出的是子类中的a
  cout << "Base::a = 666, A::a = 888" << endl;
  cout << variable.a << endl;
  //报错，没有指定的函数，所以这两个函数被隐藏了，子类调用不了
  //variable.show();
  //variable.show(1);
  variable.show(1, 2);
}







