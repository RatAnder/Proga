#pragma once
#ifndef __DECSTR__
#define __DECSTR__
class DecStr :public Stroka
{
public:
    DecStr(int = 0);
    DecStr(const DecStr* Str);
    DecStr(char val);
    //DecStr(char);
    DecStr(const char*);
    DecStr(const DecStr&);
    ~DecStr();
    DecStr& operator=(const DecStr&);
    friend DecStr operator+(const DecStr&, const DecStr&);
    friend DecStr operator+(const DecStr&, const int);
    friend DecStr operator+(const int, const DecStr&);
};
#endif // !__DECSTR__
