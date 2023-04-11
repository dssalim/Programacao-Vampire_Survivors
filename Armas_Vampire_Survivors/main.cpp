#include <iostream>
#include "ax.h"


using std::cout;

int main() {

// Testando construtor com 1 dado de entrada(level)
    cout<<"teste 1\n";
    Axe axe(2)  ;
    axe.throwAxe();
    cout<<'\n';

// Testando sets

    cout<<"teste 2\n";
    axe.setLevel(1);
    axe.setBase_damage(30);
    axe.setNumber_projectiles(7);
    axe.setRarity(60);
    axe.throwAxe();
 // Testando construtor testando formula dos níveis
    cout<<'\n';
    cout<<"teste 3\n";
    axe.setLevel(2);
    axe.setBase_damage(45);
    axe.setNumber_projectiles(3);    
    axe.throwAxe();
    cout<<'\n';
    
    cout<<"teste 4\n";
    axe.setLevel(3);
    axe.throwAxe();
    cout<<'\n';
    cout<<"teste 5\n";
    axe.setLevel(5);
    axe.throwAxe();
    cout<<"\n";
// Testando construtor com dados de entrada
    double damage=30;
    int lvl=3,rar=75,num=2;
    cout<<"teste 6\n";
    Axe custom_axe(lvl,rar,num,damage, "Axe Custom",8);
    custom_axe.throwAxe();
    cout<<'\n';


// Testando segundo construtor com dados de entrada
    cout<<"teste 7\n";
    Axe new_custom_axe(lvl, rar);
    new_custom_axe.throwAxe();
    cout<<'\n';

// Verificando valores Const dos machados Criados

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
    cout<<"\nteste 8\n";
    anotheraxe.throwAxe();

 
//Testando setAxeName

    cout<<"\nteste 9\n";
    anotheraxe.changeAxeName("Testing");

    anotheraxe.throwAxe();

//Testando changeAxeName por referencia
    cout<<"\nteste 10\n";
    string nome_teste = "Teste NameChange";
    const string *teste_nome =  &nome_teste;
    anotheraxe.changeAxeName( *teste_nome);
    anotheraxe.throwAxe();

//Testando MAXCHANGES
    cout<<"\nteste 11\n";
    anotheraxe.changeAxeName("Testing333");
    anotheraxe.throwAxe();

// Testando Grade Axe
    cout<<"\nteste 12\n";
    cout<<'\n';
    anotheraxe.gradeAxe();

// Testando Notas
    Axe topaxe(8,100);
    topaxe.changeAxeName("TopAxe");
    cout<<'\n';
    topaxe.gradeAxe();

// Testando Objetos Const
    cout<<"\nteste 13\n";
    const Axe TROOAXE(7,50);
    cout<<'\n';
    TROOAXE.gradeAxe();
    cout<<'\n';

// Testando Objetos Non Const 
    cout<<"\nteste 14\n";
    Axe fireaxe(6,70);
    cout<<'\n';
    fireaxe.gradeAxe();
    cout<<'\n';
    
// Testando Métodos Static
    cout << "\nteste 15\n";
    cout << "Numero de Objetos Axe Criados: " << Axe::getNumberAxes() <<"\n";
    cout << "Destes o numero de cópias é: " <<Axe::getNumCopies()<<"\n";

    return 0;
}