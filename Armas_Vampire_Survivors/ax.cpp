#include <iostream>
#include <cstdlib>
using std::cout;
#include <map>
using std::iterator;
#include <vector>
#include "ax.h"
#include<algorithm>
#include<cmath>


//atributos static
int Axe::numberaxes=0;
int Axe::numcopies=0;

//atributos const static
const string Axe::GRADEAXE[NUMGRADES] = {"S","A","B","C"};

// array const static

const float Axe::FIXED_BONUS_DAMAGE[NUMGRADES] = {1.5,1.2,1,0.9};

// [Atividade 5]
// Sobrecargas
ostream &operator<<(ostream &out, const Axe &current ){
    out<<"================================\n";
    out<<"Mostrando Atributos do Machado: \n";
    out<<"Dano base: " << current.base_damage<<'\n';
    out<<"Nível: "<< current.level<<'\n';
    out<<"Nome: "<< current.axename<<'\n';
    out<< *current.myCandelabrador;
    return out;
}


bool operator==( const Axe &axe_a,const Axe &axe_b){
    if (axe_a.axename == axe_b.axename){
        return true;
    }
    return false;
}

bool operator!=( const Axe &axe_a,const Axe &axe_b){
    if (axe_a.axename != axe_b.axename){
        return true;
    }
    return false;
}

int operator!( const Axe &axe){
    int level =1;
    if(axe.level!=8){level = 8; }
    return level;
}

void Axe::operator=(const Axe& axe){
    this->level = axe.level;
    this->rarity = axe.rarity;
    this->base_damage = axe.base_damage;
    this->number_projectiles = axe.number_projectiles;

}

// Métodos Static
int Axe::getNumberAxes(){
    return numberaxes;
}
int Axe::getNumCopies(){return numcopies;}


// Construtores com atributos Const
Axe::Axe(int level):
    axename("no name"),namechanges(0),graded(false),MAXCHANGES(5),MAXRARITY(100),MINDAMAGE(20)
{

// [ATIVIDADE 4]
// Constrututores alterados

        setLevel(level);
        setNumber_projectiles(number_projectiles);
        setRarity(rarity);
        setBase_damage(base_damage);
        createMapBonus();
        setAxeBuffs();
        myCandelabrador = new Candelabrador(level);
        previous_stage_bonusPtr = 0; 
        numbuffsPtr=0;
        numbuffs=5;
        completedstages=0;
        sizebuffs=0;
        numberaxes++;


}



Axe::Axe(int level,   int rarity , double base_damage, int number_projectiles, string name):
   axename(name), namechanges(0), graded(false),MAXCHANGES(5), MAXRARITY(100),MINDAMAGE(20)
{

// [ATIVIDADE 4]
// Constrututores alterados

        setLevel(level);
        setNumber_projectiles(number_projectiles);
        setRarity(rarity);
        setBase_damage(base_damage);
        createMapBonus();
        setAxeBuffs();
        myCandelabrador = new Candelabrador(level);
        previous_stage_bonusPtr = 0;    
        numbuffsPtr=0;
        numbuffs=5;
        completedstages=0;
        sizebuffs=0;    
        numberaxes++;


}


// [ATIVIDADE 4]
// Construtor de cópia ajustado
Axe::Axe (const Axe & another ):
    namechanges(0), graded(false),MAXRARITY(another.MAXRARITY),MINDAMAGE(another.MINDAMAGE),MAXCHANGES(another.MAXCHANGES){

        this ->level = another.level;
        this -> rarity = another.rarity;
        this -> base_damage = another.base_damage;
        this -> number_projectiles = another.number_projectiles;
        this -> axename = another.axename;
        
        // [ATIVIDADE 4]
        // Alterações no Construtor de Cópia


        this -> sizebuffs = another.sizebuffs;
        this -> completedstages = another.completedstages;
        this -> numbuffsPtr = new int [this -> sizebuffs];
        for (auto i = 0; i <completedstages; i++ ){
            this -> numbuffsPtr[i] = another.numbuffsPtr[i];
        }
        setNumBuffs(another.numbuffs); 

        this -> found_buffs.resize(another.found_buffs.size());   
        for (auto i = 0; i <another.found_buffs.size(); i++ ){
            this -> found_buffs[i] = another.found_buffs[i];
        }

        this -> previous_axe_names.resize(another.previous_axe_names.size());

        for (auto i = 0; i <another.previous_axe_names.size(); i++ ){
             this -> previous_axe_names[i] = another.previous_axe_names[i];
        }

        this -> previous_stage_bonus.resize(another.previous_stage_bonus.size());

        for (auto i = 0; i <another.previous_stage_bonus.size(); i++ ){
             this -> previous_stage_bonus[i] = another.previous_stage_bonus[i];
        }

        previous_stage_bonusPtr = 0;
        this-> myCandelabrador = another.myCandelabrador;
        createMapBonus();
        setAxeBuffs();    
           
        numberaxes++;
        numcopies++;

}


