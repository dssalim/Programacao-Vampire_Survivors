#ifndef AXE_H
#define AXE_H
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <map>
using std::map;

class Axe
{
public:
    Axe (int=1);
    Axe (int , int ,double=20, int =1, string="no name");

// construtor de cópia
    Axe (const Axe &);
    ~Axe();

// Métodos Static
    static int getNumberAxes();
    static int getNumCopies();
// Métodos print(throwAxe) e Grade
    void throwAxe( ) const;
    string gradingAxe() const;
// Método Const e Non Const
    void gradeAxe(bool=true) const;
    void gradeAxe(bool=true);

// const string & usando for

    void changeAxeName(const string &); //Método alterado atividade 4

// Métodos Array que usam array e while
    float checkbonus();

// Métodos de calculo de dano
    float calculate_damage(); //Método alterado atividade 4

// Simulação de Batalha usando for e while
    void simulate_battle(int);

// Método com for
    void printPreviousName();//Método alterado atividade 4

// [ATIVIDADE 4]
    void showPosBonus() const;
    void createMapBonus(); 
    float checkbonusmap() ; 
    void changeAxeNameVec(const string &) ; 
    void saveBuffs(const string &);
    float checkeachBuff(const string &)const;
    bool checkNameVec(const string &) const;
    float calculateBuffs() const;
    void LastStageBuffs (int);



// Métodos Gets
    int getLevel( ) const;
    int getRarity () const;
    double getBase_damage( ) const;
    int getNumber_projectiles () const;
    string getAxeName() const;
// Métodos Get dos atributos const
    int getMAXCHANGES() const;
    double getMINDAMAGE() const;
    int getMAXRARITY() const;


// Métodos Set
    void setLevel( int );  
    void setBase_damage( double);
    void setNumber_projectiles (int );
    void setRarity(int );
// Método setAxe modificado para salvar nomes anteriores
    void setAxeName(string );

// [ATIVIDADE 4]
    void setAxeBuffs();
    void setNumBuffs(int);





private:

//Atributos 
    int level;
    int rarity;
    double base_damage;
    int number_projectiles;
// Atributo String
    string axename;
    int namechanges;
// Atributo Bool
    bool graded;

//Atributos Const 
    const int MAXCHANGES;
    const int MAXRARITY;
    const double MINDAMAGE;

    
// Atributos statics
    static int numberaxes;
    static int numcopies;

// Atributos const Static
    static const int NUMGRADES=4;
    static const string GRADEAXE[NUMGRADES];

// Arrays

    const static float FIXED_BONUS_DAMAGE[NUMGRADES];


// [ATIVIDADE 4]

// Vector
    vector < string *> found_buffs; // vetor de buffs
    vector < string *> previous_axe_names; //vetor de map
    vector < float *> previous_stage_bonus; //vector de bonus
// Map
    map <string, double> axe_found_buffs; // map dos buffs 
    map <string, float> map_bonus_damage; // map de bonus/grade

// Auxiliares
    int *numbuffsPtr; //aumenta a alocaçao de buffs
    int numbuffs; //quantidade de buffs cadastradas
    int completedstages; //Histórico dos leveis anteriores completos
    int sizebuffs; // tamanho do vetor de buffs
    float *previous_stage_bonusPtr; //bonus do ultimo estágio
// [ATIVIDADE 4]
// Método privado
    void AllocInBuffs(int); 
};
#endif