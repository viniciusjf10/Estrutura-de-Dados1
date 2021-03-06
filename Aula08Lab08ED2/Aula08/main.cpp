#include <iostream>
#include <cstdlib> ///rand()
#include <ctime>   ///time()
#include "ListaDupla.h"

using namespace std;

int numAleatorio(int a, int b)
{
    return a + rand()%(b - a + 1); /// retorna um numero inteiro aleatório entre a e b
}

int main()
{
    ListaDupla l; /// cria lista vazia
    int NumNos = 10;

    srand(time(NULL));

    /// ATENCAO: os valores inseridos na lista sao gerados
    /// aleatoriamente e mudam em cada execucao do programa!!!
    cout << "Inserindo valores: ";
    for(int i = 1; i <= NumNos; i++)
    {
        int val =  numAleatorio(0, 50); /// cria um valor aleatório entre 0 e 50
        cout << val << ", ";
        l.insereInicio(val);
    }
    cout << endl;

    bool existe = l.busca(20);
    cout << "O valor 20 esta na lista? ";
    if(existe)
        cout << "Sim" << endl;
    else
        cout << "Nao" << endl;
    //l.imprime();
    //l.imprimeReverso();
    //cout<<"Inserindo no final o numero 5"<<endl;
    //l.insereFinal(5);
    //l.imprime();
    //cout<<"Inserindo no final o numero 8"<<endl;
    //l.insereFinal(8);
    //l.imprime();
    //l.removeFinal();
    //cout<<"Removendo no final da lista"<<endl;
    //l.imprime();
    //l.removeFinal();
    //cout<<"Removendo no final da lista"<<endl;
    //l.imprime();

    ListaDupla l2;
    cout << "Inserindo valores: ";
    for(int i = 1; i <= NumNos; i++)
    {
        int val =  numAleatorio(0, 50); /// cria um valor aleatório entre 0 e 50
        cout << val << ", ";
        l2.insereInicio(val);
    }
    cout << endl;
    l.concatena(l2);
    return 0;
};

