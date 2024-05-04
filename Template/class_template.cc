/*
 * author: inkXu
 * date:   2022.8.5
 *
 * 类模板
 */
#include<iostream>
#include<string>
using namespace std;

//类模板的定义
template <class T1, class T2>
class Animal
{
public:
  Animal(T1 a, T2 b)
  {
    this->a = a;
    this->b = b;
  }
  T1 a;
  T2 b;
};

//子类继承类模板时需要指定继承的类模板具体的模板类型
class Dog: public Animal<int, int>
{
public:
  Dog(int a, int b): Animal(a, b){}
};
class Cat: public Animal<int ,string>
{
public:
  Cat(int a, string b): Animal(a, b){};
};
//子类继承模板类时，子类也可写成模板类
template <class T1, class T2>
class Sheep: public Animal<T1, T2>
{
public:
  //使用模板类继承时，初始化时，调用父类的构造函数，要写成模板构造函数
  Sheep(T1 a, T2 b): Animal<T1, T2>(a, b){}
};

void test1();              //类模板作为函数形参
void test2();              //子类继承类模板
//类模板作为参数时
void show_int(Animal<int, int> &animal);
void show_string(Animal<string, string> &animal);
void show_int_string(Animal<int, string> &animal);
//类模板作为参数时优化
template <class T1, class T2>
void template_show(Animal<T1, T2> &animal);
//再优化，这里的T相当于Animal<T1, T2>，这可能出问题，若是传入的不是想要的类型，会出错
template <class T>
void template_show(T &animal);

int main()
{
  test1();
  return 0;
}

void test2()
{
  Dog dog(3, 5);
  show_int(dog);

  Cat cat(3, "kiti");
  show_int_string(cat);

  Sheep<string, string> sheep("Madi", "Haci");
  show_string(sheep);
}
void test1()
{
  //使用类模板实例化对象，类模板是一个类型，所以要加上<>，并且要指定类型
  Animal<int, int> sint(666, 999);
  show_int(sint);
  template_show(sint);

  Animal<string, string> sstring("mike", "bob");
  show_string(sstring);
  template_show(sstring);

  Animal<int, string> sintstring(666, "mike");
  show_int_string(sintstring);
  template_show(sintstring);

  //使用函数模板调用类模板
  Animal<int, string> a(45, "mike");
  template_show<int, string>(a);
  template_show(a);

  //若传入没有a和b两个成员变量的变量，会报错
  //int ccc = 100;
  //template_show(ccc);
}

void show_int(Animal<int, int> &animal)
{
  cout << "show_int() = " << animal.a << "  " << animal.b << endl;
}
void show_string(Animal<string, string> &animal)
{
  cout << "show_string() = " << animal.a << "  " << animal.b << endl;
}
void show_int_string(Animal<int, string> &animal)
{
  cout << "show_int_string() = " << animal.a << "  " << animal.b << endl;
}
template <class T1, class T2>
void template_show(Animal<T1, T2> &animal)
{
  cout << "template_show(Animal<T1, T2> &animal) = " << animal.a << "  " << animal.b << endl;
}
template <class T>
void template_show(T &animal)
{
  cout << "template_show(T &animal) = " << animal.a << "  " << animal.b << endl;
}







