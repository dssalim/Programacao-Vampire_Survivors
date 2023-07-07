#include <iostream>
using std::cout;
#include "ax.h"
#include "tomahawk.h"
#include "deathscythe.h"
#include "menus.h"



int main() {
    
        cout << R"(
        #######################################
        #                                     #
        #                                     #
        #               VAMPIRE               #
        #               SURVIVOR              #
        #              Simulator              #
        #                                     #
        #                                     #
        #######################################
        )" ;
    char op,i;
    cout<<"Bem vindo ao Simulador de Vampire Survivors\n";
    cout<<"Aqui voce consegue utilizar e testar alguns modulos do Jogo incluindo armas e equipamentos.\n";
    
    while (1) {
        cout<<"Escolha uma das opcoes a seguir.\n";
        cout<<"1 - Simular Batalha com Tomahawk. \n";
        cout<<"2 - Simular Batalha com DeathScythe. \n";
        cout<<"3 - Sair. \n";
        cout<<"Informe a opcao: ";
        std::cin>>op;
        
        switch (op){

                case 49:{
                cout<< "\nInforme o nivel da Arma\n";
                int lvl;
                std::cin >> lvl;
                char arma;
                Tomahawk Toma(lvl);
                menu_simulacao(Toma);
                }
                case 50:{
                cout<< "\nInforme o nivel da Arma\n";
                int lvl;
                std::cin >> lvl;
                char arma;
                DeathScythe Death(lvl);
                menu_simulacao_death(Death);
                }
                case 51:
                cout<<"\nObrigado por usar o simulador";
                exit(0);
            }

            
    }
    return 0;
}