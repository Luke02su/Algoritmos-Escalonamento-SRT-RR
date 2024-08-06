#include <bits/stdc++.h> // Inclui todas as bibliotecas padrão C++ de uma só vez
using namespace std; // Utiliza o namespace padrão para evitar a necessidade de escrever std:: antes de cada comando

// Estrutura para representar um processo
struct Processo {
    string nome; // Nome do processo
    int tempoChegada; // Tempo de chegada do processo
    int tempoExecucao; // Tempo de execução do processo

    // Função para receber os detalhes do processo do usuário
    void receberProcesso() {
        cout << "\nNome do processo: ";
        cin >> nome; // Lê o nome do processo
        cout << "Tempo de chegada: ";
        cin >> tempoChegada; // Lê o tempo de chegada do processo
        cout << "Tempo de execucao: ";
        cin >> tempoExecucao; // Lê o tempo de execução do processo
    }
};

// Função para ordenar os processos
bool ordenarSRT(Processo a, Processo b) {
    // Ordena os processos primeiro pelo tempo de chegada
    if (a.tempoChegada == b.tempoChegada) {
        // Se o tempo de chegada for o mesmo, ordena pelo tempo de execução
        if (a.tempoExecucao == b.tempoExecucao) {
            // Se o tempo de execução também for o mesmo, ordena pelo nome
            return a.nome < b.nome; // Ordena os processos com o mesmo tempo de chegada e execução pelo nome
        }
        return a.tempoExecucao < b.tempoExecucao; // Ordena os processos pelo menor tempo de execução se os tempos de chegada forem iguais
    }
    return a.tempoChegada < b.tempoChegada; // Ordena os processos pelo menor tempo de chegada
}

bool ordenarRR(Processo a, Processo b){
    if(a.tempoChegada == b.tempoChegada){
        return a.nome < b.nome;
    }
    return a.tempoChegada < b.tempoChegada;
}

// Função de escalonamento Shortest Remaining Time (SRT)
void srt() {
    vector<Processo> lista; // Lista para armazenar os processos
    int resp; // Variável para armazenar a resposta do usuário

    // Loop para adicionar processos
    while (true) {
        cout << "\nVoce deseja adicionar um processo?\n";
        cout << "1 - Sim\n2 - Nao\n\n";
        cout << "Escolha: ";
        cin >> resp; // Lê a escolha do usuário
        if (resp == 1) {
            Processo p; // Cria um novo processo
            p.receberProcesso(); // Recebe os detalhes do processo
            lista.push_back(p); // Adiciona o processo à lista
        } else if (resp == 2) {
            break; // Sai do loop se o usuário não quiser adicionar mais processos
        }
    }

    // Ordena a lista de processos pelo tempo de chegada e outros critérios
    sort(lista.begin(), lista.end(), ordenarSRT);

    int tempoAtual = 0; // Inicializa o tempo atual

    // Loop principal para executar os processos com base no algoritmo SRT
    while (!lista.empty()) {
        int menorTempExec = INT_MAX; // Inicializa o menor tempo de execução como o valor máximo inteiro
        int posAtual = -1; // Inicializa a posição do processo atual como inválida

        // Procura o processo com o menor tempo de execução restante que já chegou
        for (int i = 0; i < (int)lista.size(); i++) {
            if (lista[i].tempoChegada <= tempoAtual) {
                if (lista[i].tempoExecucao < menorTempExec) {
                    menorTempExec = lista[i].tempoExecucao; // Atualiza o menor tempo de execução
                    posAtual = i; // Atualiza a posição do processo com o menor tempo de execução
                }
            } else {
                break; // Interrompe o loop se os processos ainda não chegaram
            }
        }

        // Executa o processo selecionado
        if (posAtual >= 0) {
            lista[posAtual].tempoExecucao--; // Decrementa o tempo de execução restante do processo
            cout << "Tempo: " << tempoAtual <<  " - Executou processo " << lista[posAtual].nome << " (TR = " <<  lista[posAtual].tempoExecucao << ").\n";
            if (lista[posAtual].tempoExecucao == 0) {
                lista.erase(lista.begin() + posAtual); // Remove o processo da lista
            }
        }
        tempoAtual++; // Incrementa o tempo atual
    }
    cout << endl << endl;
}

