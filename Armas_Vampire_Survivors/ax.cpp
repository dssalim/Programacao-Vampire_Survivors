#include <iostream>
using std::cout;

#include "ax.h"


Axe::Axe(int level)
{

    cout << "Inicializando Axe.\n";

    setLevel(level);
    setNumber_projectiles(number_projectiles);
    setRarity(rarity);
    setBase_damage(base_damage);
}


Axe::Axe(int level,  int rarity , double base_damage, int number_projectiles)
{

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



void Axe::setBase_damage(double nbase_damage){ 
    if ((nbase_damage*getLevel() > 0) && (nbase_damage*getLevel()<=180)){
        this -> base_damage = nbase_damage*getLevel();
        return;}
    this -> base_damage = 20*getLevel();}


void Axe::setNumber_projectiles (int number_projectiles){

    if (number_projectiles*getLevel()> 0 && number_projectiles*getLevel() <= 8){
        this -> number_projectiles = number_projectiles*getLevel();
        return;
    }

    this -> number_projectiles = 1;}

void Axe::setLevel(int level=1){

    if ( level>= 1 && level< 9){

        this -> level = level;


        return;
    }
    if (level>=9){

        this -> level = 8;

        return;
    }

    this -> level = 1;


    }



void Axe::setRarity(int nrarity){

    if (nrarity>=10 && nrarity<=100){
        nrarity=nrarity;
    }
    if (nrarity>100 || nrarity<10){
        nrarity=100;}

    this -> rarity = nrarity;}



