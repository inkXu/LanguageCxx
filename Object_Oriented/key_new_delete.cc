/*
 * author: inkXu
 * date:   2022.7.30
 *
 * new和delete运算符
 *
 * 因为malloc动态申请的对象不会调用构造方法，所以C++使用new来动态申请内存
 */
#include<iostream>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;

class Person
{
public:
  Person()
  {
    cout << "structure is used" << endl;
  }
  ~Person()
  {
    cout << "destruct is used" << endl;
  }
};

void test1();    //malloc动态申请对象
void test2();    //new动态申请对象
void test3();    //杂项，注意数组的释放需要加[]
void test4();    //delete void * 的注意事项

int main()
{
  test4();
  return 0;
}

void test4()
{
  void *p = new Person;
  //出现警告，delete void * 未定义
  //析构函数未被调用
  delete p;
}
void test3()
{
  int *int_new = new int;
  char *arr_new = new char[10];
  *int_new = 100;
  cout << *int_new << endl;
  cout << int_new << endl;
  strcpy(arr_new, "mike");
  cout << arr_new << endl;
  cout << &arr_new << endl;
  delete int_new;
  delete[] arr_new;
  cout << int_new << endl;
  cout << &arr_new << endl;
}
void test2()
{
  //结果：调用了构造和析构
  Person *p_new = new Person;
  delete p_new;
}
void test1()
{
  //结果：未调用构造和析构
  Person *p_malloc = (Person *)malloc(sizeof(Person));
  free(p_malloc);
  p_malloc = NULL;
}






