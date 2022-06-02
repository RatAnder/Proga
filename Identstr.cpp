#include "Stroka.h"
#include "Identstr.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
//#include <lstring.h>
using namespace std;

extern"C" char* _stdcall fun1(int);
IdentStr::IdentStr(int val) :Stroka(val)
{
    cout << "IdentStr::IdentStr(int val):Stroka(val)" << endl;
}
IdentStr::IdentStr(char ch) : Stroka(ch)
{
    if ((pCh[0] >= 'a' && pCh[0] <= 'z') || (pCh[0] >= 'A' && pCh[0] <= 'Z'))
    {
        cout << "IdentStr::IdentStr(char ch)" << endl;
    }
    else
    {
        if (pCh) delete[]pCh;
        int len = 0;
        pCh = new char[len + 1];
    }
    pCh[0] = '\0';
    cout << "Bad simvol" << endl;
}
IdentStr::IdentStr(const char* Str) :Stroka(Str)
{
    if ((pCh[0] >= '0' && pCh[0] <= '9'))
    {
        cout << "Bad Simvol, pCh[0]=" << pCh[0] << endl;
        if (pCh)delete[]pCh;
        int len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
    else
    {
        for (int i = 1; i < len; i++)
        {
            if ((pCh[i] >= 'a' && pCh[i] <= 'z') || (pCh[i] >= 'A' && pCh[i] <= 'Z') || (pCh[i] >= '0' && pCh[i] <= '9') && pCh[i] != '_')
            {
                continue;
            }
            else
            {
                cout << "Bad Simvol, pCh[0]=" << pCh[0] << endl;
                if (pCh)delete[]pCh;
                len = 0;
                pCh = new char[len + 1];
                pCh[0] = '\0';
                return;
            } cout << "IdentStr::IdentStr(const char* Str):Stroka(Str)" << endl;
        }
    }

    const char* keyword[] = {
    "while",
    "continue",
    "switch",
    "extern",
    "/0"
    };
    //strcmp(...)
    //strhcmp(...)
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(pCh, keyword[i]) == 0)
        {
            IdentStr obj15("switch");
            cout << "" << endl;
        }
        else
        {
        }
        return;
    }

}
IdentStr& IdentStr::operator=(const IdentStr& S)
{
    if (&S != this)
    {
        delete[] pCh;
        len = strlen(S.pCh);
        pCh = new char[len + 1];
        strcpy_s(pCh, len + 1, S.pCh);
    }
    cout << "IdentStr& IdentStr::operator=(const IsentStr& S)" << endl;
    return *this;
}
char& IdentStr::operator[](int index)
{
    if (index >= 0 && index < len)
        cout << "char& IdentStr::operator[](int index)" << endl;
    return pCh[index];
}
//return pCh[0];
IdentStr::IdentStr(const IdentStr& from) : Stroka(from)
{
    cout << "" << endl;
}
IdentStr::~IdentStr()
{
    cout << "IdentStr::~IdentStr()" << endl;
}
IdentStr IdentStr::operator~()
{
    int i, j;
    char tmp;
    for (i = 0, j = len - 1; i < len / 2; i++, j--)
    {
        tmp = pCh[i];
        pCh[i] = pCh[j];
        pCh[j] = tmp;
    }
    cout << "IdentStr IdentStr::operator~()" << endl;
    return *this;
}
IdentStr operator + (const IdentStr& pobj1, const IdentStr& pobj2)
{
    IdentStr tmp(pobj1.GetLen() + pobj2.GetLen());
    int i = 0, j = 0;
    while (tmp.pCh[i++] = pobj1.pCh[j++]);
    strcpy_s(tmp.pCh, tmp.len + 1, pobj1.Getstr());

    --i;
    j = 0;
    while (tmp.pCh[i++] = pobj2.pCh[i++]);
    //strcat_s(tmp.pCh, tmp.len + 1, pobj2.Getstr());


    cout << "IdentStr operator+(...)" << endl;
    return tmp;
}
IdentStr operator + (const IdentStr& pobj1, const char* pobj2)
{
    IdentStr tmp(pobj1.GetLen() + (int)strlen(pobj2));
    strcpy_s(tmp.pCh, tmp.len + 1, pobj1.Getstr());
    strcat_s(tmp.pCh, tmp.len + 1, pobj2);
    cout << "..." << endl;
    return tmp;
}
IdentStr operator + (const char* pobj1, const IdentStr& pobj2)
{
    IdentStr tmp((int)strlen(pobj1) + pobj2.GetLen());
    strcpy_s(tmp.pCh, tmp.len + 1, pobj1);
    strcat_s(tmp.pCh, tmp.len + 1, pobj2.Getstr());
    cout << "..." << endl;
    return tmp;
}
int main()
{
    cout << fun1(65535) << endl;
    cout << "obj1.Getstr()" << endl;
    IdentStr obj5("_ITMO");
    IdentStr obj6 = obj5;
    IdentStr obj7 = "N3148";
    obj7.show();
    obj7 = "ITMO";
    obj7.show();
    IdentStr obj8("N3145");
    obj8 = obj7 = "FBIT";
    obj8.show();
    obj8[3] = 'X';
    cout << obj8[3] << endl;
    IdentStr obj10 = ~obj8;
    obj10.show();
    IdentStr obj20("N3148");
    IdentStr obj21("FBIT");
    obj20 = obj20 + obj21;
    obj20.show();
    IdentStr obj23("N3148");
    obj23 = obj23 + "FBIT";
    obj23.show();
};