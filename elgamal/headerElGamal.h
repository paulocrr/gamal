#include<string>
#include<NTL/ZZ.h>
#include"headMathLib.h"
#include<sstream>
class gamal{
private:
    ZZ p,d,e1,e2,r;
    string alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    int longitud = alfabeto.length();
public:
    gamal(int bits);
    gamal(ZZ e_1,ZZ e_2, ZZ p_0);
    string cifrar(string mensaje);
    string decifrar(string mensaje);
    void generarClaves(int bits);
};
