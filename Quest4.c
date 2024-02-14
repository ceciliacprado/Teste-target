#include <stdio.h>

/*Questão 4: Dado o valor de faturamento mensal de uma distribuidora, detalhado por estado:
SP – R$67.836,43
RJ – R$36.678,66
MG – R$29.229,88
ES – R$27.165,48
Outros – R$19.849,53
Escreva um programa na linguagem que desejar onde calcule o percentual de 
representação que cada estado teve dentro do valor total mensal da distribuidora.*/

int main() {

    float faturamento_sp = 67836.43;
    float faturamento_rj = 36678.66;
    float faturamento_mg = 29229.88;
    float faturamento_es = 27165.48;
    float faturamento_outros = 19849.53;

    float total = faturamento_sp + faturamento_rj + faturamento_mg + faturamento_es + faturamento_outros;

    float percentual_sp = (faturamento_sp / total) * 100;
    float percentual_rj = (faturamento_rj / total) * 100;
    float percentual_mg = (faturamento_mg / total) * 100;
    float percentual_es = (faturamento_es / total) * 100;
    float percentual_outros = (faturamento_outros / total) * 100;

    printf("Percentual de representacao por estado:\n");
    printf("SP: %.2f%%\n", percentual_sp);
    printf("RJ: %.2f%%\n", percentual_rj);
    printf("MG: %.2f%%\n", percentual_mg);
    printf("ES: %.2f%%\n", percentual_es);
    printf("Outros: %.2f%%\n", percentual_outros);

    return 0;
}
