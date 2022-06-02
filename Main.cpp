#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Stroka.h"
#include "Decstr.h"
#include "Identstr.h"
//#include <lstring.h>
using namespace std;

int main()
{
    Stroka obj("FBIT");
    Stroka obj1 = obj;
    obj1.show();
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


    //obj45 = "N3148" + obj45+"N3148";
   //obj45.show();
    DecStr obj35('9');
    obj35.show();
    DecStr obj36('+');
   // DecStr obj33("05535");
    DecStr obj51("+65535");
    DecStr obj52("1024");
    obj51 = obj52 = "255";
    obj51.show();
    DecStr obj61("65535");
    DecStr obj62("65535");
    obj61 = obj61 + obj62;
    obj61.show();
};
