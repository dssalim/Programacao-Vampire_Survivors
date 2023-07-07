#include <iostream>
#include "deathscythe.h"
#include "tomahawk.h"
using std::ostream;

DeathScythe::DeathScythe(int level):Tomahawk(level){
    this->final_bonus = 300;
};

DeathScythe::DeathScythe(int level, int delay, double final_bonus):Tomahawk(level, delay){
    this->final_bonus = final_bonus;
};


DeathScythe::DeathScythe(DeathScythe& other):Tomahawk(other){
    this->final_bonus = other.final_bonus;
};

DeathScythe::~DeathScythe(){};

const DeathScythe DeathScythe::operator=(const DeathScythe& other){
    *static_cast <Tomahawk *> (this) = static_cast < Tomahawk> (other);
    this->final_bonus = other.final_bonus;

    return *this;
}
const bool DeathScythe::operator==(DeathScythe& other){
    if (this->final_bonus==other.final_bonus && *static_cast < Tomahawk *> (this) == static_cast < Tomahawk > (other)){
        return true;
    }

    return false;
};
const bool DeathScythe::operator!=(DeathScythe& other){
    if (this->final_bonus!=other.final_bonus || *static_cast < Tomahawk *> (this) != static_cast < Tomahawk > (other)){
        return true;
    }

    return false;
};

int DeathScythe::operator!(){
    return !*static_cast < Tomahawk *> (this);
};

ostream &operator<<(ostream & out, const DeathScythe & other){
    out << static_cast <Tomahawk> (other)<<'\n';
    out<< "Atributos Death Scythe\n";
    out<< "Final Bonus " <<other.final_bonus<<'\n';
    return out;
};

double DeathScythe::get_final_bonus() const{
    return final_bonus;
};

void DeathScythe::simulate_battle_death(int numdummies){

    for (int i=0;i<numdummies;i++){
        float temp_dummy= rand() % 50 + 600;
        std::cout << "\nO hp do dummy  "<< i+1 <<" é de:"<<temp_dummy;
        while(temp_dummy>0){ 
            std::cout<<"\nDano causado ao dummy: "<< calculate_damage();
            temp_dummy -= calculate_damage() + get_final_bonus();
            if( temp_dummy>0){std::cout<<"\nHp atual do dummy: " << temp_dummy;}
            if (temp_dummy==0){std::cout<<"\nHp atual do dummy: 0 ";}
        }
        std::cout << "\nDummy derrotado\n";
    }
}