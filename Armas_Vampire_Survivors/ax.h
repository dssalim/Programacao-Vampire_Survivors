#ifndef AXE_H
#define AXE_H
#endif

class Axe
{
public:
    Axe(int,int,int,double);
    Axe(double base_damage=20 ,int rarity=100, int number=1, int level=1);
    ~Axe();

    double getBase_damage( ) const;
    int getLevel( ) const;
    int getRarity () const;
    int getNumber () const;
    void setLevel( int );
    void setBase_damage( double);
    void setNumber (int );
    void setRarity(int );
    void throwAxe( ) const;

private:

    double base_damage;
    int level;
    int rarity;
    int number;

};
