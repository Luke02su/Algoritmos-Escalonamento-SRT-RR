# Relatório: Algoritmos de Escalonamento (SRT e RR)
  
## Descrição do projeto

<p align="justify">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;O trabalho consiste em aplicar os algoritmos de escalonamento mostrados em sala de aula, criando uma espécie de simulação de uso destes algoritmos: Shortest Remaining Time First (SRT) e Round-Robin (RR). Para isso, os alunos deverão se organizar em grupos e atender aos requisitos de execução e à apresentação solicitados pelo professor.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Os algoritmos a serem desenvolvidos irão simular os escalonadores SRT e RR, sendo que as entradas serão manuais no início do programa, conforme orientação prévia.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A linguagem de programação escolhida para o desenvolvimento do presente projeto é C++, na qual utilizamos struct, array, lista, fila, dentre outros conceitos correlacionados. Há outros métodos mais simples e mais complexos que os demonstrados aqui.
</p>

##### Integrantes: 
+ [Lucas Samuel Dias](https://github.com/luke02su)
+ Andreia
+ [Nathália Beatriz](https://github.com/nathaliabeatriz)

##### Curso: 
+ ADS - Análise e Desenvolvimento de Sistemas

##### Professor: 
+ [Gilberto Viana de Oliveira](https://github.com/gvoliveira)

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
<br>

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
<br>
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
<br>

## Estrutura exclusiva do SRT

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
<br>
<p align="justify">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Retornando ao bloco de código da funcão SRT, passa-se via parâmetro na função sort, a função ordenarSRT. É ordenado do início ao fim da lista os processos presentes, conforme fora já explicitado anteriormente, seguindo critérios de ordem de chegada e tempo de execução.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A seguir, há um laço de repetição while que se repete enquanto a lista não estiver vazia. Inicia-se o menor tempo de execução como valor máximo inteiro e inicia-se a posição atual como menor que 0, pois os os processos iniciam-se em no mínimo 0, e o tempo atual em 0. Procura-se o menor tempo de execução restante que já tenha chegado na CPU, por meio de laço de repetiçao determinado (for) e condicionais (if). Atualiza-se o menor tempo de execução e a posição o processo com menor tempo de execução, caso o tempo de chegada seja menor ou igual ao tempo atual, laço é interrompido.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Para executar, ou seja, imprimir a ordenção dos processos, há uma condição na qual a posição deve ser maior ou igual a 0. O tempo de execução total do processo x é decrementado. Os detalhes do processo são, por fim impresso. E, quando seu tempo de execução zerar, imprime-se o término e limpa-se ele da lista.
Por fim, incrementa-se o tempo atual.</p>

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
<br>

<p align="justify">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Na função booleana ordenarRR(Processo a, Processo b), passa-se os parâmetros do tempo de chamada do primeiro processo e o do seguinte. Há uma condição na qual compara-se o tempo de chegada do processo a com o processo b. Caso seja igual, retorna-se o processo que teve o primeiro nome inserido, ou seja, o a. Caso contrário, retorna-se o processo que possui o menor tempo de chegada, ou seja, o a.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A dinâmica desse bloco de código possui uma estrutura semelhante ao do SRT entretanto, é mais simples, pois considera apenas o tempo de chegada, não levando em conta o tempo de execução, conforme é ilustrado na Figura 6.
</p>

~~~c++
// Função para ordenar os processos para o algoritmo Round-Robin (RR)
bool ordenarRR(Processo a, Processo b){
    if(a.tempoChegada == b.tempoChegada){
        return a.nome < b.nome; // Ordena os processos com o mesmo tempo de chegada pelo nome
    }
    return a.tempoChegada < b.tempoChegada; // Ordena os processos pelo menor tempo de chegada
}
~~~

<p align="center", color='blue'>
Figura 6
</p>
<br>

<p align="justify">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Na função void verificarProntosRR(...), que será chamada na função rr(), verifica-se se os processos estão prontos para serem adicionados à fila, na qual ordena-se pela ordem de chegada. Os parâmetros passados por referência são relacionados à lista e à fila, com exeção do tempo atual. Enquanto a lista o tempo de chegada de um processo x for menor ou igual ao tempo atual transcorrido, ele é adicionado à fila e apagado da lista. Caso tal condição não seja atendida, sai-se do laço for, conforme é denotado na Figura 7. 
</p>

~~~c+++
// Função para verificar e mover processos prontos para a fila para o algoritmo Round-Robin (RR)
void verificarProntosRR(vector<Processo> &lista, int tempoAtual, queue<Processo>&fila){
    for(int i=0; i<(int)lista.size(); i++){
        if(lista[i].tempoChegada <= tempoAtual){
            fila.push(lista[i]); // Adiciona o processo à fila
            lista.erase(lista.begin() + i); // Remove o processo da lista
        } else {
            break; // Interrompe o loop se os processos ainda não chegaram
        }
    }
}
~~~

<p align="center", color='blue'>
Figura 7
</p>
<br>

<p align="justify">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Após ser executado o bloco de código idêntico ao SRT, referente à escolha do usuário, pede-se o quantum de processamento. Em seguida, ordena-se a lista em seguida, do mesmo modo que o SRT. Cria-se uma fila (queue) para armazenar os processos prontos, indo para o final da fila. Há um laço de repetição que roda enquanto a lista e a fila estiverem vazias. Nele move-se, os processos para a fila. Caso a fila não esteja vazia e o quantum inserido pelo usuário seja maior que o tempo de execução de um processo do início da fila, o tempo de execução temporário do processo atual recebe tal processo da fila. E, enquanto o tempo de execução temporário não for percorrido por completo, imprime-se a fila de processos prontos. Decrementa-se o tempo de execução do processo atual e incrementa o tempo atual. Por fim, move-se novos processos prontos para a fila e apaga-se o processo da fila.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Caso o quantum seja menor que o processo total de execução atual da fila, transcorre-se o processo atual enquanto for menor que o quantum, imprimindo-o. E decrementa-se o tempo de execução do processo da fila e aumenta-se o tempo atual transcorrido. Novamente, verifica-se os processos prontos, movendo-os para a fila. coloca-se o processo de volta para a fila e remove-se o processo da fila. E, se a lista ou a fila não estiverem vazias, aumenta-se o tempo atual, conforme é situado na Figura 8.
</p>

<p align="center", color='blue'>
Figura 8
</p>
<br>

~~~c++ 
    int quantum; // Tempo fixo de execução para cada processo
    cout << "Digite o quantum de processamento:\n";
    cin >> quantum; // Lê o valor do quantum

    sort(lista.begin(), lista.end(), ordenarRR); // Ordena a lista de processos pelo tempo de chegada e outros critérios

    queue<Processo>fila; // Fila para armazenar processos prontos

    int tempoAtual = 0; // Inicializa o tempo atual
    while(!lista.empty() || !fila.empty()){
        verificarProntosRR(lista, tempoAtual, fila); // Move processos prontos para a fila

        if(!fila.empty()){
            if(quantum > fila.front().tempoExecucao){
                int tempExec = fila.front().tempoExecucao; // Tempo de execução do processo atual
                for(int i=0; i<tempExec; i++){
                    cout << "Processo " << fila.front().nome << ". Tempo: " << tempoAtual << ".\n";
                    fila.front().tempoExecucao--; // Decrementa o tempo de execução do processo
                    tempoAtual++; // Incrementa o tempo atual
                }
                verificarProntosRR(lista, tempoAtual, fila); // Move novos processos prontos para a fila
                fila.pop(); // Remove o processo da fila

            } else {
                for(int i=0; i<quantum; i++){
                    cout << "Processo " << fila.front().nome << ". Tempo: " << tempoAtual << ".\n";
                    fila.front().tempoExecucao--; // Decrementa o tempo de execução do processo
                    tempoAtual++; // Incrementa o tempo atual
                }
                verificarProntosRR(lista, tempoAtual, fila); // Move novos processos prontos para a fila
                fila.push(fila.front()); // Coloca o processo de volta na fila
                fila.pop(); // Remove o processo da fila
            }

        } else {
            tempoAtual++; // Incrementa o tempo atual se a fila estiver vazia
        }
    }
}
~~~

## Métodos de validação

<p align="center", color='blue'>
Figura 8
</p>
<br>

<p align="justify">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Para validarmos a lógica dos escalonadores SRT e RR, buscamos compreender melhor como funcionava tais algoritmos por meio de vídeos explicativos situados no YouTube por outros professores e alunos. À princípio, o escalonador SRT fora entendido e aplicado com maior facilidade pelos integrantes, em que o processo com o menor tempo de execução, atrelado ao tempo no qual chegou, é priorizado. Quanto ao RR, priorizado pelo tempo de chegada, houve-se uma dificuldade maior de aplicação e entendimento devido ao quantum e o retorno para a fila de prontos, pois nos vídeos vistos parecia haver uma consonânscia entre eles referente aos últimos processos que retornam para o final da fila ao excederem o quantum.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Desse modo, utilizamos três testes, os quais estão presentes nesses vídeos. O primeiro corroborou com a funcionalidade do SRT, já o segundo houve uma certa mudança de posição (embora pensamos que possa ser devido ao início do tempo atual, 0 ou 1, ou seja, sendo uma questão interpretativa) e o terceiro validou o RR.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Logo abaixo há as Figuras 9, 10 e 11 exemplos que foram utilizados para aferir os algoritmos de escalonamento.
</p>

