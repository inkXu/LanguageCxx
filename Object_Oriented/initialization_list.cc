/*
 * author: inkXu
 * date:   2022.7.30
 *
 * 初始化列表
 *
 * 注意：
 * 需要按照申明顺序来定义，初始化列表进行了定义并赋值的操作
 * 写法如下示例
 * 主要用途：
 * 在仅有有参构造的类中，其内还有其它对象(类)，这样的类对其中的对象(仅有有参构造的对象)进行初始化时
 */
#include<iostream>
#include<string>
using namespace std;

class Game
{
public:
  string g_name;
  Game(string name)
  {
    g_name = name;
  }
};
class Person
{
public:
  string name;
  int age;
  Game game;
//使用初始化列表
  Person(string name1, int age1, string g_name) : name(name1), age(age1), game(g_name) {}
  void show()
  {
    cout << "my name is " << name << " and my age is " << age << " like " << game.g_name << endl;
  }
//提示错误没有匹配的参数
#if 0
  Person(string name1, int age1, string g_name)
  {
    name = name1;
    age = age1;
    game.g_name = g_name;
  }
#endif
};

void test1();

int main()
{
  test1();
  return 0;
}

void test1()
{
  Person p("mike", 23, "xiaolaohu");
  p.show();
}






