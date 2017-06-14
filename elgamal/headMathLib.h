#include <iostream>
#include <NTL/ZZ.h>
#include <NTL/vector.h>
#include <chrono>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <math.h>
using namespace std;
using namespace NTL;
class mathLib{
public:
    mathLib();
    ZZ getMod(ZZ d,ZZ a);
    int getModInt(int a, int b);
    ZZ algEuclides(ZZ a, ZZ b);
    ZZ algEuclidesExt(ZZ a, ZZ b);
    ZZ MulMod(ZZ a, ZZ b, ZZ mod);
    ZZ Inversa(ZZ a,ZZ l);
    ZZ genetareRandom(int tamSeed, int tamNum, int numPart, int loops);
    bool testMiller(ZZ pseudoPrime,int numTest);
    ZZ modularExpo(ZZ a, ZZ b,ZZ m);
    bool fermatTest(int numTests,ZZ pseudoPrime);
    ZZ chineseReminder(vector<ZZ> ai,vector<ZZ> pi,ZZ n,ZZ i);
    ZZ fingGen(ZZ p);
};
