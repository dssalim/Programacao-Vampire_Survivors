#include <iostream>
#include "tomahawk.h"

Tomahawk::Tomahawk(int level):Axe(level){
    this->delay=1;
}

Tomahawk::Tomahawk(int level, int delay):Axe(level){
    this->delay=delay;
}

Tomahawk::Tomahawk (const Tomahawk& ori):Axe(ori){
    this->delay=ori.delay;
};
Tomahawk::~Tomahawk(){}

ostream &operator<<(ostream & out, const Tomahawk &other){
    out << static_cast < Axe  > (other );
    out <<"Atributos do Tomahawk"<<'\n';
    out << "Delay: " <<other.delay<<'\n';
    return out;
}

const Tomahawk Tomahawk::operator=(const Tomahawk& other){
    *static_cast < Axe *> (this) = static_cast < Axe > (other);
    this->delay = other.delay;

    return *this;
}

const bool Tomahawk::operator==(const Tomahawk& other){
    if (this->delay==other.delay && *static_cast < Axe *> (this) == static_cast < Axe > (other)){
        return true;
    }

    return false;
}


const bool Tomahawk::operator!=(const Tomahawk& other){
    if (this->delay!=other.delay || *static_cast < Axe *> (this) != static_cast < Axe > (other)){
        return true;
    }

    return false;
}

const int Tomahawk::operator!(){
     return !*static_cast < Axe *> (this);
}