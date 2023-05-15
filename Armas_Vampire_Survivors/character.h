#ifndef CHARACTER_H
#define CHARACTER_H
#include <ostream>
using std::ostream;
#include <string>
using std::string;
#include <vector>
using std::vector;


class Character
{
    friend ostream &operator<<(ostream &, const Character &);
    friend bool operator==( const Character &,const Character &);
    friend bool operator!=(const Character &,const Character &);
    friend int operator!( const Character &);
    friend void CopyCharac(Character&, const Character&);
    friend void MaxLevel(Character&);
public:
    void operator=(const Character &);
    Character(int=1);
    Character(string);
    Character(const Character &);
    ~Character();
    void SetUnique(int=1);
    void ChangeCharacName(const string&);
    double GetUniqueAttack() const;

private:
    struct unique{
    int level;
    double attack;
    int exp;
    }unique;
    string character_name;
    vector<string *> previous_character_name;
    void SetCharacterName(string);
    void SaveCharacterNames(const string&);
};


#endif