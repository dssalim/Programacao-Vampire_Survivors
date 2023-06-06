#ifndef CHARACTER_H
#define CHARACTER_H
#include <ostream>
using std::ostream;
#include <string>
using std::string;
#include <vector>
using std::vector;

    struct unique_char{
    int level;
    double attack;
    int exp;
    };
class Character
{
    friend ostream &operator<<(ostream &, const Character &);
    friend void CopyCharac(Character&, const Character&);
    friend void MaxLevel(Character&);
public:

    Character(int=1);
    Character(string);
    Character(const Character &);
    ~Character();
    void operator=(const Character &);
    bool operator==( const Character &);
    bool operator!=(const Character &);
    int operator!( );
    
    
    void SetUnique(int=1);
    void ChangeCharacName(const string&);
    double GetUniqueAttack() const;

private:
    unique_char unique;
    string character_name;
    vector<string *> previous_character_name;
    void SetCharacterName(string);
    void SaveCharacterNames(const string&);
};


#endif