#include <iostream>
#include "headerElGamal.h"

using namespace std;
void implementElGamal(){
    int opcion;
    string mensaje="Nos movemos entre las sombras para servir a la luz somos asesinos";
    ZZ e1,e2,p;
    string c2;
    gamal receptor(16);
    while(true){
        cout<<"Quiere decifrar presione 1: "<<endl;
        cout<<"Quiere cifrar presione 2: "<<endl;
        cin>>opcion;
        if(opcion==1){
            cout<<"Ingrese el c2: "<<endl;
            cin>>c2;
            cout<<"Mensaje decifrado: "<<receptor.decifrar(c2)<<endl;
            cout<<"preciones 0 para continuar"<<endl;
            cin>>opcion;
        }else if(opcion==2){
            cout<<"Ingrese e1: "<<endl;
            cin>>e1;
            cout<<"Ingrese e2: "<<endl;
            cin>>e2;
            cout<<"Ingrese p: "<<endl;
            cin>>p;
            gamal emisor(e1,e2,p);
            emisor.cifrar(mensaje);
            cout<<"preciones 0 para continuar"<<endl;
            cin>>opcion;
        }else{
            cout<<"Ingrese una opcion valida"<<endl;
            cout<<"preciones 0 para continuar"<<endl;
            cin>>opcion;
        }
    }
}
int main()
{
    implementElGamal();
    cout << "Hello world!" << endl;
    return 0;
}
