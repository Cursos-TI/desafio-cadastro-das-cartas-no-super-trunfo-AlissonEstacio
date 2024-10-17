#include <stdio.h>

typedef struct {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int num_pontos_turisticos;
} Cidade;

void exibir_dados(Cidade cidade) {
    printf("Código: %s\n", cidade.codigo);
    printf("População: %d\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: R$ %.2f\n", cidade.pib);
    printf("Número de Pontos Turísticos: %d\n", cidade.num_pontos_turisticos);
    printf("--------------------------\n");
}

int main() {
    Cidade cidades[32]; // 8 estados x 4 cidades
    int count = 0;

    while (1) {
        printf("Digite o estado (A-H): ");
        char estado;
        scanf(" %c", &estado);

        printf("Digite o número da cidade (01-04): ");
        char cidade_num[3];
        scanf("%s", cidade_num);
        
        sprintf(cidades[count].codigo, "%c%s", estado, cidade_num);
        
        printf("Digite a população: ");
        scanf("%d", &cidades[count].populacao);
        
        printf("Digite a área (em km²): ");
        scanf("%f", &cidades[count].area);
        
        printf("Digite o PIB: ");
        scanf("%f", &cidades[count].pib);
        
        printf("Digite o número de pontos turísticos: ");
        scanf("%d", &cidades[count].num_pontos_turisticos);

        char continuar;
        printf("Deseja cadastrar outra cidade? (s/n): ");
        scanf(" %c", &continuar);
        if (continuar != 's') {
            break;
        }
    }

    printf("\nDados das Cidades Cadastradas:\n");
    for (int i = 0; i < count; i++) {
        exibir_dados(cidades[i]);
    }

    return 0;
}