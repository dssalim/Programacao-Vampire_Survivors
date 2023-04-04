#include <iostream>
#include "ax.h"


using std::cout;

int main() {
// Testando construtor com os valores default
    Axe axe ;
    axe.throwAxe();
    cout<<'\n';
    axe.setLevel(1);
    axe.setBase_damage(50);
    axe.setNumber_projectiles(7);
    axe.setRarity(500);
   axe.throwAxe();
 // Testando construtor testando formula dos níveis
    cout<<'\n';
    axe.setLevel(2);
    axe.throwAxe();
    cout<<'\n';
 
    axe.setLevel(3);
    axe.throwAxe();
    cout<<'\n';
 
    axe.setLevel(5);
    axe.throwAxe();
    cout<<'\n';
// Testando construtor com dados de entrada
    double damage=30;
    int lvl=3,rar=100,num=2;

    Axe custom_axe(damage,rar,num,lvl);
    custom_axe.throwAxe();
    cout<<'\n';

// Testando segundo construtor com dados de entrada

    Axe new_custom_axe(22,2,2);
    new_custom_axe.throwAxe();
    return 0;
}