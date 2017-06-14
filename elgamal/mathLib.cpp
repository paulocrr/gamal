#include "headMathLib.h"

mathLib::mathLib(){}

ZZ mathLib::getMod(ZZ d, ZZ a){
    ZZ q,r;
    q = d/a;
    r = d-(q*a);
    if(r<0){
        r+=a;
    }
    return r;
}

ZZ mathLib::algEuclides(ZZ a, ZZ b){
    ZZ m;
    m = getMod(a,b);
    while(m!=0){
        a=b;
        b=m;
        m=getMod(a,b);
    }
    return b;
}

ZZ mathLib::algEuclidesExt(ZZ a, ZZ b){
    ZZ x,y,x2,x1,y2,y1,q,r;
    if(b==0){
        x2=1;
    }else{
        x=0;
        y=0;
        x1=0;
        x2=1;
        y2=0;
        y1=1;
        q=0;
        r=0;
        while(b!=0){
            q = a/b;
            r=getMod(a,b);
            x=x2-q*x1;
            y=y2-q*y1;
            a=b;
            b=r;
            x2=x1;
            x1=x;
            y2=y1;
            y1=y;
        }
    }
    return x2;

}

ZZ mathLib::Inversa(ZZ a,ZZ l){
    a = algEuclidesExt(a,l);
    if(a<0){
        a = a+l;
    }else if(a>=l){
        a=getMod(a,l);
    }
    //cout<<"Inversa: "<<a<<endl;
    return a;
}
int mathLib::getModInt(int d,int a){
    int q = d/a;
    int r = d-(q*a);
    if(r<0){
        r+=a;
    }
    return r;
}
void shiftLeft(vector<bool> &a,int inicio,int fin){
    bool val;
    val = a[inicio];
    a.erase(a.begin());
    a.insert(a.begin()+fin,val);
}
void shiftRight(vector<bool> &a,int inicio,int fin){
    bool val;
    val = a[fin];
    a.erase(a.begin()+fin);
    a.insert(a.begin()+inicio,val);
}
ZZ mathLib::genetareRandom(int sizeSeed,int sizeNumber,int numPar,int loops){
    vector<bool> seed;
    bool control = 1;
    int ini,increment,fin;
    ZZ res;
    ini = 0;
    long n = 0;
    res = 0;
    int l = 2;
    increment = sizeNumber/numPar;
    if(getModInt(sizeNumber,numPar)!=0){
        increment+=1;
    }
    fin = increment-1;

    for(int i = 0;i<sizeSeed;i++){
        int * foo;
        foo = new  int [1];
        int val = getModInt((*foo)+(time(0)),2);
        seed.push_back(val);
        delete[] foo;

    }
    for(int i = 0;i<sizeNumber;i++){
        int temp;
        temp = seed[i]+seed[i+1];
        if(temp>=2){
            temp = getModInt(temp,l);
        }
        seed.push_back(temp);
    }
    for(int j = 0;j<numPar;j++){
        for(int k = 0 ;k<loops;k++){
            if(control){
                shiftLeft(seed,ini,fin);
            }else{
                shiftRight(seed,ini,fin);
            }
            control = !control;
        }

        ini+=increment;
        fin+=increment;
        if(fin>=seed.size()){
            fin = seed.size()-1;
        }
    }
    seed[sizeNumber-1]=1;
    for (int i = sizeNumber;i>=1;i--){
        if (seed[i-1]){
            res+=power2_ZZ(n);
        }
        n = n + 1;
    }
    //cout<<res<<endl;
    return res;

}
ZZ mathLib::MulMod(ZZ a, ZZ b, ZZ mod){
    ZZ x,y,c;
    c=2;
    x = 0;
    y = getMod(a,mod);
    while (b > 0)
    {
        if (getMod(b,c) == 1)
        {
            x = getMod((x + y),mod);
        }
        y = getMod((y * c),mod);
        b = b/c;
    }
    return getMod(x,mod);
}
bool mathLib::testMiller(ZZ pseudoPrime,int iteration){
    ZZ s,a,temp,mod,c;
    c=2;
    if (pseudoPrime < c)
    {
        return false;
    }
    if (pseudoPrime != c && getMod(pseudoPrime,c)==0)
    {
        return false;
    }
    s = pseudoPrime - 1;
    while (getMod(s,c) == 0)
    {
        s /= 2;
    }
    for (int i = 0; i < iteration; i++)
    {
        a =getMod(genetareRandom(16,1024,16,8),(pseudoPrime - 1)) + 1;
        temp = s;
        mod = modularExpo(a, temp, pseudoPrime);
        while (temp != pseudoPrime - 1 && mod != 1 && mod != pseudoPrime - 1)
        {
            mod = MulMod(mod, mod, pseudoPrime);
            temp *= 2;
        }
        if (mod != pseudoPrime - 1 && getMod(temp,c) == 0)
        {
            return false;
        }
    }
    return true;

}

ZZ mathLib::modularExpo(ZZ a,ZZ b, ZZ m){
    ZZ ans,c;
    ans =1;
    c=2;
    while(b !=0 ) {
        if(getMod(b,c) == 1) {
            ans = getMod(ans*a,m);
        }
        a = getMod(a*a,m);
        b = b/2;
    }
    return ans;
}

bool mathLib::fermatTest(int numTests,ZZ pseudoPrime){
    mathLib m;
    ZZ a,c;
    c=1;
    if(pseudoPrime==2){
        return 1;
    }
    for(int i = 0;i< numTests;i++){
        a = m.genetareRandom(16,1024,16,8);
        if(a>=pseudoPrime){
            a=m.getMod(a,pseudoPrime);
        }
        if(m.modularExpo(a,(pseudoPrime-c),pseudoPrime)==1){
            return 1;
        }
    }
    return 0;
}
ZZ mathLib::chineseReminder(vector<ZZ> ai,vector<ZZ> pi,ZZ n,ZZ k){
    mathLib m;
    ZZ p,mi,inv,res,temp;
    res=0;
    p=1;
    long i=0;
    for(i=0;i<pi.size();i++){
        p *= pi[i];
    }
    for(i=0;i<pi.size();i++){
        mi = p/pi[i];
        inv = m.Inversa(mi,pi[i]);
        temp=ai[i]*inv;/**mi*/
        if(temp>=p){
            temp = m.getMod(temp,p);
        }
        temp = temp * mi;
        if(temp>=p){
            temp = m.getMod(temp,p);
        }
        if(temp>=p){
            temp = m.getMod(temp,p);
        }
        res+=temp;
        if(res>=p){
            res=m.getMod(res,p);
        }
    }
    res = res + n*k;
    return res;
}
ZZ mathLib::fingGen(ZZ p){
    ZZ g,c,q;
    q=(p-1)/2;
    c=2;
    for(int i=1;i<p-1;i++){
        g=i;
        if((modularExpo(g,c,p)!=1)&&(modularExpo(g,q,p)!=1)){
            return g;
        }
    }
    return g;


}
