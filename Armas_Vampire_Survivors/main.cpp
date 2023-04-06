#include <iostream>
#include "ax.h"


using std::cout;

int main() {
// Testando construtor com 1 dado de entrada(level)
    cout<<"teste 1\n";
    Axe axe(2)  ;
    axe.throwAxe();
    cout<<'\n';
// Testando sets

    cout<<"teste 2\n";
    axe.setLevel(1);
    axe.setBase_damage(30);
    axe.setNumber_projectiles(7);
    axe.setRarity(60);
    axe.throwAxe();
 // Testando construtor testando formula dos níveis
    cout<<'\n';
    cout<<"teste 3\n";
    axe.setLevel(2);
    axe.setBase_damage(45);
    axe.setNumber_projectiles(3);    
    axe.throwAxe();
    cout<<'\n';
    
    cout<<"teste 4\n";
    axe.setLevel(3);
    axe.throwAxe();
    cout<<'\n';
    cout<<"teste 5\n";
    axe.setLevel(5);
    axe.throwAxe();
    cout<<"\n";
// Testando construtor com dados de entrada
    double damage=30;
    int lvl=3,rar=75,num=2;
    cout<<"teste 6\n";
    Axe custom_axe(lvl,rar,num,damage);
    custom_axe.throwAxe();
    cout<<'\n';

// Testando segundo construtor com dados de entrada
    cout<<"teste 7\n";
    Axe new_custom_axe(lvl, rar);
    new_custom_axe.throwAxe();

    cout<<"teste 8\n";
    Axe another_teste_axe;
    another_teste_axe.throwAxe();
    return 0;
}