#pragma once
#include "TVector.h"

template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
  TMatrix(int s = 10);
  TMatrix(const TMatrix &mt); // ����������� 
  TMatrix(const TVector<TVector<ValType> > &mt); // �������������� ���� 
  bool operator==(const TMatrix &mt); // ��������� 
  bool operator!=(const TMatrix &mt); // ��������� 
  TMatrix & operator= (const TMatrix &mt); // ������������ 
  TMatrix operator+ (const TMatrix &mt); // �������� 
  TMatrix operator- (const TMatrix &mt); // ��������� 
  TMatrix operator* (const TMatrix &mt); // ��������� 
  // ���� / �����
  friend istream & operator>>(istream &in, TMatrix &mt)
  {
    for (int i = 0; i < mt.size; i++)
      in >> mt.pVector[i];
    return in;
  }

  friend ostream & operator<<(ostream &out, const TMatrix &mt)
  {
    for (int i = 0; i < mt.size; i++)
      out << mt.pVector[i] << endl;
    return out;
  }
};


template<class ValType>
TMatrix<ValType>::TMatrix(int s) : TVector<TVector<ValType> >(s)
{
  for (int i = 0; i < s; i++)
    this->pVector[i] = TVector<ValType>(s - i, i);
}

template<class ValType>//����������� �����������
TMatrix<ValType>::TMatrix(const TMatrix & mt) : TVector<TVector<ValType> >(mt)
{
  for (int i = 0; i < this->Size; i++)
    this->pVector[i] = TVector<ValType>(mt.pVector[i]);;
}

template<class ValType>//����������� �������������� ����
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> >& mt) : TVector<TVector<ValType> >(mt)
{
}

template<class ValType>//���������
bool TMatrix<ValType>::operator==(const TMatrix<ValType> & mt)
{
  return TVector<TVector<ValType> >::operator==(mt);
}

template <class ValType> // ���������
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) 
{
  return !(*this == mt);
}

template<class ValType>//������������
TMatrix<ValType> & TMatrix<ValType>::operator=(const TMatrix & mt)
{
  if (this != &mt)
  {
    this->Size = mt.Size;
    delete[] this->pVector;
    this->pVector = new TVector<ValType>[this->Size];
    for (int i = 0; i < this->Size; i++)
      this->pVector[i] = mt.pVector[i];
  }
  return *this;
}
template<class ValType> //��������
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix & mt)
{
  if (this->Size != mt.Size)
    throw -1;
  TMatrix tmp(this->Size);
  for (int i = 0; i < this->Size; i++)
    tmp.pVector[i] = this->pVector[i] + mt.pVector[i];
  return tmp;
}

template<class ValType>//���������
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix & mt)
{
  if (this->Size != mt.Size)
    throw -1;
  TMatrix tmp(this->Size);
  for (int i = 0; i < this->Size; i++)
    tmp.pVector[i] = this->pVector[i] - mt.pVector[i];
  return tmp;
}

template<class ValType>
TMatrix<ValType> TMatrix<ValType>::operator*(const TMatrix & mt)
{
  if (this->Size != mt.Size)
    throw -1;
  TMatrix tmp(this->Size);
  for (int i = 0; i < this->Size; i++)
    for (int j = i; j < this->Size; j++)
      for (int k = i; k < j + 1; k++)
        tmp.pVector[i][j] += this->pVector[i][k] * mt.pVector[k][j];
  return tmp;
}
