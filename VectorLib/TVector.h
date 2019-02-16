#ifndef __TVECTOR_H__
#define __TVECTOR_H__

#include <iostream>

using namespace std;


template <class ValType>
class TVector
{
protected:
  ValType * pVector;
  int Size; // ������ �������
  int StartIndex; // ������ ������� �������� �������
public:
  TVector();
  TVector(int s, int si = 0);
  TVector(const TVector &v); // ����������� �����������
  ~TVector();
  int GetSize() { return size; } // ������ �������
  int GetStartIndex() { return startIndex; } // ������ ������� ��������

  ValType & operator[] (int pos); // ������
  bool operator==(const TVector &v); // ���������
  bool operator!=(const TVector &v); // ���������
  TVector & operator= (const TVector &v); // ������������
  // ��������� ��������
  TVector operator+ (const ValType &val); // ��������� ������
  TVector operator- (const ValType &val);// ������� ������
  TVector operator* (const ValType &val);// �������� �� ������
  //��������� ��������
  TVector operator+ (const TVector &v); // ��������
  TVector operator- (const TVector &v); // ���������
  ValType operator* (const TVector &v); // ��������� ������������
  //����-����� 
  friend istream & operator>>(istream &in, TVector<ValType> &v)
  {
    for (int i = 0; i < v.Size; i++)
      in >> v.pVector[i];
    return in;
  }
  friend ostream & operator<<(ostream &out,  TVector<ValType> &v)
  {
    for (int i = 0; i < v.Size; i++)
      out << v.pVector[i] << ' ';
    return out;
  }
};

template<class ValType>
TVector<ValType>::TVector()
{
  pVector = NULL;
  Size = 0;
  StartIndex = 0;
}

template<class ValType>
TVector<ValType>::TVector(int s, int si)
{
  if ((s < 0) || (si < 0)) throw - 1;
  Size = s;
  pVector = new ValType[Size];
  for (int i = 0; i < Size; i++)
    pVector[i] = 0;
  StartIndex = si;
}

template<class ValType> //����������� �����������
TVector<ValType>::TVector(const TVector & v)
{
  Size = v.Size;
  StartIndex = v.StartIndex;
  pVector = new ValType[Size];
  for (int i = 0; i < Size; i++)
    pVector[i] = v.pVector[i];
}


template<class ValType>
TVector<ValType>::~TVector()
{
  delete[]pVector;
}


template<class ValType>//������
ValType & TVector<ValType>::operator[](int pos)
{
  if ((pos - StartIndex < 0) || (pos - StartIndex > Size)) throw - 1;
  return pVector[pos - StartIndex];
}

template<class ValType>//���������
bool TVector<ValType>::operator==(const TVector & v)
{
  if ((Size != v.Size) || (StartIndex != v.StartIndex)) return false;
  for (int i = 0; i < Size; i++)
    if (pVector[i] != v.pVector[i]) return false;
  return true;
}

template <class ValType> // ���������
bool TVector<ValType>::operator!=(const TVector &v) const
{
  return !(*this == v);
}

template<class ValType> //������������
TVector<ValType> & TVector<ValType>::operator=(const TVector &v)
{
  if (this != &v)
  {
    delete[] pVector;
    Size = v.Size;
    StartIndex = v.StartIndex;
    pVector = new ValType[Size];
    for (int i = 0; i < Size; i++)
    {
      pVector[i] = v.pVector[i];
    }
  }
  return *this;
}

template<class ValType> //��������� ������
TVector<ValType> TVector<ValType>::operator+(const ValType & val)
{
  TVector<ValType> res(Size, StartIndex);
  tmp = *this;
  for (int i = 0; i < Size; i++)
    tmp.pVector[i] += val;
  return tmp;
}
template<class ValType>//������� ������
TVector<ValType> TVector<ValType>::operator-(const ValType & val)
{
  TVector<ValType> res(Size, StartIndex);
  tmp = *this;
  for (int i = 0; i < Size; i++)
    tmp.pVector[i] -= val;
  return tmp;
}

template <class ValType> // �������� �� ������
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
  TVector<ValType> tmp(Size, StartIndex);
  tmp = *this;
  for (int i = 0; i < Size; i++)
    tmp.pVector[i] *= val;
  return tmp;
}

template<class ValType>//��������
TVector<ValType> TVector<ValType>::operator+(const TVector & v)
{
  if ((Size != v.Size) || (StartIndex != v.StartIndex)) throw - 1;
  TVector<ValType> tmp(Size, StartIndex);
  tmp = *this;
  for (int i = 0; i < Size; i++)
    tmp.pVector[i] += v.pVector[i];
  return tmp;
}
template<class ValType>//���������
TVector<ValType> TVector<ValType>::operator-(const TVector & v)
{
  if((Size != v.Size) || (StartIndex != v.StartIndex)) throw - 1;
  TVector<ValType> tmp(Size, StartIndex);
  tmp = *this;
  for (int i = 0; i < Size; i++)
    tmp.pVector[i] -= v.pVector[i];
  return tmp;
}

template<class ValType> //��������� ������������
ValType TVector<ValType>::operator*(const TVector & v)
{
  ValType tmp = 0;
  if (Size != v.Size) throw - 1;
  for (int i = 0; i < Size; i++)
    tmp += pVector[i] * v.pVector[i];
  return tmp;
}
#endif