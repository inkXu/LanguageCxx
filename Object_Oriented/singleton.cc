/*
 * author: inkXu
 * date:   2022.7.31
 *
 * 单例模式
 *
 * 一个类只能创建一个对象
 * 第一步，将构造方法给私有化
 * 第二步，构造方法私有化后，需要写个公有的成员方法或成员变量来调用构造方法来实例化对象，成功实例化，但是没法调用它
 * 第三步，因为只有对象实例化后才能调用类中的成员，所以不能调用，所以需要将写第二步的成员设置为静态(static)的，
 * 这样就能直接通过作用域的方法(类名::方法)调用，因为静态成员不能在类中初始化，所以需要在类外初始化
 * 第四步，调用拷贝构造时，可以生成新对象，所以还需要将拷贝构造也私有化
 * 第五步，single指针可能会被赋值为NULL，那么它的地址就丢了，也不能new新的对象了，所以需要将这个指针设置为const类型，
 * 作为const类型需要声明时初始化，但是非整型的静态成员初始化会无效，所以不能使用该方法
 * 第六步，所以需要将该指针私有化，通过接口对它进行调用，该接口同第三步原理，需要设置为static类型
 *
 * 出现了的问题，我没有在类外new的时候，会报对'IDCard::single'未定义的引用的错误
 */
#include<iostream>
#include<string>
using namespace std;

class IDCard
{
public:
  string name;
  string id;
  //第二步
  //IDCard *single = new IDCard;
  //第三步
  //static IDCard *single;
  //第五步
  //const static IDCard *single = new IDCard;
  //第六步
  static IDCard *instance()
  {
    return single;
  }
private:
  //第六步
  static IDCard *single;
  const static int a = 100;
  IDCard()    //无参构造私有化
  {
  }
  IDCard(const IDCard &card)    //拷贝构造私有化
  {
  }
};
//注意类外初始化静态成员变量需要加类型(类型 类名::静态成员变量名)
IDCard * IDCard::single = new IDCard;

void test1();          //调用拷贝构造时
void test2();          //完善

int main()
{
  test2();
  return 0;
}
void test2()
{
  IDCard *p = IDCard::instance();
  p->name = "Mike";
  p->id = "422412199807098724";
  IDCard *p1 = IDCard::instance();
  cout << p1->name << endl;
  cout << p1->id << endl;
}
void test1()
{
/*
  IDCard::single->name = "Mike";
  IDCard::single->id = "422412199807098724";
  IDCard p(*IDCard::single);
  cout << p.name << endl;
  cout << p.id << endl;
*/
}








