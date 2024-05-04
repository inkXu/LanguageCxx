/*
 * author: inkXu
 * date:   2022.8.1
 *
 * 运算符重载
 *
 * 可以重载的运算符
 * + - * / % ^ & | ~ ! = > < += *= /= -= ^= &= |= << >> >>= <<= == != <= >= && || ++ -- -> * ' [] () new delete
 * new[] delete[]
 * 不能重载的运算符
 * .  ::  .*  ?:  sizeof
 */
#include<iostream>
#include<string>
using namespace std;

class Person
{
  //test2例子
  friend ostream& operator<<(ostream& cout, Person &p);
public:
  Person(string name, int age)
  {
    this->name = name;
    this->age = age;
  }
  void set_birthday(string bir)
  {
    this->birthday = bir;
  }
  void show()
  {
    cout << "my name is " << name << " and my age is " << age << endl;
  }
#if 1
  Person operator+(Person &p1)
  {
    Person p(this->name + p1.name, this->age + p1.age);
    return p;
  }
#endif
  //++在变量前，注意返回值类型为引用类型，this指针相当于原对象的引用，所以返回值用引用类型
  Person& operator++()
  {
    this->age = this->age + 1;
    return *this;
  }
  //++在变量后时，不能返回引用类型，和指针一样，不能返回局部变量的指针和引用
  Person& operator++(int)
  {
    //我这里如果单纯的返回一个对象的话，在<<运算符重载中的第二个参数会报错，如果一定要返回一个对象，
    //那么外面使用<<运算符输出的时候，要先将返回值用一个对象存着，再使用这个新的对象才行
    static Person tmp(*this);
    this->age = this->age + 1;
    return tmp;
  }
  string name;
  int age;
private:
  string birthday;
};

void test1();       //重载加号运算符，类对象相加
//Person operator+(Person &p1, Person &p2);

void test2();       //重载左移运算符(<<)之友元
//void operator<<(ostream& cout, Person &p);
//这里的返回值要使用引用，因为传入的参数cout也是一个引用类型
ostream & operator<<(ostream &cout, Person &p);

void test3();       //重载++运算符

int main()
{
  test3();
  return 0;
}

void test3()
{
  Person p("sunny", 13);
  p.set_birthday("2001-09-09");
  p.show();
  cout << "++p = " << ++p << endl;   //两种方法(operator++(p1) , p1.operator++())
  p.show();

  //Person pp = p++;
  //cout << "p++ = " << pp << endl;   //p1.operator++(int)
  cout << "p++ = " << p++ << endl;
  p.show();
}
void test2()
{
  Person p("sun", 12);
  p.set_birthday("20010909");
  //和test1一样有两种情况，全局函数和类的成员函数，但是cout为标准库里的东西，所以使用类的成员函数
  //cout << p;
  //下面这句会报错，因为对<<运算符的重载返回值为void类型，就是void << endl;的样子，解决方法就是返回值cout
  cout << p << endl;
}
#if 1
ostream & operator<<(ostream &cout, Person &p)
{
  //访问了私有变量birthday，在类中声明友元即可访问
  cout << p.name << "   " << p.age << "  " << p.birthday;
  return cout;
}
#endif
#if 0
void operator<<(ostream& cout, Person &p)
{
  cout << p.name << "   " << p.age << endl;
}
#endif
void test1()
{
  Person p1("sun", 12);
  Person p2("shine", 14);
  //有两种情况，全局函数和类的成员函数，两者最多只能写一个，两个都写了会报错
  Person p3 = p1 + p2;
  p1.show();
  p2.show();
  p3.show();
}
#if 0
//重载加号运算符，将p1和p2对象中的姓名和年龄相加
Person operator+(Person &p1, Person &p2)
{
  Person p(p1.name + p2.name, p1.age + p2.age);
  return p;
}
#endif









