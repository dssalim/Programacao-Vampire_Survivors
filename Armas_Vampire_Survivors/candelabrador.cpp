#include <iostream>
using std::ostream;
#include<string>
using std::string;
#include <map>
using std::iterator;
#include "candelabrador.h"

const string Candelabrador::ELEMENTS[NUM_ELEMENT] = {"Neutral","Fire","Ice","Earth","Light"};
const double  Candelabrador::ELEMENT_BONUS[NUM_ELEMENT]= {1,1.1,1.1,1.2,1.5};

ostream &operator<<(ostream &out, const Candelabrador &cande){
    out<<"=================================\n";
    out<<"Mostrando atributos do Candelabro:\n";
    out<<"Level: ";
    out<<cande.unique.level;
    out<<"\n";
    out<<"Bonus: ";
    out<<cande.unique.bonus;
    out<<"\n";
    out<<"Element: ";
    out<<cande.type_element;
    out<<"\n";
    out<<"Element Bonus: ";
    out<<cande.get_element_bonus();
    out<<"\n";
    out<<"Last time you played: ";
    cande.last_played_ptr->print();
    out<<"\n";
    out<<"=================================\n";

    return out;
}



Candelabrador::Candelabrador(int level):type_element("Neutral"){
    set_unique(level);
    last_played_ptr = 0;
    daily_play_bonus = 0;
    set_data();
    createmapelement();
}
Candelabrador::Candelabrador(string type_element){
    set_unique(1);
    last_played_ptr = 0;
    daily_play_bonus = 0;
    set_data();
    createmapelement();
    set_element(type_element);
}

Candelabrador::Candelabrador(const Candelabrador & old_one):type_element(old_one.type_element){
    set_unique(old_one.get_unique_level());
    last_played_ptr = 0;
    daily_play_bonus = 0;
    set_data();
    createmapelement();
}


Candelabrador::~Candelabrador(){
    delete [] last_played_ptr;
    for (auto i=0; i<dates.size()-1;i++) 
        delete this -> dates[i];
};


bool Candelabrador::operator==( const Candelabrador &cande_b){
   return this->unique.level==cande_b.get_unique_level()  && this->type_element ==cande_b.get_element();
    
}

bool Candelabrador::operator!=( const Candelabrador &cande_b){
   return this->unique.level != cande_b.get_unique_level()  || this->type_element != cande_b.get_element();
}



int Candelabrador::operator!( ){
    int lvl=1;   
    if (this->get_unique_level()<8){
        lvl=8;
        return lvl;}
    if(this->get_unique_level()==8){
        return lvl;
    }
    return 0;
}

void Candelabrador::operator=( const Candelabrador &cande_b){

    this->set_unique(cande_b.get_unique_level());
    this->set_element(cande_b.get_element());

}
void Candelabrador::set_unique(int level){
    if (level >= 1 && level <= 5){
        this -> unique.level = level;
        this -> unique.bonus = level*5;
        return;
    }
    if (level>5){
        this ->unique.level = 5;
        this ->unique.bonus = unique.level*5;
        return;
    }
    if (level<1){
        this ->unique.level = 1;
        this ->unique.bonus = unique.level*5;
        return;
    }

}

void Candelabrador::set_element(string element){
    if (checkelement(element)==false){
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

string Candelabrador::get_element() const{
    return type_element;
}

double Candelabrador::get_element_bonus() const{
    for(auto itr =map_elemet.begin(); itr!=map_elemet.end();++itr){
    if (this->type_element == itr->first){
            return itr->second;
    }
}
    return 0;
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



// Candelabrador &operator==(Candelabrador &cande_a, Candelabrador &cande_b){
//     if (cande_a.unique.level == cande_b.unique.level){
//         std::cout<<"Objetos com leveis iguais\n";
//     }
//    if (cande_a.unique.level > cande_b.unique.level){
//         std::cout<<"Primeiro objeto da Igualdade com level maior\n";
//         std::cout<<"Alterando nível do segundo objeto\n";
//         cande_b.set_unique(cande_a.unique.level);
//         std::cout<<"Nível alterado do segundo objeto\n";
//         std::cout<<"Mostrando  segundo Objeto\n";
//         std::cout<<cande_b;

//     }
//     if (cande_a.unique.level <cande_b.unique.level){
//         std::cout<<"Segundo objeto da Igualdade com level maior\n";
//         cande_a.set_unique(cande_b.unique.level);
//         std::cout<<"Nível alterado do primeiro objeto\n";
//         std::cout<<"Mostrando  primeiro Objeto\n";
//         std::cout<<cande_a;

//     }

// };





void Candelabrador::set_data(int dia, int mes, int ano){
    Data currentDate(dia, mes, ano);
    this -> currentDate = currentDate;
    save_date(currentDate);

}

void Candelabrador::save_date(Data data){
    this -> dates.push_back(new Data (currentDate));
    last_played_ptr = new Data ;
    last_played_ptr = dates[dates.size()-1];
    daily_play_bonus++;
}