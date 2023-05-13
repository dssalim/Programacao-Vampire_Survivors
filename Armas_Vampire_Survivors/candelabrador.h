#ifndef CANDELABRADOR_H
#define CANDELABRADOR_H
#include <iostream>
using std::ostream;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <map>
using std::map;
#include "data.h"


class Candelabrador
{
    friend ostream &operator<<(ostream &, const Candelabrador &);
    // friend ostream &operator<<(ostream &, const Candelabrador &);

public:
    Candelabrador(int = 1);
    Candelabrador(string="Neutral");
    Candelabrador(const Candelabrador &);
    ~Candelabrador();


void set_unique(int);
int  get_unique_level() const;
double get_unique_bonus() const;
void set_element(string);
string get_element() const;
void set_data(int=13 , int=5, int=2023);
void printdata()const;
void save_date();
bool checkelement(string);
void createmapelement();

private:
    struct unique {  int level; 
    double bonus; 
};
    unique unique;
    const static int NUM_ELEMENT=5;
    const static string ELEMENTS[NUM_ELEMENT];
    const static double ELEMENT_BONUS[NUM_ELEMENT];
    map<string,double>map_elemet;
    string type_element;
    Data* last_played_ptr;
    int daily_play_bonus_size;
    int* daily__play_bonus_ptr;
    Data currentDate;
    vector <Data *> dates;

};

#endif