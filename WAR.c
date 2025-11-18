#include <stdio.h>
#include <string.h>

#define territorio_max 5
#define str_max 30

// Definindo a Estrutura
struct Territorio {
    char nome[str_max];
    char cor[10];
    int tropas;
};

//Funcao para limpar o buffer de entrada
void ClearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
};

//Funcao Principal
int main(){
    struct Territorio paises [territorio_max];
    int TotalPais = 0;

    //Cadastro dos Territorios
    printf("\nHora de Cadastrar os 5 Territorios!!\n");

    for (int i = 0; i < territorio_max; i++){
        printf("\nCadastro do Territorio %d", i + 1);
        printf("\nInsira o Nome do Territorio: ");
        fgets(paises[TotalPais].nome, str_max, stdin);
        printf("Insira a Cor do Territorio: ");
        fgets(paises[TotalPais].cor, str_max, stdin);

        paises[TotalPais].nome[strcspn(paises[TotalPais].nome, "\n")] = '\0';
        paises[TotalPais].cor[strcspn(paises[TotalPais].cor, "\n")] = '\0';

        printf("Insira a Quantidade de Tropas Que o Territorio Possui: ");
        scanf("%d", &paises[TotalPais].tropas);
        ClearBuffer();
        TotalPais++;
    };

    //Exibindo os 5 Territorios
    printf("\n==============================================");
    printf("\nMAPA MUNDO\n");
    for (int i = 0; i < TotalPais; i++){
        printf("\nTerritorio %d: ", i + 1);
        printf("Nome: %s\n", paises[i].nome);
        printf("Dominado por: Exercito %s\n", paises[i].cor);
        printf("Tropas: %d\n", paises[i].tropas);
    };

}
