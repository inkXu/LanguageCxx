/*
 * author: inkXu
 * date:   2022.7.30
 *
 * 深浅拷贝
 *
 * 若是一个类中定义了拷贝构造，那么系统将不生成无参构造，和析构等
 * 若是定义了有参构造，系统将不会定义析构函数，但会定义拷贝构造
 * 重新定义的拷贝函数为深拷贝，默认的仅有值拷贝的拷贝函数为浅拷贝
 */
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class Person
{
public:
  int mAge;
  char *mName;
  Person(int age, char *name)
  {
    mAge = age;
    mName = (char *)malloc(strlen(name) + 1);
    strcpy(mName, name);
  }
//深拷贝部分
#if 1
  Person(const Person &p)
  {
    mAge = p.mAge;
    mName = (char *)malloc(strlen(p.mName) + 1);
    strcpy(mName, p.mName);
  }
#endif
  ~Person()
  {
    if(mName != NULL)
    {
      free(mName);
      mName = NULL;
    }
  }
  void show()
  {
    cout << "my age is " << mAge << " and my name is " << mName << endl;
  }
};

void test1();

int main()
{
  test1();
  return 0;
}

void test1()
{
  //有一个警告，不要将常量字符串赋值给char *类型
  Person p1(21, "mike");
  p1.show();
  //该地方没有使用深拷贝时，只是进行了普通的值拷贝，则p2的mName指向的地址和p1指向的地址
  //是同一块，调用析构函数时就会free两次同一块空间，这是不允许的
  Person p2(p1);
  p2.show();
}




