/*
 * author: inkXu
 * date:   2022.8.6
 *
 * 字符串容器
 */
#include<iostream>
#include<string>       //包含string容器的文件
using namespace std;

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();
void test9();
void test10();

int main()
{
  test5();
  return 0;
}

/*
 * 特别注意
 */
void test10()
{
  string str = "abcdefghijklmnopqrstuvwxyz";

  char& d = str[3];
  char& a = str[0];

  //调用了operator=()，这个函数会进行判断，若是str已有指向的地址，会将之释放掉，在new一块空间，所以上面的
  //a和d的引用将不能使用了，它们指向的是那个释放掉的空间，会造成内存泄漏，注意，注意，注意
  str = "hsoageoiago";

  //这句话是错的，能执行，但不能使用，会泄漏内存
  cout << a << "   " << d << endl;
}

/*
 * string对象类型转换
 *
 * char *和string对象相互转换
 */
void test9()
{
  string str("thank you very much");

  char *s = NULL;

  //c_str()返回一个const char *的指针，使用const_cast强转为char *类型就可以赋值给char类型的指针了
  s = const_cast<char *>(str.c_str());

  cout << s << endl;
}
/*
 * 字符串的插入和删除
 *
 * string& insert(int pos, const char* s);
 * string& insert(int pos, const string& str);
 * string& insert(int pos, int n, const char c);        //在pos处插入n个c
 * string& erase(int pos, int n = npos);                //删除从pos开始的n个字符
 */
void test8()
{
  string str = "lllllll";

  str.insert(2, "yes");
  cout << str << endl;

  str.insert(6, 6, 'c');
  cout << str << endl;

  str.erase(2, 3);
  cout << str << endl;
}
/*
 * 字串的获取
 *
 * string substr(int pos = 0; int n = npos) const;
 */
void test7()
{
  string str = "lsowoyes";

  string str1 = str.substr(2, 3);

  cout << str1 << endl;
}

/*
 * string比较操作
 *
 * int compare(const string& str) const;
 * int compare(const char* s) const;
 */
void test6()
{
  string name = "ahogi";
  string str = "gi98345hai";

  cout << "name.compare(str) = " << name.compare(str) << endl;;
  cout << "name.compare('yes') = " << name.compare("yes") << endl;
}

/*
 * string查找和替换
 *
 * int find(const string& str, int pos = 0) const;       //查找str第一次出现的位置，从pos开始查找
 * int find(const char* s, int pos = 0) const;
 * int find(const char* s, int pos, int n) const;        //查找str前n个字符第一次出现的位置，从pos开始查找
 * int find(const char c, int pos = 0) const;            //查找字符c第一次出现的位置
 * int rfind(const string& str, int pos = npos) const;   //查找str最后一次出现的位置，从pos开始查找
 * int rfind(const char* s, int pos = npos) const;
 * int rfind(const char* s, int pos, int n) const;       //查找str前n个字符最后一次出现的位置，从pos开始查找
 * int rfind(const char c, int pos = 0) const;           //查找字符c最后一次出现的位置
 * string& replace(int pos, int n, const string& str);   //从下标pos开始的n个字符替换为str
 * string& replace(int pos, int n, const char* s);
 */
void test5()
{
  string str = "Iloveyou";
  cout << str << endl;

  cout << str.find('v') << endl;

  str.replace(1, 4, " love ");
  cout << str << endl;
}

/*
 * string拼接操作
 *
 * string& operator+=(const string& str);
 * string& operator+=(const char* str);
 * string& operator+=(const char c);
 * string& append(const char *s);
 * string& append(const char *s, int n);               //取s字符串前面的n个字符连接到当前字符串后
 * string& append(const string &s);
 * string& append(const string &s, int pos, int n);    //从s字符串中的下标为pos的字符开始取n个字符连接到当前字符串
 * string& append(int n, char c);
 */
void test4()
{
  string str = "Ilove";
  string str1 = "you";

  str += str1;
  cout << str << endl;

  str += ",forver";
  cout << str << endl;

  str += '.';
  cout << str << endl;

  str = "I";

  str.append("love");
  cout << str << endl;

  str.append(str1);
  cout << str << endl;

  //注意没有添加一个字符的append函数重载
  str.append(",");
  cout << str << endl;

  string temp = "ogeforeversghos";
  str.append(temp, 3, 7);
  cout << str << endl;

  str.append(".goge", 1);
  cout << str << endl;

  str.append(9, 'c');
  cout << str << endl;
}

/*
 * char& operator[](int n);
 * char& at(int n);
 */
void test3()
{
  string str = "iloveyou";

  str[0] = 'I';
  for(int i = 0; i < str.length(); i++)
  {
    cout << str.at(i) << "  ";
  }
  cout << endl;

  str.at(0) = 'i';
  cout << str << endl;
}

/*
 * string 赋值操作
 *
 * string& operator=(const char* s);
 * string& operator=(const string &s);
 * string& operator=(char c);
 * string& assign(const char *s);
 * string& assign(const char *s, int n);                //获取s中前n个字符给当前字符串
 * string& assign(const string &s);
 * string& assign(int n, char c);
 * string& assign(const string &s, int start, int n);   //在字符串s中，下标start开始获取n个字符
 */
void test2()
{
  string str("iloveyou");
  string str1("thankyouverymuch");

  str = "yes";
  cout << str << endl;

  str = str1;
  cout << str << endl;

  str = 'c';
  cout << str << endl;

  str.assign("inherit");
  cout << str << endl;

  str.assign("algorithm", 5);
  cout << str << endl;

  str.assign(str1);
  cout << str << endl;

  str.assign(6, 'o');
  cout << str << endl;

  str.assign(str1, 8, 4);
  cout << str << endl;
}

/*
 * string构造函数
 * string();
 * string(const char *s);
 * string(const string& str);
 * string(int n, char c);     使用n个字符c初始化
 */
void test1()
{
  string str;
  string str1("hello");
  string str2(str1);
  string str3(5, 'w');
  cout << str3 << endl;
}







