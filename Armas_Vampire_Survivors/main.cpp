#include <iostream>
using std::cout;
#include "ax.h"
#include "tomahawk.h"
#include "deathscythe.h"

int main() {
// Testes de sobrecarga de Axe 
    Axe teste_axe(2);
    Axe teste_axe2(1,2,40,2,"Testinho");
    Axe teste_axe3(teste_axe2);
    cout<< "=========================================\n";
    cout<< "=========================================\n";
    cout<< "TESTES Axe\n";
    cout<<teste_axe;
    cout<<teste_axe2;
    cout<<teste_axe3;
    cout<< "Axes são iguais? "<<(teste_axe==teste_axe2)<<'\n';
    cout<<"Axes são iguais? "<<(teste_axe2==teste_axe3)<<'\n';
    cout<< "Axes são diferentes? "<<(teste_axe!=teste_axe2)<<'\n';
    cout<<"Axes são diferentes? "<<(teste_axe2!=teste_axe3)<<'\n';
    cout<<"Qual o nível maximo? "<<(!teste_axe)<<'\n';
    teste_axe3=teste_axe;
    cout<<teste_axe3;
    cout<<teste_axe3;
    
// Teste de Tomahawk. Construtores e Construtor de Cópia
    Tomahawk toma(1);
    Tomahawk toma2(1,2);
    Tomahawk toma3(toma2);
// Teste Sobrecargas de Tomahawk
    cout<< "=========================================\n";
    cout<< "=========================================\n";
    cout<< "TESTES TOMAHAWK\n";
    cout<<toma;
    cout<<toma2;
    toma=toma2;
    cout<<toma;
    toma.changeAxeName("Flying Tomahawk");
    cout<<toma;
    cout<< "Tomahawks são iguais? "<<(toma==toma2)<<'\n';
    cout<<"Tomahawks são iguais? "<<(toma2==toma3)<<'\n';
    cout<< "Tomahawks são diferentes? "<<(toma!=toma2)<<'\n';
    cout<<"Tomahawks são diferentes? "<<(toma2!=toma3)<<'\n';
    cout<<"Qual o nível maximo? "<<(!toma)<<'\n';

// Teste de DeathScythe. Construtores e Construtor de Cópia
    DeathScythe death(1);
    DeathScythe death2(1,1,100);
    DeathScythe death3(death2);
    cout<<death<<'\n';
    cout<<death2<<'\n';
    cout<<death3<<'\n';
// Teste Sobrecargas de DeathScythe
    cout<< "Death Scythes são iguais? "<<(death==death2)<<'\n';
    cout<<"Death Scythes são iguais? "<<(death2==death3)<<'\n';
    cout<< "Death Scythes são diferentes? "<<(death!=death2)<<'\n';
    cout<<"Death Scythes são diferentes? "<<(death2!=death3)<<'\n';
    cout<<"Qual o nível maximo? "<<(!death)<<'\n';
    return 0;
}