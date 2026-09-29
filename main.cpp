#include <iostream>
#include <string>

using namespace std;

int main() {

    const int MAX_CONTAS = 5;

    int numeroConta[MAX_CONTAS];
    string nomeCliente[MAX_CONTAS];
    string cpf[MAX_CONTAS];
    int tipoConta[MAX_CONTAS];
    double saldo[MAX_CONTAS];
    bool contaAtiva[MAX_CONTAS];

    int quantidadeContas = 0;
    int opcao;
    int numeroBusca;
    int posicao;
    int novoTipo;

    do {

        cout << "\n*******************************************" << endl;
        cout << "TRABALHO BANCARIO - GABRIEL MONTEIRO - 26514" << endl;
        cout << "*********************************************" << endl;
        cout << "1 - Cadastrar conta" << endl;
        cout << "2 - Consultar conta" << endl;
        cout << "3 - Verificar saldo" << endl;
        cout << "4 - Alterar tipo da conta" << endl;
        cout << "5 - Ativar/Desativar conta" << endl;
        cout << "6 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {

        case 1:

            if (quantidadeContas >= MAX_CONTAS) {
                cout << "\nLimite de 5 contas atingido!" << endl;
                break;
            }

            cout << "\n--- CADASTRO DE CONTA ---" << endl;

            cout << "Numero da conta: ";
            cin >> numeroConta[quantidadeContas];

            // Valida o numero da conta
            while (numeroConta[quantidadeContas] <= 0) {
                cout << "Numero invalido. Digite um numero maior que zero: ";
                cin >> numeroConta[quantidadeContas];
            }

            cin.ignore();

            cout << "Nome do titular: ";
            getline(cin, nomeCliente[quantidadeContas]);

            cout << "CPF: ";
            getline(cin, cpf[quantidadeContas]);

            cout << "Tipo da conta (1 - Corrente / 2 - Poupanca): ";
            cin >> tipoConta[quantidadeContas];

            // Valida o tipo da conta
            while (tipoConta[quantidadeContas] != 1 &&
                   tipoConta[quantidadeContas] != 2) {

                cout << "Tipo invalido. Digite 1 ou 2: ";
                cin >> tipoConta[quantidadeContas];
            }

            cout << "Saldo inicial: R$ ";
            cin >> saldo[quantidadeContas];

            // Valida o saldo
            while (saldo[quantidadeContas] < 0) {
                cout << "O saldo nao pode ser negativo. Digite novamente: R$ ";
                cin >> saldo[quantidadeContas];
            }

            contaAtiva[quantidadeContas] = true;

            quantidadeContas++;

            cout << "\nConta cadastrada com sucesso!" << endl;

            break;


        case 2:

            if (quantidadeContas == 0) {
                cout << "\nNenhuma conta cadastrada." << endl;
                break;
            }

            cout << "\nDigite o numero da conta: ";
            cin >> numeroBusca;

            posicao = -1;

            for (int i = 0; i < quantidadeContas; i++) {
                if (numeroConta[i] == numeroBusca) {
                    posicao = i;
                }
            }

            if (posicao == -1) {

                cout << "\nConta nao encontrada." << endl;

            } else {

                cout << "\n--- DADOS DA CONTA ---" << endl;
                cout << "Numero: " << numeroConta[posicao] << endl;
                cout << "Titular: " << nomeCliente[posicao] << endl;
                cout << "CPF: " << cpf[posicao] << endl;

                if (tipoConta[posicao] == 1) {
                    cout << "Tipo: Conta Corrente" << endl;
                } else {
                    cout << "Tipo: Conta Poupanca" << endl;
                }

                cout << "Saldo: R$ " << saldo[posicao] << endl;

                if (contaAtiva[posicao]) {
                    cout << "Situacao: Ativa" << endl;
                } else {
                    cout << "Situacao: Inativa" << endl;
                }
            }

            break;


        case 3:

            cout << "\nDigite o numero da conta: ";
            cin >> numeroBusca;

            posicao = -1;

            for (int i = 0; i < quantidadeContas; i++) {
                if (numeroConta[i] == numeroBusca) {
                    posicao = i;
                }
            }

            if (posicao == -1) {

                cout << "\nConta nao encontrada." << endl;

            } else if (!contaAtiva[posicao]) {

                cout << "\nA conta esta inativa." << endl;

            } else {

                cout << "\nSaldo da conta: R$ "
                     << saldo[posicao] << endl;
            }

            break;


        case 4:

            cout << "\nDigite o numero da conta: ";
            cin >> numeroBusca;

            posicao = -1;

            for (int i = 0; i < quantidadeContas; i++) {
                if (numeroConta[i] == numeroBusca) {
                    posicao = i;
                }
            }

            if (posicao == -1) {

                cout << "\nConta nao encontrada." << endl;

            } else if (!contaAtiva[posicao]) {

                cout << "\nA conta esta inativa." << endl;

            } else {

                cout << "\nTipo atual: ";

                if (tipoConta[posicao] == 1) {
                    cout << "Conta Corrente" << endl;
                } else {
                    cout << "Conta Poupanca" << endl;
                }

                cout << "Novo tipo (1 - Corrente / 2 - Poupanca): ";
                cin >> novoTipo;

                while (novoTipo != 1 && novoTipo != 2) {
                    cout << "Tipo invalido. Digite 1 ou 2: ";
                    cin >> novoTipo;
                }

                tipoConta[posicao] = novoTipo;

                cout << "\nTipo da conta alterado com sucesso!" << endl;
            }

            break;


        case 5:

            cout << "\nDigite o numero da conta: ";
            cin >> numeroBusca;

            posicao = -1;

            for (int i = 0; i < quantidadeContas; i++) {
                if (numeroConta[i] == numeroBusca) {
                    posicao = i;
                }
            }

            if (posicao == -1) {

                cout << "\nConta nao encontrada." << endl;

            } else {

                if (contaAtiva[posicao]) {

                    contaAtiva[posicao] = false;
                    cout << "\nConta desativada com sucesso!" << endl;

                } else {

                    contaAtiva[posicao] = true;
                    cout << "\nConta ativada com sucesso!" << endl;
                }
            }

            break;


        case 6:

            cout << "\nSistema encerrado." << endl;
            break;


        default:

            cout << "\nOpcao invalida!" << endl;
        }

    } while (opcao != 6);

    return 0;
}