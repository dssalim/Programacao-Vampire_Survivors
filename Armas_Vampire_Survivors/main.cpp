#include <iostream>
using std::cout;
#include "ax.h"


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



    // Construtor 1 Candelabrador
    Candelabrador teste (2);
    cout<< teste.get_unique_level()<<'\n';
    cout<< teste.get_unique_bonus()<<'\n';
    // Construtor 2 Candelabrador
    Candelabrador teste2("Fire");
    // Construtor de Cópia Candelabrador
    cout<<teste2.get_unique_level()<<'\n';
    Candelabrador teste3(teste);
    cout<<teste3.get_unique_level()<<'\n';
    teste.set_data(14,05,2023);
    cout<<'\n';

    // Testes Sobrecarcaga Candelabrador
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
    cout <<'\n';
    teste_copia.set_candelabrador_data(15,5,2023);
    hellaxe.set_candelabrador_data(15,5,2023);
    // Teste Character
    Character teste_chara(3);
    Character teste2_chara("Fulano");
    Character teste3_chara(teste2_chara);
    teste_chara.ChangeCharacName("O Outro");
    teste2_chara.ChangeCharacName("O Outro novo");
    teste3_chara.ChangeCharacName("O Outro Novamente");
    teste_chara.ChangeCharacName("O Outro Original");
    // Teste Sobrecarca
    cout<<teste_chara;
    cout<<teste2_chara;
    // Teste Métodos
    CopyCharac(teste2_chara,teste_chara);
    cout<<teste2_chara;
    MaxLevel(teste_chara);
    cout<<teste_chara;

    // Teste Agregação
    Axe * Axe_ptr;
    Axe_ptr = new Axe(2);
    cout<<"Teste Ponteiro\n";
    cout<<Axe_ptr->calculate_damage();
    cout<<'\n';
    cout<<Axe_ptr->myCharacter;
    // Deletando Ponteiro
    delete Axe_ptr;
    Axe_ptr=0;

    return 0;
}