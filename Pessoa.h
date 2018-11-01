#include <iostream>
#include <string>
using namespace std;
class Pessoa {
    private:
        string nome;
        double valorPorHora;
        int horasDiarias;
    public:
        Pessoa(string nome, double valorPorHora, int horasDiarias);
        string getNome();
        double getValorPorHora();
        int getHorasDiarias();
        double getCusto(int dias);
        void imprimir();
        ~Pessoa();
};
