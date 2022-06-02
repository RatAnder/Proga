//#pragma once
#ifndef __STROKA__
#define __STROKA__
#include <iostream>

class Stroka
{
protected:
    int len;
    char* pCh;
public:
    Stroka(int = 0);
    Stroka(char);
    Stroka(const char*);
    Stroka(const Stroka&);
    ~Stroka();
    char* Getstr(void)const { return pCh; }
    int GetLen(void)const { return len; }
    void show();
};
#endif // !__STROKA__