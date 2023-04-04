#ifndef AXE_H
#define AXE_H
#endif

class Axe
{
public:
    Axe (int, int,int);
    Axe (double=20 ,int =100,  int =1, int =1);
    ~Axe();

    void throwAxe( ) const;
    double getBase_damage( ) const;
    int getLevel( ) const;
    int getRarity () const;
    int getNumber_projectiles () const;
    void setLevel( int );
    void setBase_damage( double);
    void setNumber_projectiles (int );
    void setRarity(int );


private:

    double base_damage;
    int level;
    int rarity;
    int number_projectiles;

};