Axe::~Axe( )
{  
    // // [ATIVIDADE 4]
        

    //  deletando conteudo do ponteiro
    delete myCandelabrador;
    for (int i = 0; i<previous_stage_bonus.size(); i++)
        delete this->previous_stage_bonus[i];
    delete [] previous_stage_bonusPtr;
    delete [] numbuffsPtr;
    for (int i = 0; i<previous_axe_names.size(); i++)
        delete this->previous_axe_names[i];
    for (int i = 0; i<found_buffs.size(); i++)
        delete this->found_buffs[i];

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
// [ATIVIDADE 4]
// Mostra Possiveis bonus dos map

void Axe::showPosBonus() const{
    cout<<"ALL BONUS FOUND IN THE GAME\n";
    cout<<"BONUS FOR AXE GRADE \n";
    for (auto itr = map_bonus_damage.begin(); itr!=map_bonus_damage.end();++itr){
        cout<< "Grade : "<< itr->first << '\t' <<" Bonus: " << itr->second <<"\n";
    }
    cout<<"BONUS FOR ITEMS FOUND \n";
    for (auto itr =axe_found_buffs.begin(); itr!=axe_found_buffs.end();++itr){
        cout<< "Item : "<< itr->first << '\t' << " Bonus: " << itr->second <<"\n";
    }

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

// [ATIVIDADE 4]
// Change AxeName alterado para usar vetores
void Axe::changeAxeName (const string &nname ){
    if (namechanges==0){
        setAxeName(nname);
        return;
    }
    if (namechanges>0){
        bool teste=checkNameVec(nname);
        if(namechanges<=getMAXCHANGES() && teste==false){
            setAxeName(nname);
            return;
        }
 
    }
} 

// [ATIVIDADE 4]
// CheckNameVec Testa se o nome já foi usado

bool Axe::checkNameVec (const string &nname) const{
    int test =0;
    for(int i=0; i<previous_axe_names.size(); i++){
        if (nname==*previous_axe_names[i]){ test++;}
    } 
    if (test>0){ return true;}
    return false;
}

 
// [ATIVIDADE 4]
// changeAxeNameVec insere os valores no vetor de nomes
void Axe::changeAxeNameVec(const string &axename){
    if(previous_axe_names.size()<MAXCHANGES){
        previous_axe_names.push_back(new string(axename));
        return;
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

// [ATIVIDADE 4]
// Método Calculate Damage Alterado para considerar os bonus dos drops e das fases anteriores

float Axe::calculate_damage(){
    float bonusprevious = 1;
    if(previous_stage_bonus.size()>0){
    bonusprevious += *previous_stage_bonusPtr;}
    float final_damage = (getBase_damage()*checkbonus()*(1+calculateBuffs())*bonusprevious*(this->myCandelabrador->get_element_bonus())) + (this->myCandelabrador->get_unique_bonus());
    return final_damage;

}

// [ATIVIDADE 3]
// Simulador de batalha usando for e while para criar dummies

void Axe::simulate_battle(int numdummies){

    for (int i=0;i<numdummies;i++){
        float temp_dummy= rand() % 50 + 300;
        cout << "\nO hp do dummy  "<< i+1 <<" é de:"<<temp_dummy;
        while(temp_dummy>0){ 
            cout<<"\nDano causado ao dummy: "<< calculate_damage();
            temp_dummy -= calculate_damage();
            if( temp_dummy>0){cout<<"\nHp atual do dummy: " << temp_dummy;}
            if (temp_dummy==0){cout<<"\nHp atual do dummy: 0 ";}
        }
        cout << "\nDummy derrotado\n";
    }
}

// [ATIVIDADE 4]
// imprimir nomes anteriores usando for metado alterado para usar for e for_each

void Axe::printPreviousName(){
    cout<<"Nomes anteriores" <<"\n";
    vector <string> temp;
    for (int i=0; i<previous_axe_names.size();i++){
         temp.push_back(*previous_axe_names[i]);
    }
    for_each(temp.begin(), temp.end(), [] (auto axename){ cout<<axename<<'\n'; });
    for( int i =0; i<temp.size(); i++){
        temp.pop_back();
    }
}





// [ATIVIDADE 4]
// Cria um map dos arrays const de GRADEAXE e FIXED_BONUS_DAMAGE

void Axe::createMapBonus(){
    for (int i=0; i<NUMGRADES;i++){
        map_bonus_damage.insert(std::pair <string, float>(GRADEAXE[i],FIXED_BONUS_DAMAGE[i]));

    }
}

// [ATIVIDADE 4]
// SALVANDO BUFFS EM UM VETOR até o limite estabelecido pelo setNumBuffs
void Axe::saveBuffs(const string &buff){
    if(found_buffs.size()<numbuffs){
        found_buffs.push_back(new string (buff));
        return;}
// Quando o vetor alcança o numero maximo ele salvo o total dos buffs anteriores em outro vetor
    if (found_buffs.size()==numbuffs){
        cout<<"Parabens! Você Passou de fase!\n";
        cout<<"Você levara de bonus os para a proxima fase!\n";
// Salvando total dos buffs no vetor previous stage bonus 
        previous_stage_bonus.push_back(new float (calculateBuffs()));
// Criando ponteiro pra ultima posição do vetor
        previous_stage_bonusPtr = new float [previous_stage_bonus.size()];
        previous_stage_bonusPtr = previous_stage_bonus[previous_stage_bonus.size() - 1];
// Pop_back nos valores anteriores do vetor
        for(int i=0; i<numbuffs; i++){
            delete found_buffs[i];
            found_buffs.pop_back();
        }
//metodo saveBuffs chamado novamente para incrementar o vetor found_buffs 
        saveBuffs(buff);
    }

 }


// [ATIVIDADE 4]
// Checa dentro do Map qual os valores o Bonus do Machado do Jogador

float Axe::checkbonusmap() {
    for (auto itr = map_bonus_damage.begin(); itr!=map_bonus_damage.end();++itr){
        if(gradingAxe() == itr->first){
            return itr->second;
        }
    }
    return 0;
}

// [ATIVIDADE 4]
// Checa dentro do Map qual os valores dos drops obtidos pelo jogador

float Axe::checkeachBuff(const string &buff) const{
    float bonus_egg = 0;
    for (auto itr = axe_found_buffs.begin(); itr!=axe_found_buffs.end();++itr){
        if(buff == itr->first){
             bonus_egg += itr->second;
        }
        if (buff != itr->first) {
            bonus_egg = bonus_egg;
        }
    }
    return bonus_egg;
}

// [ATIVIDADE 4]
// calculo da soma dos buffs

float Axe::calculateBuffs() const{
    float total = 0;    
    for(auto i = 0;i<found_buffs.size();i++){
        total+=checkeachBuff(*found_buffs[i]);
        }
    return total;
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
        changeAxeNameVec(axename);
        namechanges++;
        return;
    }
    if( namechanges < getMAXCHANGES() ){
        namechanges++;
        this->axename = axename;
        changeAxeNameVec(axename); 
        return;}
    
}

// [ATIVIDADE 4]
// CRIA UM MAP COM OS VALORES POSSIVEIS DE BONUS

 void Axe::setAxeBuffs(){
    axe_found_buffs.insert(std::pair <string, double> ("goldenegg",0.05));
    axe_found_buffs.insert(std::pair <string, double> ("silvergg",0.01));
    axe_found_buffs.insert(std::pair <string, double> ("fourleafclover",0.08));
    axe_found_buffs.insert(std::pair <string, double> ("goldenfourleafclover",0.1));    
 }


// [ATIVIDADE 4]
// Numero maximo de buffs
void Axe::setNumBuffs(int numbuffs){
    if (numbuffs<0){
        numbuffs=0;
        return;
    }
    this -> numbuffs = numbuffs;
    LastStageBuffs(numbuffs);
} 


// [ATIVIDADE 4]
// Alocação de buffs
void Axe::LastStageBuffs (int numbuffs) {

    // memoria alocada dinamicamente. Primeiro caso completedstages incrementa caso o sizebuffs
    // esteja maior que 0. Salvando o numero de buffs na proxima posição de memoria
        if ( completedstages < sizebuffs )
    {
        numbuffsPtr[completedstages++] = numbuffs;
        return;
    }
    // Caso size of buffs esteja ainda igual a 0 o mesmo é alterado para 1
    if( sizebuffs == 0 )
    {
        sizebuffs = 1;
        // Numbuff alocados com a memoria 1 de sizebuffs
        numbuffsPtr = new int[ sizebuffs ];
        // Numbuff salvo na posição de memoria 
        numbuffsPtr[ completedstages++ ] = numbuffs;
        return;
    } 
    // Passado as duas condiçoes acima o método AllocinBuffs é chamado para alocar memoria
    AllocInBuffs(numbuffs);
}


 void Axe::AllocInBuffs(int numbuffs){
    // Salva o valor anterior da memoria em um ponteiro temporário
    int *buffs_temp = new int[sizebuffs];
    for (int i =0; i<completedstages ; i++)
        buffs_temp[i] = numbuffsPtr[i];

    // vetor anterior é desalocado
    delete [] numbuffsPtr;
    // Valor da sizebuffs incrementado em 100%
    sizebuffs += int( ceil(sizebuffs * 1));
    // memoria incrementada em 100%
    int *numbuffsPtr = new int[sizebuffs];
    // valores anteriores de armazenados em buffs_temp copiados para numbuffsPtr   
    for (int i = 0; i < completedstages;i++)
        numbuffsPtr[i] = buffs_temp[i];
    // Passa para a proxima posição de memoria
    numbuffsPtr[completedstages++] = numbuffs;
    // Deleta o vetor temporário
    delete [] buffs_temp;
    buffs_temp=0;

 }

// [Atividade 5]
// Métodos usando composição

    void Axe::set_candelabrador_unique(int level){
        this-> myCandelabrador->set_unique(level);
    }
    
    void Axe::set_candelabrador_element(string element){
        this-> myCandelabrador->set_element(element);
    }
    void Axe::set_candelabrador_data(int d, int m, int a){
        this-> myCandelabrador-> set_data(d , m, a);
    }