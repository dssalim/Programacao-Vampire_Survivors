#include <iostream>
#include <cstdlib>
using std::cout;

#include "ax.h"

//atributos static
int Axe::numberaxes=0;
int Axe::numcopies=0;

//atributos const static
const string Axe::GRADEAXE[NUMGRADES] = {"S","A","B","C"};

// array const static

const float Axe::FIXED_BONUS_DAMAGE[NUMGRADES] = {1.5,1.2,1,0.9};

// Métodos Static
int Axe::getNumberAxes(){
    return numberaxes;
}
int Axe::getNumCopies(){return numcopies;}


// Construtores com atributos Const
Axe::Axe(int level):
    axename("no name"),namechanges(0),graded(false),MAXCHANGES(5),MAXRARITY(100),MINDAMAGE(20)
{

        cout << "Inicializando Axe.\n";

        setLevel(level);
        setNumber_projectiles(number_projectiles);
        setRarity(rarity);
        setBase_damage(base_damage);
        numberaxes++;

}



Axe::Axe(int level,   int rarity , double base_damage, int number_projectiles, string name):
   axename(name), namechanges(0), graded(false),MAXCHANGES(5), MAXRARITY(100),MINDAMAGE(20)
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
// Métodos para gerar a Nota do Machado
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

// Métodos para gerar nota de objetos const
void Axe::gradeAxe(bool graded) const{
    if (!graded){return;}

    cout<<"A nota do seu machado é: \n"<<gradingAxe()<<'\n';

}

// Métodos para Gerar a nota de Objetos non Const
void Axe::gradeAxe(bool graded){
    this -> graded = graded;
    if (!this->graded){return;}
    
    cout<<"A nota do seu machado é: \n"<<gradingAxe()<<'\n';



}
// Método changeAxeName alterado para verificar se o nome já foi usado.
void Axe::changeAxeName (const string &nname ){
    if (namechanges==0){
        setAxeName(nname);
        return;
    }
    if (namechanges>0){
        bool teste=false;
        for (int i =0; i<=namechanges;i++){
            if(nname==previousAxeNames[i] || nname==axename){
            cout<<"o nome " << nname <<" já foi usado\n";
            teste=true;
            return;
            }
        }

        if(namechanges<=getMAXCHANGES() && teste==false){
            setAxeName(nname);
            return;
        }
 
    }
} 

// Método com while para verificar o bonus do machado de acordo com a nota

float Axe::checkbonus(){
    int contador=0;
    string grade = gradingAxe();

    while(grade != GRADEAXE[contador]){
        contador++;
    }

    return FIXED_BONUS_DAMAGE[contador];
}

// Calculo dano
float Axe::calculate_damage(){
    
    float final_damage = getBase_damage()*checkbonus();
    return final_damage;

}

// Simulador de batalha usando for e while para criar dummies

void Axe::simulate_battle(int numdummies){

    for (int i=0;i<numdummies;i++){
        float temp_dummy= rand() % 50 + 300;
        cout << "\nO hp do dummy  "<< i+1 <<" é de:"<<temp_dummy;
        while(temp_dummy>0){ 
            cout<<"\nDano causado ao dummy: "<< calculate_damage();
            temp_dummy -= calculate_damage();
            if( temp_dummy>0){cout<<"\nHp atual do dummy: " << temp_dummy;}
            cout<<"\nHp atual do dummy: 0 ";
        }
        cout << "\nDummy derrotado\n";
    }
}

// imprimir nomes anteriores usando for

void Axe::printPreviousName(){
    cout << "Nomes anteriores:\n";
    cout << previousAxeNames[2];
    for(int i = 0; i<namechanges; i++ ){
        cout << previousAxeNames[i]<<'\n';
    }
}

// métodos get 

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

    this -> rarity = nrarity;
}


// Método setAxeName alterado para salvar os nomes em um array
void Axe::setAxeName (string axename){

    if( namechanges ==  0 )
    {   
        this->axename = axename;
        namechanges++;
        return;
    }
    if( namechanges <  MAXNUMCHANGES ){
        previousAxeNames[ namechanges-1] = this->axename;
        namechanges++;
        this->axename = axename;}
    
}


