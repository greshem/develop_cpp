#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef unsigned int uint;
#define  StdVectSize 2000
template <class T>
class Vector {
 private:
  T **tab;
  uint pos;
  
	uint size;

 public:
  Vector (uint size = StdVectSize);
  ~Vector ();
  void recycle ();
  void addElement (T *elt);
  inline uint getLength () { return pos; }
  inline uint getSize() {return size;}
  inline T **getTab() { return tab; }
  T *operator [] (uint i);
};

template <class T> Vector<T>::Vector (uint size) 
{
  this->size = size;
  pos = 0;
  //tab = new sizeof(T)*size ;
  tab = new T*[size];
}

template <class T> Vector<T>::~Vector () 
{
	for (uint i=0; i<pos; i++) 
	{
	//if(tab[i])	delete tab[i];
	}
	delete [] tab;
}

template <class T>
void Vector<T>::recycle () 
{
	for (uint i=0; i<pos; i++) 
	{
		delete tab[i];
	}
	pos = 0;
}

template <class T> void Vector<T>::addElement (T *elt) 
{
  assert (pos <= size);
  if (pos == size) 
	{
        size *= 2;
        T **tmp = new T*[size];
        for (uint i=0; i<pos; i++) 
		{
          tmp[i] = tab[i];
        }
        delete [] tab;
        tab = tmp;
  }
  tab[pos] = elt;
  pos++;
}


template <class T> T *Vector<T>::operator [] (uint i) 
{
	if (i<pos) 
	{
		return tab[i];
	} 
	else 
	{
		return NULL;
	}
}

main()
{     Vector<int> vec_int(100);
      int i=100;
      vec_int.addElement(&i);
      vec_int.addElement(&i);
      vec_int.addElement(&i);
      vec_int.addElement(&i);
      vec_int.addElement(&i);
      vec_int.addElement(&i);
      
      printf("element %d\n", vec_int.getLength());
      printf("size %d\n", vec_int.getSize());
//      getchar();
      return 0;
}
