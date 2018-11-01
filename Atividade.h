#include <iostream>
#include <string>
using namespace std;
#include "Pessoa.cpp"
#define MAXIMO_RECURSOS 10

class Atividade {
    private:
        string nome;
        int horasNecessarias;
        Pessoa* p[MAXIMO_RECURSOS];
        int numeroDePessoas;
    public:
        Atividade(string nome, int horasNecessarias);
        ~Atividade();
        string getNome();
        int getHorasNecessarias();
        bool adicionar(Pessoa* recurso);
        Pessoa** getPessoas();
        int getQuantidadeDePessoas();
        int getDuracao();
        double getCustoAtividade();
        void imprimir();
};