void verificarProntosRR(vector<Processo> &lista, int tempoAtual, queue<Processo>&fila){
    for(int i=0; i<(int)lista.size(); i++){
        if(lista[i].tempoChegada <= tempoAtual){
            fila.push(lista[i]);
            lista.erase(lista.begin() + i);
        } else {
            break;
        }
    }
}

// Função de escalonamento Round-Robin (RR) - ainda não implementada
void rr() {
    // Round-Robin é um algoritmo de escalonamento onde cada processo é executado por um tempo fixo (quantum)
    // e depois é colocado de volta na fila se não terminar.
    vector<Processo> lista; // Lista para armazenar os processos
    int resp; // Variável para armazenar a resposta do usuário

    // Loop para adicionar processos
    while (true) {
        cout << "\nVoce deseja adicionar um processo?\n";
        cout << "1 - Sim\n2 - Nao\n\n";
        cout << "Escolha: ";
        cin >> resp; // Lê a escolha do usuário
        if (resp == 1) {
            Processo p; // Cria um novo processo
            p.receberProcesso(); // Recebe os detalhes do processo
            lista.push_back(p); // Adiciona o processo à lista
        } else if (resp == 2) {
            break; // Sai do loop se o usuário não quiser adicionar mais processos
        }
    }

    int quantum;
    cout << "Digite o quantum de processamento:\n";
    cin >> quantum;

    sort(lista.begin(), lista.end(), ordenarRR);

    queue<Processo>fila;

    int tempoAtual = 0;
    while(!lista.empty() || !fila.empty()){
        verificarProntosRR(lista, tempoAtual, fila);

        if(!fila.empty()){
            if(quantum > fila.front().tempoExecucao){
                int tempExec = fila.front().tempoExecucao;
                for(int i=0; i<tempExec; i++){
                    fila.front().tempoExecucao--;
                    cout << "Tempo: " << tempoAtual <<  " - Executou processo " << fila.front().nome << " (TR = " <<  fila.front().tempoExecucao << ").\n";
                    verificarProntosRR(lista, tempoAtual, fila);
                    tempoAtual++;
                }
                fila.pop();

            } else {
                for(int i=0; i<quantum; i++){
                    fila.front().tempoExecucao--; 
                    cout << "Tempo: " << tempoAtual <<  " - Executou processo " << fila.front().nome << " (TR = " <<  fila.front().tempoExecucao << ").\n";
                    verificarProntosRR(lista, tempoAtual, fila);
                    tempoAtual++;
                }
                fila.push(fila.front());
                fila.pop();
            }

        } else {
            tempoAtual++;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese"); // Configura a localidade para português para formatar a saída

    int opcao; // Variável para armazenar a opção do usuário
    do {
        // Menu de seleção de escalonador
        cout << "Escolha um escalonador:" << endl;
        cout << "1. SRT (Shortest Remaining Time)" << endl;
        cout << "2. RR (Round-Robin)" << endl;
        cout << "3. Sair\n" << endl;

        cout << "Escolha: ";
        cin >> opcao; // Lê a escolha do usuário
        switch (opcao) {
            case 1:
                srt(); // Chama a função SRT
                break;
            case 2:
                rr(); // Chama a função RR (ainda não implementada)
                break;
            case 3:
                cout << "Programa de escalonamento fechado." << endl; // Mensagem de saída
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl; // Mensagem para opções inválidas
                break;
        }
    } while (opcao != 3); // Continua até o usuário escolher sair

    return 0; // Finaliza o programa
}
