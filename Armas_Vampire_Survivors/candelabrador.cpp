#include <iostream>
using std::ostream;
#include<string>
using std::string;
#include <map>
using std::iterator;
#include "candelabrador.h"

const string Candelabrador::ELEMENTS[NUM_ELEMENT] = {"Neutral","Fire","Ice","Earth","Light"};
const double  Candelabrador::ELEMENT_BONUS[NUM_ELEMENT]= {1,1.1,1.1,1.2,1.5};



Candelabrador::Candelabrador(int level):type_element("Neutral"){
    set_unique(level);
    set_data();
    createmapelement();
}
Candelabrador::Candelabrador(string type_element){
    set_unique(1);
    set_data();
    createmapelement();
}

Candelabrador::Candelabrador(const Candelabrador & old_one):type_element(old_one.type_element){
    set_unique(old_one.get_unique_level());
    set_data();
    createmapelement();
}


Candelabrador::~Candelabrador(){
    for (auto i=0; i<dates.size();i++)
        delete this -> dates[i];

};

void Candelabrador::set_unique(int level){
    if (level >= 1 && level <= 5){
        this -> unique.level = level;
        this -> unique.bonus = level*5;
        return;
    }
    if (level<5){
        this ->unique.level = 5;
        this ->unique.bonus = unique.level*5;
        return;
    }
    if (level>1){
        this ->unique.level = 1;
        this ->unique.bonus = unique.level*5;
        return;
    }

}

void Candelabrador::set_element(string element){
    if (checkelement(element)==true){
        element = ELEMENTS[1];
    }
    this->type_element=element;

}

int Candelabrador::get_unique_level() const{
    return unique.level;
}

double Candelabrador::get_unique_bonus() const{
    return unique.bonus;
}

void Candelabrador::createmapelement(){
    for (auto i =0; i<NUM_ELEMENT;i++){
        map_elemet.insert(std::pair<string,double>(ELEMENTS[i],ELEMENT_BONUS[i]));
    }
}

bool Candelabrador::checkelement(string element){
    for(auto itr =map_elemet.begin(); itr!=map_elemet.end();++itr){
        if (element == itr->first){
            return true;
        }
    }
    return false;
}

void Candelabrador::set_data(int dia, int mes, int ano){
    Data currentDate(dia, mes, ano);
    this -> currentDate = currentDate;
    this -> dates.push_back(new Data (currentDate));

}

void Candelabrador::printdata() const{
    for(auto i =0; i<dates.size();i++)
        dates[i] -> print();

}

ostream &operator<<(ostream &out, const Candelabrador &cande){
    out<<"=================================\n";
    out<<"Mostrando atributos do Candelabro:\n";
    out<<"Level: ";
    out<<cande.unique.level;
    out<<"\n";
    out<<"Bonus: ";
    out<<cande.unique.bonus;
    return out;
}