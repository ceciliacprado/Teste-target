#include <stdio.h>
#include <string.h>

/*Questão 5:  Escreva um programa que inverta os caracteres de um string.
IMPORTANTE:
a) Essa string pode ser informada através de qualquer entrada de sua preferência ou pode ser previamente definida no código;
b) Evite usar funções prontas, como, por exemplo, reverse;*/

int main() {
    char string_original[100];
    char string_invertida[100];
    int tamanho, i, j;

    printf("Digite a string: ");
    fgets(string_original, sizeof(string_original), stdin);

    tamanho = strlen(string_original);

    if (string_original[tamanho - 1] == '\n') {
        string_original[tamanho - 1] = '\0';
        tamanho--;
    }

    for (i = 0, j = tamanho - 1; i < tamanho; i++, j--) {
        string_invertida[i] = string_original[j];
    }
    string_invertida[i] = '\0';

    printf("String invertida: %s\n", string_invertida);

    return 0;
}
