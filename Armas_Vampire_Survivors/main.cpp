#include <iostream>
#include "ax.h"

using std::cout;


int main() {

vector <string* > drops;
drops.push_back(new string ("trash"));
drops.push_back(new string ("goldenegg"));
drops.push_back(new string ("silveregg"));
drops.push_back(new string ("fourleafclover"));
drops.push_back(new string ("goldenclover"));
drops.push_back(new string ("silveregg"));
drops.push_back(new string ("fourleafclover"));
drops.push_back(new string ("goldenclover"));

Axe hellaxe(1,100); 

hellaxe.throwAxe();

hellaxe.setNumBuffs(8);
for (auto i=0; i<drops.size(); i++){
    hellaxe.saveBuffs(*drops[i]);
}

hellaxe.changeAxeName("Axe do Inferno");

cout<<hellaxe;

    for (auto i =0; i<drops.size();i++){
        delete  drops[i];
        drops[i] =0;
        drops.pop_back();
    }



    // Construtor 1
    Candelabrador teste (2);
    cout<< teste.get_unique_level()<<'\n';
    cout<< teste.get_unique_bonus()<<'\n';
    // Construtor 2 
    Candelabrador teste2("Fire");
    // Construtor de Cópia
    cout<<teste2.get_unique_level()<<'\n';
    Candelabrador teste3(teste);
    cout<<teste3.get_unique_level()<<'\n';
    teste.set_data(14,05,2023);
    cout<<'\n';
    cout<<teste;
    cout<<teste2;
    cout<<(teste==teste2);
    cout<<'\n';
    cout<<(teste==teste3);
    cout<<'\n';
    cout<<(teste!=teste2);
    cout<<'\n';
    cout<<(teste!=teste3);
    
    // Sobrecarga atribuição Candelabrador
    teste2=teste;
    cout<<'\n';
    cout<<teste2;
    cout<<'\n';
    cout<<!teste2;
    cout<<'\n';
    // Sobrecarga Axe
    Axe teste_copia(hellaxe);
    cout<<(hellaxe==teste_copia);
    teste_copia.changeAxeName("Novo Nome");
    cout<<'\n';
    cout<<(hellaxe==teste_copia);
    cout<<'\n';
    cout<<!hellaxe;
    cout<<'\n';
    cout<<hellaxe;
    cout<<'\n';
    hellaxe.setLevel(!hellaxe);
    cout<<hellaxe;
    cout<<'\n';
    teste_copia=hellaxe;
    cout<<teste_copia;
    cout<<hellaxe;
    hellaxe.set_candelabrador_unique(3);
    cout<<hellaxe;
    cout<<'\n';
    hellaxe.set_candelabrador_element("Fire");
    cout<<hellaxe;
    hellaxe.set_candelabrador_data(14,5,2023);
    cout<<hellaxe;
    teste_copia.set_candelabrador_data(14,5,2023);
    cout<<teste_copia;
    cout << hellaxe.calculate_damage();
    return 0;
}