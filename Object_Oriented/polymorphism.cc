/*
 * author: inkXu
 * date:   2022.8.4
 *
 * 多态
 *
 * 多态为一种接口多种形态，多态分为静态多态和动态多态
 * 函数的重载就是静态多态，静态多态在编译阶段就会给每一个函数申请一个地址，地址不会发生改变，地址早绑定（静态联编）
 * 对虚函数的重写就是动态多态，在运行时才调用需要的地址（动态联编）
 * 实现多态条件
 * 父类有虚函数   发生了继承   子类重写了父类的虚函数  有全局接口实现了父类虚函数，形参为父类指针或引用
 * 动态多态实现原理
 * 当有虚函数时，默认会生成一个虚函数指针，该指针指向虚函数表，在类的构造函数被调用时该指针会初始化，
 * 初始化后指针指向父类的虚函数的地址，在发生继承后，子类中也会继承虚函数指针和虚函数表，若是子类对
 * 虚函数进行了重写，那么子类中的虚函数表的地址会变为子类重写的虚函数后的地址
 */
#include<iostream>
using namespace std;

//父类植物类
class Plant
{
public:
  void show()
  {
    cout << "Plant show" << endl;
  }
  virtual void Growing()
  {
    cout << "Plant growing" << endl;
  }
};
//竹子类
class Bamboo: public Plant
{
public:
  void Growing()
  {
    cout << "Bamboo is growing good" << endl;
  }
};
//松树类
class Pine: public Plant
{
  void Growing()
  {
    cout << "Pine is growing good" << endl;
  }
};

//父类普通函数的实现，子类可以使用该方法，但不能发生重写父类方法，若子类中有同名的方法调用该方法使用的也
//还是父类的方法，不是子类中的方法，因为发生了地址早绑定
void show(Plant &plant)
{
  plant.show();
}
//父类中virtual函数的实现，该接口传入基类的引用，传入子类对象时，若有重写了父类的虚函数，那么使用的是子
//类中的函数，这就是动态多态，在程序运行时才决定调用哪个类的方法，虚函数指针地址不是绑定的
void show_growing(Plant &plant)
{
  plant.Growing();
}

void test1();

int main()
{
  test1();
  return 0;
}

void test1()
{
  Plant plant;
  Bamboo bamboo;
  Pine pine;

  show(plant);
  show(bamboo);
  show(pine);

  show_growing(plant);
  show_growing(bamboo);
  show_growing(pine);
}







