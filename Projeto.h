#include <iostream>
#include <string>
#include <cmath>
#include "Atividade.cpp"
#define MAXIMO_ATIVIDADES 10
using namespace std;

class Projeto {
    private:
        string nome;
        int numeroAtividades;
        int numeroPessoas;
        Atividade* atividades[MAXIMO_ATIVIDADES];
        Pessoa* pessoas[MAXIMO_RECURSOS];

    public:
        string getNome();
        Projeto(string nome);
        ~Projeto();
        bool adicionar(Atividade* a);
        Atividade** getAtividade();
        int getQuantidadeDeAtividades();

        bool adicionarRecurso(Pessoa* pe);
        Pessoa** getPessoas();
        int getQuantidadeDePessoas();

        int getDuracaoProjeto();
        double getCustoProjeto();

        void imprimir();
};