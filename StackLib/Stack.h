#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include "Exception.h"

template <class T>
class TStack
{
protected: 
  T * Elem; // �������� �����
  int top; // ������� ����� 
  int size;//������ �����
public:
  TStack(int S = 0);
  TStack(TStack<T>&m);
  ~TStack();
  int IsEmpty(); // �������� �������
  int GetSize();// ���-�� ��������� � �����
  bool IsFull(); // �������� �� �������
  bool IsEmpty(); // �������� �� �������
  void Put(const int Val); // �������� �������
  T Get(); // �������� �������
  void Print();
};


#endif

