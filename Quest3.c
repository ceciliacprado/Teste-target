#include <stdio.h>

/*Questao 3: Dado um vetor que guarda o valor de faturamento diário de uma distribuidora, faça um programa, na linguagem que desejar, que calcule e retorne:
• O menor valor de faturamento ocorrido em um dia do mês;
• O maior valor de faturamento ocorrido em um dia do mês;
• Número de dias no mês em que o valor de faturamento diário foi superior à média mensal.*/

#define TAMANHO_VETOR 31 

int main() {
    float faturamento_diario[TAMANHO_VETOR];
    float total_faturamento = 0;
    float menor_valor = __FLT_MAX__;
    float maior_valor = __FLT_MIN__;
    int dias_acima_media = 0;
    int dias_no_mes = 0;

    printf("Digite o faturamento diário para cada dia do mês:\n");
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        printf("Dia %d: ", i + 1);
        scanf("%f", &faturamento_diario[i]);
    }

  FILE *arquivo_json = fopen("faturamento.json", "r");
  if (!arquivo_json) {
      printf("Erro ao abrir o arquivo JSON.\n");
      return 1;
  }

  fseek(arquivo_json, 0, SEEK_END);
  long tamanho = ftell(arquivo_json);
  fseek(arquivo_json, 0, SEEK_SET);
  char *conteudo = (char *)malloc(tamanho + 1);
  fread(conteudo, 1, tamanho, arquivo_json);
  fclose(arquivo_json);
  conteudo[tamanho] = '\0';

  struct json_object *root = json_tokener_parse(conteudo);
  struct json_object *faturamento_array;
  json_object_object_get_ex(root, "faturamento_diario", &faturamento_array);

  int num_elementos = json_object_array_length(faturamento_array);
  for (int i = 0; i < num_elementos; i++) {
      struct json_object *obj = json_object_array_get_idx(faturamento_array, i);
      struct json_object *dia_obj, *valor_obj;
      json_object_object_get_ex(obj, "dia", &dia_obj);
      json_object_object_get_ex(obj, "valor", &valor_obj);
      int dia = json_object_get_int(dia_obj);
      float valor = json_object_get_double(valor_obj);
      faturamento_diario[dia - 1] = valor;
  }

    for (int i = 0; i < TAMANHO_VETOR; i++) {
        if (faturamento_diario[i] != 0) {
            total_faturamento += faturamento_diario[i];
            dias_no_mes++;
            if (faturamento_diario[i] < menor_valor) {
                menor_valor = faturamento_diario[i];
            }
            if (faturamento_diario[i] > maior_valor) {
                maior_valor = faturamento_diario[i];
            }
        }
    }

    float media_mensal = total_faturamento / dias_no_mes;

    for (int i = 0; i < TAMANHO_VETOR; i++) {
        if (faturamento_diario[i] > media_mensal) {
            dias_acima_media++;
        }
    }

    printf("Menor valor de faturamento: R$ %.2f\n", menor_valor);
    printf("Maior valor de faturamento: R$ %.2f\n", maior_valor);
    printf("Número de dias com faturamento acima da média mensal: %d\n", dias_acima_media);

  free(conteudo);
  json_object_put(root);

    return 0;
}
