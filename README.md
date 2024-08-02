# Relatório: Algoritmos de Escalonamento (SRT e RR)

##### Integrantes: 
+ Lucas Samuel Dias
+ Andreia
+ Nathália

##### Curso: 
+ ADS - Análise e Desenvolvimento de Sistemas

##### Professor: 
+ Gilerto Viana de Oliveira
  
## Descrição do projeto

<p align="justify">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;O trabalho consiste em aplicar os algoritmos de escalonamento mostrados em sala de aula, criando uma espécie de simulação de uso destes algoritmos: SRT e RR (Round. Para isso, os alunos deverão se organizar em grupos e atender os requisitos de execução e apresentação solicitados pelo professor.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Os algoritmos a serem desenvolvidos irão simular os escalonadores Shortest Remaining Time First (SRT) e Round-Robin (RR) sendo que as entradas serão manuais no início do programa conforme orientação prévia.
A linguagem de programação escolhida para o desenvolvimento do presente projeto é C++.
</p>

## Estrutura compartilhada entre SRT e RR

<p align="justify">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Na main do nosso programa de escalonamento, há um laço de repetição que sempre executa no mínimo uma vez. Nele há um switch em que é pedido uma entrada do usuário em relação a qual algoritmo de escalonamento será executado, puxando, dessa forma, o bloco de código em que há nessas funções, as quais são: srt() e void rr(), as quais, não possuem retorno.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;É possível a saída do programa de maneira não forçada, como quando um determinado escalonador é finalizado. Desse modo, o usuário poderá escolher finalizar o programa. E, se ele digitar alguma opção inválida dentre as disponpiveis, o laço se repetirá até alguma dentre as três opções seja escolhida, conforme é demonstrado na figura 1.
</p>

~~~c++
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
                cout << "Opção inválida. Tente novamente." << endl; // Mensagem para opções inválidas
                break;
        }
    } while (opcao != 3); // Continua até o usuário escolher sair

    return 0; // Finaliza o programa
}
~~~

<p align="center", color='blue'>
Figura 1
</p>

<p align="justify">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Para cada processo lido, deverá ser armazenado o nome, o tempo de chegada e tempo de execução realizada pela CPU. Para a leitura desses dados, utilizamos o tipo abstrato de dados (TAD), conhecido como struct. Por meio dessa struct, que chamamos de Processo, será solicitado ao usuário a entrada dos dados necessários para os algoritmos RR e SRT, conforme a ilustração da Figura 2.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Essa struct será implementada na bloco de código das funções void srt() e rr().
</p>

~~~c++
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
        cout << "Tempo de execução: ";
        cin >> tempoExecucao; // Lê o tempo de execução do processo
    }
};
~~~
<p align="center", color='blue'>
Figura 2
</p>

<p align="justify">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Para o armazenamento dos dados lidos em nosso programa, dentro da função void srt() e rr(), utilizamos o array chamado vector, que possui como tipo nosso TAD Processo, denominado lista. Dentro da função há um laço de repetição while, que pede ao usuário se ele deseja adicionar um processo, quantas vezes ele desejar. (No entanto, o limite máximo instruído pelo professor fora de 15 processos.) Caso a condição seja atendida, é criado um novo processo, recebe-se seus dados relativos (nome, tempo de chegada e tempo de execução) e inserido no final da lista, senão simplesmente sai do laço, conforme é demonstrado no código da Figura 3.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Como a estrutura inicial do bloco de código da função void srt() é idêntico ao do void rr(), evitamos duplicá-lo no relatório por quesitos de redundância e poluição visual.
</p>

~~~c++
// Função de escalonamento Shortest Remaining Time (SRT)
void srt() { // void rr() funciona da mesma maneira a parte de adicionar processos
    vector<Processo> lista; // Lista para armazenar os processos
    int resp; // Variável para armazenar a resposta do usuário

    // Loop para adicionar processos
    while (true) {
        cout << "\nVocê deseja adicionar um processo?\n";
        cout << "1 - Sim\n2 - Não\n\n";
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
~~~

<p align="center", color='blue'>
Figura 3
</p>

# Estrutura exclusiva do SRT

<p align="justify">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Finalizadas as entradas dos n processos do algoritmo SRT, implementa-se a função com retorno: boolean ordenarSRT(Processo a, Processo b), na qual recebe-se da struct Processo há a passagem de dois parâmetros relativos aos processos armazenados no vector Lista. E, com isso, far-se-á a comparação para ordenação.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;O critério estabelecido para a lista será por ordem de menor tempo de chegad, e para efeito de desempate é utilizado o menor tempo de execução dos processos. Caso o tempo de chegada e execução forem os mesmos, dá-se preferência pelo nome do processo inserido pelo usuário inicialmente.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Tais eventos são conforme denotado na Figura 4.
</p>

~~~c++
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
~~~

<p align="center", color='blue'>
Figura 4
</p>

<p align="justify">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Retornando ao bloco de código da funcão SRT, passa-se via parâmetro na função sort, a função ordenarSRT. É ordenado do início ao fim da lista os processos presentes, conforme fora já explicitado anteriormente, seguindo critérios de ordem de chegada e tempo de execução.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A seguir, há um laço de repetição while que se repete enquanto a lista não estiver vazia. Inicia-se o menor tempo de execução como valor máximo inteiro e inicia-se a posição atual como inválida, ou sseja, menor que 1.
</p>

~~~c++
    // Ordena a lista de processos pelo tempo de chegada, execução e nome
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
            cout << "\nProcesso: " << lista[posAtual].nome << ". Tempo: " << tempoAtual << ".";
            if (lista[posAtual].tempoExecucao == 0) {
                // Se o tempo de execução do processo chegar a zero, o processo terminou
                cout << "\nProcesso " << lista[posAtual].nome << " terminou no tempo " << tempoAtual << ".";
                lista.erase(lista.begin() + posAtual); // Remove o processo da lista
            }
        }
        tempoAtual++; // Incrementa o tempo atual
    }
    cout << endl << endl;
}
~~~

<p align="center", color='blue'>
Figura 5
</p>

Métodos

