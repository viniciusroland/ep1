#include <iostream>
#include <string>
#include <cmath>
#include "Projeto.cpp"
using namespace std;

int main () {
    string nomeProjeto;
    int comando;
    cout << "Digite o nome do projeto: ";
    cin >> nomeProjeto;
    cout << "" << endl;
    Projeto* p = new Projeto(nomeProjeto);
    do {
        cout << "1 - Adicionar pessoa" << endl;
        cout << "2 - Adicionar atividade" << endl;
        cout << "3 - Imprimir projeto" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> comando;
        cout << "" << endl;
        if(comando == 1) {
            string nome;
            int valorPorHora;
            int horasDisponiveis;
            bool verificar;
            cout << "Nome: ";
            cin >> nome;
            cout << "Valor por hora (em R$): ";
            cin >> valorPorHora;
            cout << "Horas diarias: ";
            cin >> horasDisponiveis;
            cout << "" << endl;
            Pessoa * pessoa =  new Pessoa(nome, valorPorHora, horasDisponiveis);
            verificar = p->adicionarRecurso(pessoa);
            if (verificar == false) {
                cout << "Nao eh possivel adicionar uma nova pessoa." << endl;
                cout << "" << endl;
            } else {
                cout << "" << endl;
            }
        }
        if (comando == 2) {
            string nome;
            int horasNecessarias;
            bool verificar;
            cout << "Nome: ";
            cin >> nome;
            cout << "Horas necessarias: ";
            cin >> horasNecessarias;
            cout << "" << endl;
            Atividade* atv = new Atividade(nome, horasNecessarias);
            verificar = p->adicionar(atv);
            if (verificar == false) {
                cout << "Nao eh possivel adicionar uma nova atividade";
                cout << "" << endl;
            } else {
                string comando_;
                do {
                    cout << "Deseja adicionar um recurso (s/n)? ";
                    cin >> comando_;
                    cout << "" << endl;
                    if (comando_ == "s") {
                        int i;
                        int comando2;
                        for (i = 0; i < p->getQuantidadeDePessoas(); i++) {
                            cout << i+1 << " - ";
                            (p->getPessoas()[i])->imprimir();
                        }
                        cout << "Escolha uma pessoa ou 0 para cancelar: ";
                        cin >> comando2;
                        cout << "" << endl;
                        if (comando2 != 0) {
                            bool verificar = p->getAtividade()[p->getQuantidadeDeAtividades() - 1]->adicionar(p->getPessoas()[comando2 - 1]);
                            if (verificar == false) {
                                cout << "Nao foi possivel adicionar a pessoa" << endl;
                                cout << "" << endl;
                            }
                        }
                    }
                } while (comando_ != "n");
            }
        }
        if (comando == 3) {
            p->imprimir();
            cout << "" << endl;
        }
    } while (comando != 0);
    delete p;
    cout << "Voce encerrou o programa." << endl;
    return 0;

}
