#include <iostream>
#include <string>
#include <cmath>
#include "Projeto.h"

Projeto::~Projeto() {
    for (int j = 0; j < this->getQuantidadeDePessoas(); j++) {
        delete this->pessoas[j];
    }
    delete[] this->pessoas;
    
    for (int i = 0; i < this->getQuantidadeDeAtividades(); i++) {
        delete this->atividades[i];
    }
    delete[] this->atividades;

    cout << "Projeto deletado." << endl;
}

Projeto::Projeto(string nome) {
    this->nome = nome;
    this->numeroAtividades = 0;
    this->numeroPessoas = 0;
}

string Projeto::getNome() {
    return this->nome;
}

bool Projeto::adicionar(Atividade *a){
    int n_atividades = this->getQuantidadeDeAtividades();
    int i;
    if (n_atividades < MAXIMO_ATIVIDADES) {
        atividades[numeroAtividades] = a;
        this->numeroAtividades++;
        return true;
    } else {
        return false;
    }
}
Atividade** Projeto::getAtividade() {
    return this->atividades;
    //retorna um vetor de atividades? ficou vago no enunciado.
}

int Projeto::getQuantidadeDeAtividades() {
    return this->numeroAtividades;
}

bool Projeto::adicionarRecurso(Pessoa *pe) {
    int n_pessoas = this->getQuantidadeDePessoas();
    for (int i = 0; i < n_pessoas; i++) {
        if(pessoas[i] == pe){
            return false;
        }
    }
    if (n_pessoas < MAXIMO_RECURSOS) {
        pessoas[n_pessoas] =  pe;
        this->numeroPessoas++;
        return true;
    } else {
        return false;
    }
}
Pessoa** Projeto::getPessoas(){
    return this->pessoas;
    //mesmo problema: retorna um vetor de pessoas? good question..
}
int Projeto::getQuantidadeDePessoas(){
    int pessoas_recurso, i;
    pessoas_recurso = 0;
    for(i = 0; i < this->getQuantidadeDeAtividades(); i++) {
        pessoas_recurso += this->atividades[i]->getQuantidadeDePessoas();
    }
    
    return this->numeroPessoas;
}

int Projeto::getDuracaoProjeto(){
    int duracao = 0;
    int i;
    for (i = 0; i < this->getQuantidadeDeAtividades(); i++) {
        duracao += atividades[i]->getDuracao();
    }
    return duracao;
}

double Projeto::getCustoProjeto() {
    int custo = 0;
    int j;
    for (j = 0; j < this->getQuantidadeDeAtividades(); j++) {
        custo += atividades[j]->getCustoAtividade();
    }
    return custo;
}
void Projeto::imprimir() {
    int k;
    cout << this->getNome() << " - " << this->getDuracaoProjeto() << " dias " << " - R$" << this->getCustoProjeto() << endl;
    for (k = 0; k < this->getQuantidadeDeAtividades(); k++) {
        atividades[k]->imprimir();
    }
}

