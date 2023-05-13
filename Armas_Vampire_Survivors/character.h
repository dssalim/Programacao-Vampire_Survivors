#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <map>
using std::map;

class character
{
public:
    character();
    ~character();




private:
    double life; //vida do personagem
    int movimentation; //quantidade de células movimentadas
    double speed; //tempo necessário para trocar de célula
    double delay; // tempo necessário para repetir o ataque
    int defense; //defesa do personagem
    struct unique { double bonus_life;
    int bonus_movimentation;
    double bonus_speed;
    double bonus_delay;
    int bonus_defense;};
    struct position{
        int cord_x;
        int cord_y;
    }
};

#endif