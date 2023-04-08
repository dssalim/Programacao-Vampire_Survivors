#include <iostream>
using std::cout;

#include "ax.h"

//atributos static
int Axe::numberaxes=0;
int Axe::numcopies=0;

//atributos const static
const string Axe::GRADEAXE[NUMGRADES] = {"S","A","B","C"};

// Métodos Static
int Axe::getNumberAxes(){
    return numberaxes;
}
int Axe::getNumCopies(){return numcopies;}

// Construtores com atributos Const
Axe::Axe(int level):
    axename("no name"),namechanges(0),graded(false),MAXCHANGES(1),MAXRARITY(100),MINDAMAGE(20)
{

        cout << "Inicializando Axe.\n";

        setLevel(level);
        setNumber_projectiles(number_projectiles);
        setRarity(rarity);
        setBase_damage(base_damage);
        numberaxes++;


}



Axe::Axe(int level,   int rarity , double base_damage, int number_projectiles, string name, int MAXCHANGES):
   axename(name), namechanges(0), graded(false),MAXCHANGES(MAXCHANGES), MAXRARITY(100),MINDAMAGE(20)
{

    setLevel(level);
    setNumber_projectiles(number_projectiles);
    setRarity(rarity);
    setBase_damage(base_damage);
    numberaxes++;


}



// Construtor de cópia
Axe::Axe (const Axe & another ):
    namechanges(0), graded(false),MAXRARITY(another.MAXRARITY),MINDAMAGE(another.MINDAMAGE),MAXCHANGES(another.MAXCHANGES){
        this ->level = another.level;
        this -> rarity = another.rarity;
        this -> base_damage = another.base_damage;
        this -> number_projectiles = another.number_projectiles;
        this -> axename = another.axename;
        numberaxes++;
        numcopies++;

}


Axe::~Axe( )
{  
}
// Throw Axe foi alterado para exibir o nome
void Axe::throwAxe( ) const
{
    cout << "\nArremessando Machados\n";
    cout << "Machados Arremessados: "   << getNumber_projectiles() << '\n';
    cout << "Dano Causado: " << getBase_damage()<<'\n';
    cout << "Nivel: "<< getLevel()<<'\n';
    cout << "Raridade: "<< getRarity()<<'\n';
    cout << "Nome do Machado: " <<getAxeName()<<'\n';

}

string Axe::gradingAxe()const
{
    double total;
    total= getNumber_projectiles()*getBase_damage()*getLevel();
    if (total>=10000){
        return GRADEAXE[0];
  }
    if (total>=8000){
        return GRADEAXE[1];
  }
    if (total>=5000){
        return GRADEAXE[2];
  }
    return GRADEAXE[3];

}

void Axe::gradeAxe(bool graded) const{
    if (!graded){return;}

    cout<<"A nota do seu machado é: \n"<<gradingAxe()<<'\n';



}


void Axe::gradeAxe(bool graded){
    this -> graded = graded;
    if (!this->graded){return;}
    
    cout<<"A nota do seu machado é: \n"<<gradingAxe()<<'\n';



}

void Axe::changeAxeName (const string &nname ){

    if(getNameChanges()<=getMAXCHANGES()){
        setAxeName(nname);
        setNameChanges();
        return;
        }
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

string Axe::getAxeName() const{
    return axename;
}

int Axe::getNameChanges()const{
    return namechanges;
}

// Métodos Get Const

int Axe::getMAXRARITY() const{
    return MAXRARITY;
}

double Axe::getMINDAMAGE() const{
    return MINDAMAGE;
}


int Axe::getMAXCHANGES() const{
    return MAXCHANGES;
}

// As formulas para calculo dos atributos dependendem do level da arma

// Métodos ajustados para utilizar os métodos const dos atributos const


void Axe::setBase_damage(double nbase_damage){ 
    if (nbase_damage<getMINDAMAGE()){nbase_damage=getMINDAMAGE();}
    if ((nbase_damage*getLevel() > 0) && (nbase_damage*getLevel()<=180)){
        this -> base_damage = nbase_damage*getLevel();
        return;}
    this -> base_damage = nbase_damage*getLevel();}


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

    if (nrarity>=10 && nrarity<=getMAXRARITY()){
        nrarity=nrarity;
    }
    if (nrarity>getMAXRARITY() || nrarity<10){
        nrarity=getMAXRARITY();}

    this -> rarity = nrarity;}



void Axe::setAxeName (string nname){
    this -> axename=nname;
}

void Axe::setNameChanges(){
    this -> namechanges +=1;
}

