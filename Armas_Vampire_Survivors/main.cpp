#include <iostream>
#include "ax.h"

using std::string;
using std::cout;
using std::iterator;
using std::map;

int main() {

// Testando construtor com 1 dado de entrada(level)
    cout<< "======================================================================\n";
    cout<<"TESTE 1\n";
    Axe axe(2)  ;
    axe.throwAxe();
    cout<<'\n';

// Testando sets
    cout<< "=======================================================================\n";
    cout<<"TESTE 2\n";
    axe.setLevel(1);
    axe.setBase_damage(30);
    axe.setNumber_projectiles(7);
    axe.setRarity(60);
    axe.throwAxe();
    cout<<'\n';
 // Testando construtor testando formula dos níveis
    cout<< "=======================================================================\n";
    cout<<"TESTE 3\n";
    axe.setLevel(2);
    axe.setBase_damage(45);
    axe.setNumber_projectiles(3);    
    axe.throwAxe();
    cout<<'\n';
    cout<< "=======================================================================\n";
    
    cout<<"TESTE 4\n";
    axe.setLevel(3);
    axe.throwAxe();
    cout<<'\n';
    cout<< "=======================================================================\n";

    cout<<"TESTE 5\n";
    axe.setLevel(5);
    axe.throwAxe();
    cout<<"\n";
// Testando construtor com dados de entrada
    double damage=30;
    int lvl=3,rar=75,num=2;
    cout<< "=======================================================================\n";
    cout<<"TESTE 6\n";
    Axe custom_axe(lvl,rar,num,damage, "Axe Custom");
    custom_axe.throwAxe();
    cout<<'\n';


// Testando segundo construtor com dados de entrada
    cout<< "========================================================================\n";
    cout<<"TESTE 7\n";
    Axe new_custom_axe(lvl, rar);
    new_custom_axe.throwAxe();
    cout<<'\n';

// Verificando valores Const dos machados Criados
    cout<< "========================================================================\n";
    cout<<"TESTE 8\n";

    cout<<"Axe:\n";
    cout<<"MAXRARITY: "<<axe.getMAXRARITY()<<'\n';
    cout<<"MINDAMAGE: "<<axe.getMINDAMAGE()<<'\n';
    cout<<"MAXCHANGES: "<<axe.getMAXCHANGES()<<'\n';


    cout<<"Custom Axe:\n";
    cout<<"MAXRARITY: "<<custom_axe.getMAXRARITY()<<'\n';
    cout<<"MINDAMAGE: "<<custom_axe.getMINDAMAGE()<<'\n';
    cout<<"MAXCHANGES: "<<custom_axe.getMAXCHANGES()<<'\n';


    cout<<"New Custom AxeAxe:\n";
    cout<<"MAXRARITY: "<<new_custom_axe.getMAXRARITY()<<'\n';
    cout<<"MINDAMAGE: "<<new_custom_axe.getMINDAMAGE()<<'\n';
    cout<<"MAXCHANGES: "<<new_custom_axe.getMAXCHANGES()<<'\n';

//Testando Const Static
cout << "Testando Grade: " << axe.gradingAxe();


// Testando construtor de cópia
    Axe anotheraxe(new_custom_axe);
    cout<< "\n======================================================================\n";
    cout<< "TESTE 9\n";
    anotheraxe.throwAxe();

 
//Testando setAxeName

    cout<< "========================================================================\n";
    cout<< "TESTE 10\n";;
    anotheraxe.changeAxeName("Testing");

    anotheraxe.throwAxe();

//Testando changeAxeName por referencia
    cout<< "========================================================================\n";
    cout<< "TESTE 11\n";
    string nome_teste = "Teste NameChange";
    const string *teste_nome =  &nome_teste;
    anotheraxe.changeAxeName( *teste_nome);
    anotheraxe.throwAxe();

//Testando MAXCHANGES
    cout<< "========================================================================\n";
    cout<< "TESTE 12\n";
    anotheraxe.changeAxeName("Testing333");
    anotheraxe.throwAxe();

// Testando Grade Axe
    cout<< "========================================================================\n";
    cout<< "TESTE 13\n";
    cout<<'\n';
    anotheraxe.gradeAxe();

// Testando Notas
    Axe topaxe(8,100);
    topaxe.changeAxeName("TopAxe");
    cout<<'\n';
    topaxe.gradeAxe();

// Testando Objetos Const
    cout<< "=======================================================================\n";
    cout<< "TESTE 14\n";
    const Axe TROOAXE(7,50);
    cout<<'\n';
    TROOAXE.gradeAxe();
    cout<<'\n';
// Testando Objetos Non Const 
    cout<< "========================================================================\n";
    cout<< "TESTE 14\n";
    Axe fireaxe(6,70);
    cout<<'\n';
    fireaxe.gradeAxe();
    cout<<'\n';
    
// Testando Métodos Static
    cout<< "=========================================================================\n";
    cout<< "TESTE 15\n";
    cout << "Numero de Objetos Axe Criados: " << Axe::getNumberAxes() <<"\n";
    cout << "Destes o numero de cópias é: " << Axe::getNumCopies() <<"\n";
 
// Testando PreviousNames e Arrays

    cout<< "=========================================================================\n";
    cout<< "TESTE 16\n";
    cout <<"Teste do  Previous name salvar nomes anteriores em um array\n";
    fireaxe.changeAxeName("Teste1");
    fireaxe.changeAxeName("Teste1");
    fireaxe.changeAxeName("Teste2");
    fireaxe.changeAxeName("Teste3");
    cout << "\nMostrando nome atual com throw axe:\n ";
    fireaxe.throwAxe();
    cout << "Mostrando nomes anteriores\n ";
    fireaxe.printPreviousName();
    cout << "Mostrando Grade do Axe\n ";
    fireaxe.gradeAxe();    
    cout << "Mostrando Bonus de dano do Axe\n ";
    cout<<fireaxe.checkbonus()<<'\n';

    cout<< "==========================================================================\n";
    cout<< "TESTE 17\n";
    cout <<"Método com while\n";
    fireaxe.simulate_battle(1);

// Testando ponteiros memoria
    cout<< "==========================================================================\n";
    cout<< "TESTE 18\n";
    cout <<"Método com Ponteiros no Main\n";
    Axe *fireaxePtr;
    cout <<"Teste do ponteiro para Objeto \n";
    fireaxePtr = new Axe;   
    fireaxePtr ->changeAxeName("TestePtr1");
    fireaxePtr ->changeAxeName("TestePtr2");
    fireaxePtr ->changeAxeName("TestePtr3");
    fireaxePtr ->setBase_damage(100);
    fireaxePtr ->throwAxe();
    fireaxePtr ->printPreviousName(); 
    fireaxePtr ->simulate_battle(1);
    cout<<'\n';

// Desalocando e realocando memoria
    cout<< "============================================================================\n";
    cout<< "TESTE 19\n";
// Deletando conteudo do objeto
    delete fireaxePtr;
    fireaxePtr=0;
    cout<<'\n';


// [ATVIDADE 4]
// teste map

    cout<< "============================================================================\n";
    cout<< "TESTE 20\n";
// Comparando saída do método GradeAxe com Bonusmap

    anotheraxe.gradeAxe();
    cout<< "bonus map > " << anotheraxe.checkbonusmap()<<'\n';


// Teste de print de nomes anteriores ajustado
    cout<< "============================================================================\n";
    cout<< "TESTE 21\n";

    anotheraxe.printPreviousName();
        
// Alocação dinâmica de Memória no SetNumBuffs adição de de valores por meio de um for
    cout<< "============================================================================\n";
    cout<< "TESTE 22\n";
    anotheraxe.setNumBuffs(8);
    vector <string* > drops;
    drops.push_back(new string ("trash"));
    drops.push_back(new string ("goldenegg"));
    drops.push_back(new string ("silveregg"));
    drops.push_back(new string ("fourleafclover"));
    drops.push_back(new string ("goldenclover"));
    drops.push_back(new string ("silveregg"));
    drops.push_back(new string ("fourleafclover"));
    drops.push_back(new string ("goldenclover"));
    
    for (auto i=0; i<drops.size(); i++){
        anotheraxe.saveBuffs(*drops[i]);
    }
    
    cout <<"Checando os valores salvos: " <<anotheraxe.calculateBuffs();
    cout <<'\n';
//  Numero maximo de buffs
    cout<< "============================================================================\n";
    cout<< "TESTE 24\n";
    
    cout << anotheraxe.calculate_damage()<<'\n';



// Teste do novo método ChangeAxe Name;
    cout<< "============================================================================\n";
    cout<< "TESTE 23\n";
    Axe testepranome;
    testepranome.changeAxeName("teste1");
    testepranome.changeAxeName("teste3");
    testepranome.changeAxeName("teste5");
    testepranome.throwAxe();
    testepranome.printPreviousName();





// Testando 
    cout <<"Bonus Anterior: " <<anotheraxe.calculateBuffs()<<'\n';
    drops.push_back(new string ("goldenegg"));
    anotheraxe.saveBuffs(*drops[drops.size()-1]);
    drops.push_back(new string ("goldenegg"));
    anotheraxe.saveBuffs(*drops[drops.size()-1]);
    cout << "bonus novo : "<<anotheraxe.calculateBuffs()<<'\n';//teste utiliza uma função com MAP para calculo
    cout<<'\n';
    cout << anotheraxe.calculate_damage()<<'\n';

    for (auto i =0; i<drops.size();i++){
        delete  drops[i];
        drops[i] =0;
        drops.pop_back();
    }

// TesteMap
    cout<< "============================================================================\n";
    cout<< "TESTE 24\n";
    anotheraxe.showPosBonus();


// Teste construtor de cópia atualizado
    cout<< "============================================================================\n";
    cout<< "TESTE 25\n";
    cout<<"Teste pra teste de cópia"<<'\n';

    Axe testepracopia(anotheraxe);
    testepracopia.printPreviousName();


    return 0;
}