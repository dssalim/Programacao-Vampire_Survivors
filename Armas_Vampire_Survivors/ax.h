#ifndef AXE_H
#define AXE_H
#include <string>
using std::string;

class Axe
{
public:
    Axe (int=1);
    Axe (int , int ,double=20, int =1, string="no name", int = 5);

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

// Métodos Gets
    int getLevel( ) const;
    int getRarity () const;
    double getBase_damage( ) const;
    int getNumber_projectiles () const;
    string getAxeName() const;
    int getNameChanges() const;
// Métodos Get dos atributos const
    int getMAXCHANGES() const;
    double getMINDAMAGE() const;
    int getMAXRARITY() const;

// Métodos Set
    void setLevel( int );
    void setBase_damage( double);
    void setNumber_projectiles (int );
    void setRarity(int );
    void setAxeName(string );
    void setNameChanges();
// const string &

    void changeAxeName(const string &);


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



};
#endif