#include "Stroka.h"
#include "Decstr.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
//#include <lstring.h>
using namespace std;
extern"C" char* _stdcall fun1(int);
DecStr::DecStr(char val) :Stroka(val)
{
    if (!((pCh[0] = '1' && pCh[0] <= '9') || (pCh[0] == '-' && pCh[0] == '+')))
    {
        cout << "Bad simbol, pCh[0]=" << pCh[0] << endl;
        if (pCh)delete[]pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
    for (int i = 1; i < len; i++)
    {
        if (!(pCh[i] >= '1' && pCh[i] <= '9'))
        {
            cout << "Bad Stroka, pCh[" << i << "]= if(pCh)delete[]pCh;" << pCh[i] << endl;
            len = 0;
            pCh = new char[len + 1];
            pCh[0] = '\0';
            return;
        }
    }
    cout << "DecStr::DecStr(int val):Stroka(val)" << endl;
}
DecStr::DecStr(const char* str) : Stroka(str)
{
    if (!((pCh[0] >= '1' && pCh[0] <= '9') || (pCh[0] == '-' && pCh[0] == '+')))
    {
        cout << "Bad simbol, pCh[0]=" << pCh[0] << endl;
        if (pCh)delete[]pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
    for (int i = 1; i < len; i++)
    {
        if (!(pCh[i] >= '1' && pCh[i] <= '9'))
        {
            cout << "Bad Stroka, pCh[" << i << "]= if(pCh)delete[]pCh;" << pCh[i] << endl;
            len = 0;
            pCh = new char[len + 1];
            pCh[0] = '\0';
            return;
        }
    }
}
DecStr::DecStr(const DecStr& from) :Stroka(from)
{
    cout << "DecStr::DecStr(const DecStr&from)" << endl;
}
DecStr::~DecStr()
{
    cout << "DecStr::~DecStr()" << endl;
};
DecStr& DecStr::operator=(const DecStr& Ds)
{
    if (&Ds != this)
    {
        delete[]pCh;
        len = strlen(Ds.pCh);
        pCh = new char[len + 1];
        strcpy_s(pCh, len + 1, Ds.pCh);
    }
    cout << "DecStr& DecStr::operator=(const DecStr&Ds)" << endl;
    return *this;
}
DecStr operator+(const DecStr& pobj1, const DecStr& pobj2)
{
    int num1, num2;
    DecStr tmp(pobj1);
    num1 = atoi(tmp.Getstr());
    num2 = atoi(pobj2.Getstr());
    char* pTmpCh;
    int A = num1 + num2;
    if (tmp.len >= pobj2.len)
    {
        pTmpCh = new char[tmp.len + 2];
        _itoa_s(A, pTmpCh, tmp.len + 2, 10);
    }
    else
    {
        pTmpCh = new char[pobj2.len + 2];
        _itoa_s(A, pTmpCh, pobj2.len + 2, 10);
    }
    if (tmp.pCh)
        delete[] tmp.pCh;
    tmp.pCh = pTmpCh;
    tmp.len = strlen(tmp.pCh);
    return tmp;
}
/*DecStr operator+(const DecStr& pobj1, const int pobj2)
{
    int num1, num2;
    DecStr tmp(pobj1);
    num1 = atoi(tmp.Getstr());
    num2 = pobj2;
    int A = num1 + num2;
    while (num2 > 0)
    {
        num2 /= 10;
        len2 += 1;
    }
    if (tmp.len >= len2)
    {

    }
    else
    {

    }
    cout << "..." << endl;
    return tmp;
}*/
DecStr operator+(const int, const DecStr&)
{
    return DecStr();
}
