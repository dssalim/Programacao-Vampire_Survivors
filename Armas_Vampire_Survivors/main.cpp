#include <iostream>
#include "ax.h"


using std::cout;

int main() {

    Axe axe ;
    axe.throwAxe();
    cout<<'\n';
    axe.setBase_damage(50);
    axe.setNumber(8);
    axe.setRarity(500);
    axe.setLevel(2);
    axe.throwAxe();
    cout<<'\n';
    axe.setLevel(1);
    axe.throwAxe();
    cout<<'\n';
 
    axe.setLevel(3);
    axe.throwAxe();
    cout<<'\n';
 
    axe.setLevel(5);
    axe.throwAxe();
    cout<<'\n';
    double damage=30;
    int lvl=3,rar=100,num=3;

    Axe custom_axe(rar,lvl,num,damage);
    custom_axe.throwAxe();
    return 0;
}