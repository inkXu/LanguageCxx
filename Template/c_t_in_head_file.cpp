#include"c_t_in_head_file.hpp"

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



