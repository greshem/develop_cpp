#ifndef _INCL_TREE_H
#define _INCL_TREE_H
//########################################################################
#include <fstream>
#include <string> 
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>

using namespace std;
template <class T> class tree
{
public:
        tree *_pup;
        tree *_pleft;
        tree *_pright;
        tree *_pdown;
        T _data;

        tree( T in );
        //tree(tree *pparent);
		int  addParent(tree *pparent);
		int  addChild(tree *pchild);
        ~tree();

};

template <typename T> void Dump( tree<T>  *in );

template <class T> tree<T>::tree( T in )
{
        _pup=0;
        _pleft=0;
        _pright=0;
        _pdown=0;
		_data=in;
}

//�����������һ����, �ڵ�, ���Լ��ӳ������ӽڵ㡣 
 template <class T> int tree<T>::addParent(tree *pparent)
{
		//����  parent ���ӽڵ�, ��������ߵ� �ҽڵ㣬 �����Լ�
        if (pparent->_pdown) 
		{
				//�����ӽڵ㣬 ��ô��ӵĶ����� Ӧ��������ӽڵ�� ���ҽ������.,  
                _pleft=pparent->_pdown;
                while (_pleft->_pright)
				{ 
					_pleft=_pleft->_pright;
				};
                _pleft->_pright=this;
        } 
		else 
		{
				//�Լ���Ϊ�����ӽڵ���
                pparent->_pdown=this;
                _pleft=0;
        }
        _pup=pparent;
        _pright=0;
        _pdown=0;
		return 1;
}

template <class T>int  tree<T>::addChild(tree *pchild)
{
	//child�Ѿ����˸��ڵ㣬 ���ӵ��Լ���_pdown�ϣ�  Ӧ�üӵ� �Լ��� pright ȥ��
	if(pchild->_pup)
	{
		return 0;
	}
	else
	{
		pchild->_pup=this;
		if(_pleft)
		{
			while(_pleft->_pright)
			{
				_pleft=_pleft->_pright;
			};
			_pleft->_pright=pchild;
		}
		else
		{
			_pleft=pchild;
		}
	}
	return 1;
}

template <class T> tree<T>::~tree()
{
        while (_pdown) delete _pdown;
        if (_pleft) _pleft->_pright=_pright;
        if (_pright) _pright->_pleft=_pleft;
        if (_pup && _pup->_pdown==this) _pup->_pdown=_pright;
}
 //       tree *_pup;
 //       tree *_pleft;
 //       tree *_pright;
 //       tree *_pdown;

template <class T>  void Dump( tree<T>  *in )
{
	cout<<in->_data<<endl;
	while(in->_pdown)	
	{
		Dump(in->_pdown);
	}
}

//########################################################################
int main()
{
 	tree<string> child1("111");;	
 	tree<string> child2("222");//(&child1);	
 	tree<string> child3("333");
 	tree<string> child4("/");;

	child4.addChild(&child1);
	child4.addChild(&child2);
	child4.addChild(&child3);

	Dump(&child4);	
	return 0;
}
#endif
