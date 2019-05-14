#ifndef __EXCEPTION_H
#define __EXCEPTION_H

#define DataErr -1
#define DataEmpty -101 // �� �����
#define DataFull -102 // �� �����������
#define DataNoMem -103 // ��� ������

template <class T>
class TException {
protected:
  int RetCode; // ��� ����������
public:
  TException(int ex);
};

template <class T>
TException<T>::TException(int ex)
{
  RetCode = ex;
}
#endif