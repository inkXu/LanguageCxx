/*
 * author: inkXu
 * date:   2022.7.31
 *
 * 友元
 *
 * 在一个类中声明了其它作用域的函数，那么该函数可以访问该类中的私有成员变量
 * 注意一下一个类要访问另一个类的方法，要先声明类，再定义另一个类，在另一个类中如果要声明前面类，只能用指针声明，
 * 因为前一个只进行了声明，没有具体的定义，如果前一个类需要对后一个类的数据进行访问，那么前一个类只能使用类外
 * 定义法，在后一个类定义完毕后，再对前一个方法的类进行定义
 */
#include<iostream>
#include<string>
using namespace std;

class Home;
class Friend
{
public:
  //这里必须要在这个类之前声明了Home类才能这样写，若没有声明会报错，这里不能写成Home home;因为Home没有定义
  Home *home;
  //这里的构造方法和普通方法若要使用Home类中的内容，一定要在Home定义完再定义方法，这里只做声明
  Friend(string hall, string bedroom);
  void visit();
};

class Home
{
  //声明该全局函数作为Home类的友元函数
  friend void show(Home &home);
  //声明Friend类中函数作为Home类的友元函数
  //friend void Friend::visit();
  //声明Friend类为Home类的友元类
  friend class Friend;
public:
  string hall;
  Home(string hall, string bedroom)
  {
    this->hall = hall;
    this->bedroom = bedroom;
  }
  void show()
  {
    cout << "bedroom is " << bedroom << ", hall is " << hall << endl;
  }
private:
  string bedroom;
};

//类外定义
Friend::Friend(string hall, string bedroom)
{
  home = new Home(hall, bedroom);
}
//类外定义
void Friend::visit()
{
  cout << "bedroom is " << home->bedroom << ", hall is " << home->hall << endl;
}

//该函数作为Home类的友元函数来调用Home类的私有成员
void show(Home &home)
{
  cout << "bedroom is " << home.bedroom << ", hall is " << home.hall << endl;
}

void test1();     //全局方法作为Home类的友元来调用Home类的私有成员
void test2();     //一个类中的成员函数作为友元函数访问另一个类中的私有成员变量
void test3();     //一个类作为友元访问另一个类中的私有成员变量

int main()
{
  test3();
  return 0;
}
void test1()
{
  Home home("moonlight", "sunshine");
  show(home);
}
void test2()
{
  Friend frie("moonlight", "sunshine");
  frie.visit();
}
void test3()
{
  Friend frie("moonlight", "sunshine");
  frie.visit();
}














