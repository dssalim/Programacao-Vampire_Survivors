#ifndef TOMAHAWK_H
#define TOMAHAWK_H
#include "ax.h"
#include <iostream>
using std::ostream;
class Tomahawk : public Axe

{
    friend ostream &operator<<(ostream &, const Tomahawk &);
    
    public:
    Tomahawk(int);
    Tomahawk(int, int);
    Tomahawk (const Tomahawk&);
    ~Tomahawk();

    const Tomahawk operator=(const Tomahawk&);
    const bool operator==(const Tomahawk&);
    const bool operator!=(const Tomahawk&);
    const int operator!();
    

    private:
    int delay;
    
    
};


#endif 