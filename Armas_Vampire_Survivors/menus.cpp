#include<iostream>
#include<string>
#include "menus.h"

void menu_atributos(Tomahawk Toma){
    char ops;
    string name;
    int  lvl, nmr;
    double dmg;
    while(1){
        cout<<"1 - Alterar Nivel. \n";
        cout<<"2 - Alterar Ataque\n";
        cout<<"3 - Alterar Numero de Machados\n";
        cout<<"4 - Voltar\n";
        cout<<"Informe a opcao: ";
        std::cin>>ops;
        switch (ops){
            case 49:{
                cout<<"Informe o novo nivel do machado: ";
                std::cin>>lvl;
                Toma.setLevel(lvl);
                menu_atributos(Toma);}
            case 50:{ 
                cout<<"Informe o novo dano do machado: ";
                std::cin>>dmg;
                Toma.setBase_damage(dmg);
                menu_atributos(Toma);
            }
            case 51:{ 
                cout<<"Informe o Numero de Machados: ";
                std::cin>>nmr;
                Toma.setNumber_projectiles(nmr);
                menu_atributos(Toma);
            }

            case 52:{
                menu_simulacao(Toma);}

        }
    }
}


void menu_simulacao(Tomahawk Toma){
    char ops;
    while(1){
        
        cout<<"Escolha uma das opcoes a seguir.\n";
        cout<<"1 - Ver atributos do Machado. \n";
        cout<<"2 - Alterar Atributos do Machado\n";
        cout<<"3 - Iniciar Simulacao\n";
        cout<<"4 - Desistir e Sair da Simulacao. \n";
        cout<<"Informe a opção: ";
        std::cin>>ops;
        switch (ops){
            case 49:{
                cout<<Toma;
                menu_simulacao(Toma);}
            case 50:{
                menu_atributos(Toma);
            }
            case 51:{
                Toma.simulate_battle(3);
                cout<<"\nSimulacao encerrada, você voltara ao menu!\n";
                menu_simulacao(Toma);
                }
            case 52:
                cout<<"\nObrigado por usar a Simulacao!\n";
                exit(0);

        }

    }

}

void menu_atributos_death(DeathScythe Death){
    char ops;
    string name;
    int  lvl, nmr;
    double dmg;
    while(1){
        cout<<"1 - Alterar Nivel. \n";
        cout<<"2 - Alterar Ataque\n";
        cout<<"3 - Alterar Numero de Machados\n";
        cout<<"4 - Voltar\n";
        cout<<"Informe a opcao: ";
        std::cin>>ops;
        switch (ops){
            case 49:{
                cout<<"Informe o novo nivel do machado: ";
                std::cin>>lvl;
                Death.setLevel(lvl);
                menu_atributos_death(Death);}
            case 50:{ 
                cout<<"Informe o novo dano do machado: ";
                std::cin>>dmg;
                Death.setBase_damage(dmg);
                menu_atributos_death(Death);
            }
            case 51:{ 
                cout<<"Informe o Numero de Machados: ";
                std::cin>>nmr;
                Death.setNumber_projectiles(nmr);
               menu_atributos_death(Death);
            }

            case 52:{
                menu_simulacao_death(Death);}

        }
    }
}


void menu_simulacao_death(DeathScythe Death){
    char ops;
    while(1){
        
        cout<<"Escolha uma das opcoes a seguir.\n";
        cout<<"1 - Ver atributos do Machado. \n";
        cout<<"2 - Alterar Atributos do Machado\n";
        cout<<"3 - Iniciar Simulacao\n";
        cout<<"4 - Desistir e Sair da Simulacao. \n";
        cout<<"Informe a opção: ";
        std::cin>>ops;
        switch (ops){
            case 49:{
                cout<<Death;
                menu_simulacao_death(Death);}
            case 50:{
                menu_atributos_death(Death);
            }
            case 51:{
                Death.simulate_battle_death(3);
                cout<<"\nSimulacao encerrada, você voltara ao menu!\n";
                menu_simulacao_death(Death);
                }
            case 52:
                cout<<"\nObrigado por usar a Simulacao!\n";
                exit(0);

        }

    }

}