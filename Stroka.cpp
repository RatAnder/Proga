#include "Stroka.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
//#include <lstring.h>
using namespace std;

extern"C" char* _stdcall fun1(int);
Stroka::Stroka(int val) :len(val), pCh(new char[len + 1])
{
    if (val == 0)
        pCh[0] = '\0';
    cout << "Stroka::Stroka(int val)" << endl;
}
Stroka::Stroka(char ch) :len(1), pCh(new char[len + 1])
{
    pCh[0] = ch;
    pCh[1] = '\0';
    cout << "Stroka::Stroka(char ch)" << endl;
}
/*Stroka::Stroka(const char* S) :len(strlen(S)), pCh(new char[len + 1])
{
    strcpy_s(pCh, len + 1, S);
    cout << "Stroka::Stroka(const char S)" << endl;
}*/

Stroka::Stroka(const char* S)
{
    len = 0;
    int i = 0;
    while (S[i++] != '\0') {
        len++;
    }
    //S -= len + 1;
    len++;
    pCh = new char[len + 1];
    for (i = 0; S[i] != 0; i++)
    {
        *pCh++ = *S++;
        pCh -= len + 1;
    }
    cout << "Stroka::Stroka(const char S)" << endl;
}

Stroka::Stroka(const Stroka& from) : len(strlen(from.pCh)), pCh(new char[from.len + 1])
{
    strcpy_s(pCh, len + 1, from.pCh);

    cout << "Stroka::Stroka(const Stroka &from)" << endl;
}
Stroka::~Stroka()
{
    if (pCh)
        delete[]pCh;
    cout << "Stroka::~Stroka()" << endl;

}
void Stroka::show(void)
{
    cout << "pCh =" << pCh << endl;
    cout << "len =" << len << endl;
}
