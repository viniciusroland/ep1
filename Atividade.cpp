#include <iostream>
#include <string>
#include <cmath>
#include "Atividade.h"
using namespace std;

Atividade::Atividade(string nome, int horasNecessarias) {
    this->nome = nome;
    this->horasNecessarias = horasNecessarias;
    this->numeroDePessoas = 0;
}

string Atividade::getNome() {
    return this->nome;
}

int Atividade::getHorasNecessarias() {
    return this->horasNecessarias;
}

bool Atividade::adicionar(Pessoa* recurso) {
    int n_pessoas = this->getQuantidadeDePessoas();
    int i;
    for (i = 0; i < n_pessoas; i++) {
        if(p[i] == recurso){
            return false;
        }
    }
    if(n_pessoas < MAXIMO_RECURSOS) {
        p[n_pessoas] = recurso;
        this->numeroDePessoas++;
        return true;
    } else {
        return false;
    }
}

Pessoa** Atividade::getPessoas(){
    return this->p;
    //esse aqui nao tenho certeza, ficou vago no enunciado.
}

int Atividade::getQuantidadeDePessoas(){
    return this->numeroDePessoas;
}

int Atividade::getDuracao(){
    if (this->getQuantidadeDePessoas() == 0) {
        return -1;
    }
    int duracao = 0;
    int horasDisponiveis = 0;
    int i;
    for (i = 0; i < this->getQuantidadeDePessoas(); i++) {
        horasDisponiveis += p[i]->getHorasDiarias();
    }
    duracao = ceil(double(this->getHorasNecessarias())/double(horasDisponiveis));
    return duracao;
}

double Atividade::getCustoAtividade() {
    if (this->getQuantidadeDePessoas() == 0) {
        return -1;
    }
    int i;
    double custo = 0;
    for (i = 0; i < this->getQuantidadeDePessoas(); i++) {
        custo += (p[i]->getCusto(this->getDuracao()));
    }
    return custo;
}

void Atividade::imprimir() {
    cout << this->getNome() << " - " << this->getDuracao() << " dias" << " - R$" << this->getCustoAtividade() << endl; 
}

Atividade::~Atividade(){
    //deletar o objeto e desalocar memória.
    cout << "Atividade deletada do projeto." << endl;
    //destrutores sao chatinhos vei, a gente precisa ver depois..
}
