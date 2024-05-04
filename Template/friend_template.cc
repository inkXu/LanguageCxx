/*
 * author: inkXu
 * date:   2022.8.5
 *
 * 友元函数在模板类中的使用方法
 */
#include<iostream>
#include<string>
using namespace std;

//因为你下面要声明有模板类作为参数的函数，所以你的模板类的声明或定义要写在这个函数的声明或定义上面
template <class T1, class T2>
class Animal;
#if 1
//因为你的类中声明了该函数为友元函数，所以你的这个函数的定义或声明要写在类的定义上面，
//在类的定义的时候才知道有这个函数
//写声明时
template <class T1, class T2>
void show_animal(Animal<T1, T2> &animal);
//写定义时
template <class T1, class T2>
void show_animal_2(Animal<T1, T2> &animal)
{
  cout << "show_animal_2<T1, T2>(Animal<T1, T2> &animal)" << endl;
  cout << "animal.name = " << animal.name << "    animal.age = " << animal.age << endl;
}
#endif
template <class T1, class T2>
class Animal
{
  //声明模板函数为友元函数，记得加模板，即函数名后加<>，这里的Animal可以不用写模板了，但全局的要
  friend void show_animal<>(Animal<T1, T2> &animal);
  friend void show_animal_2<>(Animal<T1, T2> &animal);
  //该函数为全局函数，虽然在类中定义了，但是声明了是友元，推荐这种写法，这里定义的是普通函数，不能定义为
  //模板函数，原因可能是为了防止你在类中定义的函数，理论上是全局的函数，只是写在了类里面，但是外面实际上
  //调用不了该函数，若定义为模板函数会报些奇怪的错误
  friend void show_animal_3(Animal<T1, T2> &animal)
  {
    cout << "show_animal_3<T1, T2>(Animal<T1, T2> &animal)" << endl;
    cout << "animal.name = " << animal.name << "    animal.age = " << animal.age << endl;
  }
#if 0
  //类外没有声明该函数将无法使用
  friend void show()
  {
    cout << "show()" << endl;
  }
#endif
#if 0
  //这段代码写了会报错
  template <class T>
  friend void show<T>(T &animal)
  {
    cout << "show<T>(T &animal)" << endl;
  }
#endif
public:
  Animal(){}
  Animal(T1 name, T2 age)
  {
    this->name = name;
    this->age = age;
  }
private:
  T1 name;
  T2 age;
};

template <class T1, class T2>
class Dog: public Animal<T1, T2>
{
public:
  Dog(T1 name, T2 age): Animal<T1, T2>(name, age){}
};
void test1();

int main()
{
  test1();
  return 0;
}

void test1()
{
  Animal<string, int> animal("kiti", 14);
  show_animal(animal);
  show_animal_2(animal);
  show_animal_3(animal);
  Dog<string, int> dog("dogge", 15);
  show_animal_3(dog);
  //show(dog);
}
template <class T1, class T2>
void show_animal(Animal<T1, T2> &animal)
{
  cout << "show_animal(Animal<T1, T2> &animal)" << endl;
  cout << "animal.name = " << animal.name << "    animal.age = " << animal.age << endl;
}







