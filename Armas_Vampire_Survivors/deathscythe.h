#ifndef DEATHSCYTHE_H
#define DEATHSCYTHE_H

#include "tomahawk.h"



class DeathScythe: public Tomahawk
{
friend ostream &operator<<(ostream &, const DeathScythe &);
public:
    DeathScythe(int);
    DeathScythe(int, int, double);
    DeathScythe(DeathScythe&);
    ~DeathScythe();
    const DeathScythe operator=(const DeathScythe&);
    const bool operator==(DeathScythe&);
    const bool operator!=(DeathScythe&);
    int operator!();
    double get_final_bonus() const;
    void simulate_battle_death(int);
private:
    double final_bonus;
};

#endif