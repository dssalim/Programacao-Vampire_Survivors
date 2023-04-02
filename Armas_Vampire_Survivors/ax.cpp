#include <iostream>
using std::cout;

#include "ax.h"

Axe::Axe( double base_damage,int rarity, int number, int level)
{

cout << "Inicializando Axe.\n";

setLevel(level);

setNumber(number);

setRarity(rarity);

setBase_damage(base_damage);

}
Axe::Axe(int rarity ,int level, int number,double base_damage){

setLevel(level);

setNumber(number);

setRarity(rarity);

setBase_damage(base_damage);


}

Axe::~Axe( )
{  

}


double Axe::getBase_damage( ) const
{
    return base_damage;
}

int Axe::getLevel( ) const
{
    return level;
}

int Axe::getRarity( ) const
{
    return rarity;
}

int Axe::getNumber( ) const
{
    return number;
}


// As formulas para calculo dos atributos dependendem do level da arma



void Axe::setBase_damage(double base_damage){    
    if ((base_damage*Axe::getLevel() > 0) && (base_damage*Axe::getLevel()<=180)){
    this -> base_damage = base_damage*Axe::getLevel();}
    else{ this -> base_damage = 20*Axe::getLevel();}
    return;
    }

void Axe::setNumber (int number){
    int newnumber;
    newnumber = number*Axe::getLevel();
    if (newnumber > 0 && newnumber <= 8){
    this -> number = newnumber;
    }
    else if (newnumber > 8){this -> number =8 ;}
    else{this -> number = 1;}
return;}

void Axe::setLevel(int level){

    if ( level>= 1 && level< 9){

        this -> level = level;


        return;
    }
    else if (level>=9){

        this -> level = 8;

        return;
    }
    else{

        this -> level = 1;

        return;
    }

}

void Axe::setRarity(int rarity){
    int newrarity;
    newrarity = rarity;
    if (newrarity>10 && newrarity<=100){
        this -> rarity = newrarity;
    }
    else if(newrarity>100 ) {this -> rarity =100;}
    else {this -> rarity =10;}

}

void Axe::throwAxe( ) const
{
    cout << "Arremessando Machados\n";
    cout << "Machados Arremessados: "   << Axe::getNumber() << '\n';
    cout << "Dano Causado: " << Axe::getBase_damage()<<'\n';
    cout << "Nivel: "<< Axe::getLevel()<<'\n';
    cout << "Raridade: "<< Axe::getRarity()<<'\n';

}
