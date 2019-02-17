#ifndef __EXEPTION_H
#define __EXEPTION_H

#define DataErr -1
#define DataEmpty -101 // �� �����
#define DataFull -102 // �� �����������
#define DataNoMem -103 // ��� ������

template <class T>
class TExeption {
protected:
  int RetCode; // ��� ����������
public:
  TExeption(int ex);
};

template <class T>
TExeption<T>::TExeption(int ex)
{
  RetCode = ex;
}
#endif