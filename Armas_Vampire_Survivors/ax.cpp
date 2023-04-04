#include <iostream>
using std::cout;

#include "ax.h"


Axe::Axe( int rarity , int number_projectiles,int level)
{

cout << "Inicializando Axe.\n";

setLevel(level);

setNumber_projectiles(number_projectiles);

setRarity(rarity);

setBase_damage(base_damage);

}


Axe::Axe(double base_damage, int rarity , int number_projectiles,int level){

setLevel(level);

setNumber_projectiles(number_projectiles);

setRarity(rarity);

setBase_damage(base_damage);


}



Axe::~Axe( )
{  

}

void Axe::throwAxe( ) const
{
    cout << "Arremessando Machados\n";
    cout << "Machados Arremessados: "   << getNumber_projectiles() << '\n';
    cout << "Dano Causado: " << getBase_damage()<<'\n';
    cout << "Nivel: "<< getLevel()<<'\n';
    cout << "Raridade: "<< getRarity()<<'\n';

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

int Axe::getNumber_projectiles( ) const
{
    return number_projectiles;
}


// As formulas para calculo dos atributos dependendem do level da arma



void Axe::setBase_damage(double base_damage){ 

    if ((base_damage*getLevel() > 0) && (base_damage*getLevel()<=180)){
    this -> base_damage = base_damage*getLevel();}
    else{ this -> base_damage = 20*getLevel();}
    return;
    }

void Axe::setNumber_projectiles (int number_projectiles){

    if (number_projectiles*getLevel()> 0 && number_projectiles*getLevel() <= 8){
    this -> number_projectiles = number_projectiles*getLevel();
    }
    else if (number_projectiles*getLevel() > 8){this -> number_projectiles =8 ;}
    else{this -> number_projectiles = 1;}
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

