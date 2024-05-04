/*
 * author: inkXu
 * date:   2022.8.6
 *
 * 栈解旋
 *
 * 即抛出异常后，当前创建的对象都将销毁掉，程序异常后的语句都不执行了
 */
#include<iostream>
#include<string>
using namespace std;

class Animal
{
public:
  Animal(string name)
  {
    cout << "structure is used" << endl;
    this->name = name;
  }
  ~Animal()
  {
    cout << this->name << " destruct is used" << endl;
  }
private:
  string name;
};

void test1();
void NewObject();

int main()
{
  test1();
  return 0;
}

void test1()
{
  try{
    Animal a1("one");
    NewObject();
    cout << "cout of object" << endl;
  }
  catch(int){
    cout << "catch a exception of int" << endl;
  }
}
void NewObject()
{
  Animal a2("wto");
  Animal a3("terhe");
  throw 1;
  Animal a4("furo");
  Animal a5("eifv");
}







