#include <stdio.h>

/*Questão 2: Dado a sequência de Fibonacci, onde se inicia por 0 e 1 e o próximo valor sempre será a 
soma dos 2 valores anteriores (exemplo: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34...), escreva um programa na linguagem 
que desejar onde, informado um número, ele calcule a sequência de Fibonacci e retorne uma mensagem avisando 
se o número informado pertence ou não a sequência.*/

int main() {
    int n, a = 0, b = 1, temp, pertence = 0;

    printf("Digite um número: ");
    scanf("%d", &n);

    while (b <= n) {
        if (b == n) {
            pertence = 1;
            break;
        }
        temp = b;
        b = a + b;
        a = temp;
    }

    if (pertence)
        printf("O número %d pertence à sequência de Fibonacci.\n", n);
    else
        printf("O número %d não pertence à sequência de Fibonacci.\n", n);

    return 0;
}

