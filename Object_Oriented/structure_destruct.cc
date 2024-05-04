/*
 * author: inkXu
 * date:   2022.7.25
 *
 * 构造函数和析构函数和拷贝函数
 *
 * 一个类中就算没有人为的编写这三个函数，系统也会生成这三个函数，
 * 自动生成的构造和析构这两个函数里啥都没有，拷贝函数默认是进行了值的拷贝
 * 无参构造函数的调用不用加括号，即(Person p1;)，有参则按参数个数写
 * 如果你编写了有参构造函数，则系统不会编写无参构造函数，就不能(Person p1)
 */
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
  //构造函数
  //实例化对象时会调用该函数
  Person()
  {
    cout<< "无参构造函数被调用了" <<endl;
  }
  //explicit关键字，修饰构造函数，使该方法不能被隐式调用
  explicit Person(string name, int age)
  {
    cout<< "有参构造函数被调用了" <<endl;
    //string类型的变量可以直接赋值，不能用strcpy函数拷贝，string是对象
    m_name = name;
    m_age = age;
  }
  void show()
  {
    cout<< "my name is " << m_name\
        << ", and I am " << m_age << "-years-old" <<endl;
  }
  //析构函数
  //析构函数实例化的对象销毁时会调用该函数，写法：~类名
  ~Person()
  {
    cout<< "析构函数被调用了" <<endl;
  }
  //拷贝函数
  //拷贝函数的参数为常量引用，不能写成了Person person，这样表示初始化一个对象，
  //会陷入死循环，加const关键字是因为这个对象不能是其它对象，确定没有强制转换
  Person(const Person &person)
  {
    m_name = person.m_name;
    m_age = person.m_age;
    cout<< "拷贝函数被调用了!" <<endl;
  }
private:
  string m_name;
  int    m_age;
};

void test1();
void test2();   //拷贝构造函数，默认的就是值的拷贝
void test3();   //对象的实例化
void test4();

int main()
{
  test4();
  return 0;
}

void test4()
{
  Person("liu", 32);
  Person p1("liu", 32);
  Person p2 = p1;
}
#if 0
void test3()
{
  //匿名对象，没有名字，生命周期在当前行
  Person();                       //调用无参构造生成匿名对象
  Person("nihao", 18);            //调用有参构造生成匿名对象
  //Person(p1);                   //匿名对象不能使用括号法调用拷贝构造
  //显式法调用构造函数
  Person p1 = Person();           //显式调用无参构造
  Person p2 = Person("lein", 18); //显式调用有参构造
  Person p3 = Person(p2);         //显式调用拷贝构造
  //隐式调用，若是类中的方法加了explicit关键字，则不能用隐式调用
  //Person p1 = Person();         //隐式无法调用无参构造
  //Person p4 = {"yinshi", 18};   //隐式调用有参构造，老师有用我没用
  Person p5 = p2;                 //隐式调用拷贝构造
}
#endif
void test2()
{
  Person p1("niu", 31);
  //拷贝构造
  Person p2(p1);
  p1.show();
  p2.show();
}
void test1()
{
  Person person("liu", 32);
  person.show();
}
