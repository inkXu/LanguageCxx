/*
 * author: inkXu
 * date:   2022.8.5
 *
 * .hpp文件为头文件，但是其中又有函数的定义，原因是，在函数模板中，不能像平常那样将声明写在.h文件，而定义部分
 * 写在其它的.cpp文件中。需要将声明和定义写在一个文件中 或是 将声明写在.h文件，定义写在有main函数的文件中，
 * 老师讲的是预处理只是简单的作个拷贝，将.h文件的内容，没有定义，所以调用时只有声明而没有定义，报没有定义的引用
 * 但按照老师讲的话，普通的类应该也是这样的吧，但是普通的类能用普通的分文件方法
 */
#include<iostream>
using namespace std;

template <class T>
class Animal
{
public:
  Animal(T id);
  void show();

  T id;
};

#if 1
template <class T>
Animal<T>::Animal(T id)
{
  this->id = id;
} 
template <class T>
void Animal<T>::show()
{
  cout << "Animal id: " << this->id << endl;
}
#endif



