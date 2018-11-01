#include <iostream>
#include <string>
using namespace std;
#include "Pessoa.h"

Pessoa::Pessoa(string nome, double valorPorHora, int horasDiarias){

    this->nome = nome;
    this->valorPorHora = valorPorHora;
    this->horasDiarias = horasDiarias;

}
string Pessoa::getNome() {
    return this->nome;
}
double Pessoa::getValorPorHora() {
    return this->valorPorHora;
}
int Pessoa::getHorasDiarias() {
    return this->horasDiarias;
}
double Pessoa::getCusto(int dias) {
    return dias * this->horasDiarias * this->valorPorHora;
}
void Pessoa::imprimir() {
    cout << this->nome << " - " << "R$" << this->valorPorHora << " - " << this->horasDiarias << "h por dia" << endl;
}
Pessoa::~Pessoa(){
    //deletar o objeto e desalocar espaço na memória.
    cout << "Pessoa deletado do projeto." << endl;
    //destrutores sao chatinhos vei, a gente precisa ver depois...
}