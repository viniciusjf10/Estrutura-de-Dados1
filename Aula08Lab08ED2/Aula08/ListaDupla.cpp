#include <iostream>
#include <cstdlib>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla()
{
    cout << "Criando uma ListaDupla" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaDupla::~ListaDupla()
{
    cout << "Destruindo ListaDupla" << endl;
    NoDuplo *p = primeiro;
    while(p != NULL)
    {
        NoDuplo *t = p->getProx();
        delete p;
        p = t;
    }
}

bool ListaDupla::busca(int val)
{
    NoDuplo *p;
    for(p = primeiro; p != NULL; p = p->getProx())
        if(p->getInfo() == val)
            return true;
    return false;
}

int ListaDupla::get(int k)
{
    NoDuplo *p = primeiro;
    for(int i = 0; i < k; i++)
    {
        if(p == NULL)
            break;
        p = p->getProx();
    }
    if(p == NULL)
    {
        cout << "ERRO: Indice invalido!" << endl;
        exit(1);
    }
    else
        return p->getInfo();
}

void ListaDupla::set(int k, int val)
{
    NoDuplo *p = primeiro;
    for(int i = 0; i < k; i++)
    {
        if(p == NULL)
            break;
        p = p->getProx();
    }
    if(p == NULL)
        cout << "ERRO: Indice invalido!" << endl;
    else
        p->setInfo(val);
}

void ListaDupla::insereInicio(int val)
{
	NoDuplo *p = new NoDuplo();
	p->setInfo(val);
	p->setProx(primeiro);
	p->setAnt(NULL);

	if(n == 0) ultimo = p;
	else primeiro->setAnt(p);

	primeiro = p;
	n = n + 1;
}

void ListaDupla::removeInicio()
{
	NoDuplo *p;
	if(primeiro != NULL)
	{
		p = primeiro;
		primeiro = p->getProx();
		delete p;
		n = n - 1;

		if(n == 0) 	ultimo = NULL;
		else primeiro->setAnt(NULL);
	}
	else
        cout << "ERRO: lista vazia" << endl;
}

void ListaDupla::insereFinal(int val)
{
    NoDuplo *p= new NoDuplo();
    ultimo ->setProx(p);
    p->setInfo(val);
    p->setAnt(ultimo);
    p->setProx(NULL);
    ultimo =p;
    n=n+1;

}

void ListaDupla::removeFinal()
{
    NoDuplo *p=ultimo;
    p=p->getAnt();
    p->setProx(NULL);
    ultimo=p;
    n=n-1;
}

void ListaDupla::imprime()
{
    NoDuplo *p=primeiro;
    cout<<"Imprimindo a lista na ordem correta: "<<endl;
    while (p!=NULL)
    {
        cout<<p->getInfo()<<",";
        p=p->getProx();
    }
    cout<<endl;
}

void ListaDupla::imprimeReverso()
{
    NoDuplo *p=ultimo;
    cout<<"Imprimendo lista na ordem inversa"<<endl;
    while(p!=NULL)
    {
        cout<<p->getInfo()<<",";
        p=p->getAnt();
    }
    cout<<endl;
}

ListaDupla* ListaDupla::concatena(ListaDupla *l2)
{
    NoDuplo *p=ultimo;
    NoDuplo *q=primeiro;
    p->setProx(q);
    q->setAnt(p);
}
