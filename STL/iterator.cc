/*
 * author: inkXu
 * date:   2022.8.7
 *
 * 迭代器
 */
#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<string>
#include<vector>            //stl中vector容器头文件
#include<algorithm>         //stl算法头文件
#include<iostream>
using namespace std;

class Animal
{
  friend ostream &operator<<(ostream &out, Animal &animal);
public:
#if 0
  Animal(const string name, int age)
  {
    this->name = name;
    this->age = age;
  }
#endif
  Animal(const char *name, int age)
  {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->age = age;
  }
//容器的使用会调用拷贝构造，对象中有指针，懂的都懂，为什么会崩溃，没有拷贝构造的时候
#if 1
  Animal(const Animal &animal)
  {
    this->name = new char[strlen(animal.name) + 1];
    strcpy(this->name, animal.name);
    this->age = animal.age;
  }
  Animal &operator=(const Animal &animal)
  {
    if(this->name != NULL)
    {
      delete []this->name;
    }
    this->name = new char[strlen(animal.name) + 1];
    strcpy(this->name, animal.name);
    this->age = animal.age;
  }
#endif
#if 1
  ~Animal()
  {
    delete []name;
  }
  void show()
  {
    cout << name << "    " << age << endl;
  }
private:
  char *name;
  int age;
#endif
#if 0
private:
  string name;
  int age;
#endif
};
class Dog
{
  friend ostream& operator<<(ostream &out, Dog &dog)
  {
    cout << "Dog's name is " << dog.name << ", dog's age is " << dog.age << endl;
  }
public:
  Dog(string name, int age)
  {
    this->name = name;
    this->age = age;
  }
  void show()
  {
    cout << name << "   " << age << endl;
  }
private:
  string name;
  int age;
};

void test1();           //迭代器的简单使用
void test2();           //使用stl中的算法完成输出操作
template <class T>
void print(T a);
void test3();           //容器类型为一个对象时
ostream &operator<<(ostream &out, Animal &animal);
void test4();
void test5();           //容器套容器

int main()
{
  test1();
  return 0;
}

void test5()
{
  vector< vector<int> > viint;

  //定义三个vector<int>类型的容器  
  vector<int> v1;
  vector<int> v2;
  vector<int> v3;

  for(int i = 0; i < 3; i++)
  {
    v1.push_back(i);
    v2.push_back(i + 10);
    v3.push_back(i + 100);
  }

  //将v1，v2，v3三个容器放入viint vector<vector<int>>容器中
  viint.push_back(v1);
  viint.push_back(v2);
  viint.push_back(v3);

  //it为指向第一个vector<int>容器的指针
  vector< vector<int> >::iterator it = viint.begin();

  for( ; it != viint.end(); it++)
  {
    //(*it)为一个vector<int>容器，it为指向一个vector<int>容器的指针
    //(*it)指的是一个vector<int>容器，(*it).begin()指的是(*it)容器的第一个元素，就是第一个int
    for(vector<int>::iterator inner = (*it).begin(); inner != (*it).end(); inner++)
    {
      cout << *inner << "  ";
    }
    cout << endl;
  }
}
void test4()
{
  Dog dog("tow", 23);
  vector<Dog> vdog;
  vdog.push_back(dog);
  for_each(vdog.begin(), vdog.end(), print<Dog>);
}
void test3()
{
  vector<Animal> vAnimal;

  Animal animal("neo", 34);

  print<Animal>(animal);
  cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

  vAnimal.push_back(animal);
  vAnimal.push_back(Animal("kiti", 20));
  vAnimal.push_back(Animal("meni", 8));
  vAnimal.push_back(Animal("saqi", 11));

  for_each(vAnimal.begin(), vAnimal.end(), print<Animal>);
#if 0
  vector<Animal>::iterator it = vAnimal.begin();
  for( ; it != vAnimal.end(); it++)
  {
    print<Animal>(*it);
  }
#endif
}
ostream &operator<<(ostream &out, Animal &animal)
{
  out << "animal's name is " << animal.name << ", and animal age is " << animal.age;
  return out;
}
template <class T>
void print(T a)
{
  cout << a << endl;
}
void test2()
{
  vector<char> vchar;

  //在容器vchar中存入a c e g i k m
  for(int i = 97; i < 110; i = i + 2)
  {
    vchar.push_back(static_cast<char>(i));
  }

  //stl中遍历算法，该算法为一个模板函数，所以第三个函数要传入一个函数，该函数第一和第二个参数使用的为同一个
  //模板，这里该模板是vector<char>::iterator，第二个模板是一个函数指针，该指针是void (*)(char)类型
  for_each(vchar.begin(), vchar.end(), print<char>);
}
void test1()
{
  //定义个容器vint，用来存放int类型的数据
  vector<int> vint;

  //调用vector容器中的尾插法插入元素
  vint.push_back(5);
  vint.push_back(2);
  vint.push_back(0);

  //获取指向容器头的指针，将其放入迭代器（类似智能指针）中
  vector<int>::iterator it_start = vint.begin();
  //获取指向容器最后一个元素的后一个位置的指针
  vector<int>::iterator it_end = vint.end();

  //该迭代器重载了++运算符，可以使得指向容器元素地址的指针指向下一个下一个元素的位置
  for( ;it_start != it_end; it_start++)
  {
    //智能指针的用法，it_start表示的是地址，加*表示该元素的值
    cout << (*it_start) << endl;
  }
}







