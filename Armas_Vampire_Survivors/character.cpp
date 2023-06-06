#include <iostream>
#include "character.h"


ostream &operator<<(ostream &out, const Character &chara){
    out<<"=================================\n";
    out<<"Mostrando atributos do Personagem:\n";
    out<<"Level: ";
    out<<chara.unique.level;
    out<<"\n";
    out<<"Ataque: ";
    out<<chara.unique.attack;
    out<<"\n";
    out<<"Nome do Personagem: ";
    out<<chara.character_name;
    out<<"\n";
    out<<"Nomes Anteriores: \n";
    for (auto i =0; i<chara.previous_character_name.size();i++){
        out<<*chara.previous_character_name[i]<<'\n';
    }
    out<<"=================================\n";

    return out;
}

bool Character::operator==( const Character &chara_b){
    return this->unique.level == chara_b.unique.level;
}

bool Character::operator!=( const Character &chara_b){
    return this->unique.level != chara_b.unique.level;
}

int Character::operator!( ){
    int level=1;
    if(this->unique.level!=100){level=100;}
    return level;
}

void CopyCharac( Character&chara_a,const Character&char_b){
    if(chara_a==char_b){return;}
    if(chara_a!=char_b){chara_a=char_b;return;}
}

void MaxLevel(Character& Character){
    Character.SetUnique( !Character);
} 

void Character::operator=(const Character &another){
    SetUnique(another.unique.level);

}
Character::Character(int level):character_name("no name"){

    SetUnique(level);

}

Character::Character(string character_name){
    SetUnique();
    SetCharacterName(character_name);
}

Character::Character(const Character & another){
    SetUnique(another.unique.level);
    SetCharacterName(another.character_name);
}

Character::~Character(){
    for(auto i =0; previous_character_name.size(); i++)
        delete this->previous_character_name[i];
}


void Character::SetUnique(int level){
    if(level>=1 && level<=100){
    this->unique.level = level;
    this->unique.attack = 2*level;
    this->unique.exp = 40*level;
    return;}
    if(level<1){
    level = 1;
    this->unique.level = level;
    this->unique.attack = 2*level;
    this->unique.exp = 40*level;
    return;}
    if(level>100){
    level = 1;
    this->unique.level = level;
    this->unique.attack = 2*level;
    this->unique.exp = 40*level;
    return;}
}

void Character::SetCharacterName(string character_name){
    this->character_name=character_name;

}

double Character::GetUniqueAttack() const{
    return unique.attack;
}
void Character::SaveCharacterNames(const string& character_name){
    this->previous_character_name.push_back(new string(character_name));
}

void Character::ChangeCharacName(const string& character_name){
    SaveCharacterNames(character_name);
    SetCharacterName(character_name);   
}

