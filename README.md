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

O trabalho consiste em aplicar os algoritmos mostrados em sala, criando uma espécie de simulação de uso desses algoritmos. Para isso, os alunos deverão se organizar em grupos e atender os requisitos de execução e apresentação solicitados pelo professor.
Os algoritmos a serem desenvolvidos irão simular os escalonadores Round-Robin e SRT, sendo que as entradas serão manuais no início do programa conforme orientação prévia.
A linguagem de programação escolhida para o desenvolvimento do presente projeto é C++.

## Algoritmo SRT

Para cada processo lido, deverá ser armazenado o nome, o tempo de processamento pela CPU e o tempo de chegada do mesmo. Para a leitura desses dados, utilizamos o tipo abstrato de dados Struct. Através dessa Struct que chamamos de Processo, será solicitado ao usuário a entrada dos dados necessários para os algoritmos Round-Robin e SRT conforme ilustração da Figura 1.

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

								##### Figura 1

Figura 1
Para o armazenamento dos dados lidos em nosso programa, utilizamos o array chamado Vector que possui como tipo nossa TAD Processo e como nome de lista. Esse vector é chamado na main do programa, conforme apresentado na Figura 2.

Figura 2
	Ainda na main, se inicia uma estrutura de repetição while para que possa ser efetuada a entrada de um ou mais processos de acordo com o desejado pelo usuário. O limite máximo de processos aceitos no programa que foi orientado pelo professor é de 15 processos.
	Finalizadas as entradas dos processos, há um método dentro da Struct Processo que receberá como parâmetro dois processos armazenados em nosso vector Lista e fará a comparação para ordenação. A lista será por ordem de menor tempo de chegada e para efeito de desempate é utilizado o tempo de execução dos processos.

Figura 3
A função na main que executa a ordenação está descrita na Figura 4.

Figura 4
Após entradas e ordenação feitas, a simulação do algoritmo SRT executa, de acordo com a Figura 5:

Figura 5

