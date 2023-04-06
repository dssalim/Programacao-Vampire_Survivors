#ifndef AXE_H
#define AXE_H


class Axe
{
public:
    Axe (int=1);
    Axe (int , int ,double=20, int =1);
    ~Axe();

    void throwAxe( ) const;

    int getLevel( ) const;
    int getRarity () const;
    double getBase_damage( ) const;
    int getNumber_projectiles () const;
    void setLevel( int );
    void setBase_damage( double);
    void setNumber_projectiles (int );
    void setRarity(int );


private:


    int level;
    int rarity;
    double base_damage;
    int number_projectiles;
    
};
#endif