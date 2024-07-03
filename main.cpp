#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

int main() {
    
    int tam = 10;
    list<int> aula, teste; //declarando lista
    list<int>::iterator it; //inserir valor em um determinado endereco da lista
    
    teste.push_front(10);
    teste.push_front(11);
    teste.push_front(12);
    teste.push_front(13);
    
    /*  int t;
    
    cin >> t;
    
    aula.push_front(t);
    aula.push_front(5);
    aula.push_front(7);
    aula.push_front(8);
    aula.push_front(10);
    aula.push_front(1);
    aula.push_front(0);
    aula.push_front(6);
    aula.push_front(9);
    aula.push_front(3); */
    
     for (int i = 0; i < tam; i++) {
        aula.push_front(i); //inserindo no início da lista 
    }
    
    // it=aula.begin(); // recebendo inicio
    // advance(it, 7); // inserindo na posicao
    // aula.insert(it, 0); // inserindo de fato o valor 
    
    it=aula.begin(); // recebendo inicio
    advance(it, 3); // inserindo na posicao
    aula.insert(it, 0); // inserindo de fato o valor
    aula.erase(--it); // apaga o valor da posicao (-- pre-decrementando, se nao usar -- remove por ultimo)
    
    // aula.clear(); // remove todos os elementos da lista (outra forma é usar do while ou while ate ficar vazia)
    aula.merge(teste); // aula recebe os elementos da lista teste
    
    cout << "Tamanho da lista: " << aula.size() << "\n\n";
    
    //  aula.sort(); // ordena em ordem caso tivesse desordenado
    // aula.reverse(); // ordena na ordem inversa depois de ordenado usando sort
    
    
    tam=aula.size(); // retorna tamanho da lista
    
    for (int i = 0; i < tam; i++) {
        cout << aula.front() << "\n"; // imprime elemento da frente (back no final)
        aula.pop_front(); // e em seguida retira da frente e joga para final da lista
    }
    
    cout << "Tamanho da lista: " << aula.size() << "\n\n";  // zera pois já foi impressa
    
    return 0;
}