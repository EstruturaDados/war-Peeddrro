#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define territorio_max 5
#define str_max 30

//Definindo a Estrutura
typedef struct {
    char nome[str_max];
    char cor[10];
    int tropas;
} Territorio;

//Criando a Funcao de Ataque
void Ataque(Territorio* Atacante, Territorio* Defensor){
    //Dados para cada acao
    int attack = 1 + rand() % 6;
    int block = 1 + rand() % 6;
   
    printf("\n---%s ATACOU %s---\n", Atacante->nome, Defensor->nome);
    printf("%s(Atacante) tirou: %d\n", Atacante->nome, attack);
    printf("%s(Defensor) tirou: %d\n", Defensor->nome, block);


    Territorio* Vencedor = NULL;
    Territorio* Perdedor = NULL;

    if (attack > block){
        printf("\nResultado: O ATACANTE %s VENCEU ESTA RODADA!!\n", Atacante->nome);
        Vencedor = Atacante;
        Perdedor = Defensor;
        Perdedor->tropas--;
    } else if (block > attack){
        printf("\nResultado: O DEFENSOR %s VENCEU ESTA RODADA!!\n", Defensor->nome);
        Vencedor = Defensor;
        Perdedor = Atacante;
        Perdedor->tropas--;
    } else{
        printf("\nResultado: EMPATE... A VITORIA VAI PARA O DEFENSOR %S\n", Defensor->nome);
        Vencedor = Defensor;
        Perdedor = Atacante;
        Perdedor->tropas--;
    }

    if(Perdedor->tropas == 0){
        printf("\n============================================\n");
        printf("O TERRITORIO %s FOI DOMINADO POR %s!!!!\n", Perdedor->nome, Vencedor->nome);
        printf("\n============================================\n");

        strcpy(Perdedor->cor, Vencedor->cor);
    } 
}

//Funcao para limpar o buffer de entrada
void ClearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
};

//Funcao Principal
int main(){
    //gerador de numeros pseudo aleatorios
    srand(time(NULL));

    Territorio *paises;
    paises = (Territorio *)calloc(territorio_max, sizeof(Territorio));
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

    printf("\n============================================");
    printf("\nMAPA MUNDO\n");

    int NumAtacante, NumDefensor;
    int indice_Atacante, indice_Defensor;

    //Inicia um loop infinito
    while (1) { 
        //Mostra o Mapa Mundo + Listagem Atualizada das tropas
        for (int i = 0; i < TotalPais; i++){
        printf("\n%d - %s (Exercito %s, Tropas %d)\n", i + 1, paises[i].nome, paises[i].cor, paises[i].tropas);
    }       
        printf("\n---FASE DE ATAQUE---\n");
        printf("Escolha o Territorio Atacante (1 a 5, ou 0 para sair): ");
        scanf("%d", &NumAtacante);
        ClearBuffer();

        //Finaliza o Loop
        if (NumAtacante == 0){
            printf("\n Fase de Ataque Finalizada\n");
            break;
        }
        
        printf("Escolha o Territorio Defensor (1 a 5, ou 0: ");
        scanf("%d", &NumDefensor);
        ClearBuffer();

        indice_Atacante = NumAtacante - 1;
        indice_Defensor = NumDefensor - 1;

        Territorio* Atacante = &paises[indice_Atacante];
        Territorio* Defensor = &paises[indice_Defensor];

        if (NumAtacante < 1 || NumAtacante > TotalPais || NumDefensor < 1 || NumDefensor > TotalPais){
            printf("\nOPCAO INVALIDA... TERRITORIOS DA MESMA COR NAO PODEM SE ATACAR!!\n");
            continue; 
        } else if (NumAtacante == NumDefensor){
            printf("\nPCAO INVALIDA. NAO SE PODE ATACAR O PROPRIO TERRITORIO\n");
            continue;
        } else if (strcmp(Atacante->cor, Defensor->cor) == 0) {
            printf("\nOPCAO INVALIDA... TERRITORIOS DA MESMA COR NAO PODEM SE ATACAR!!\n");
            continue;
        }

        Ataque(Atacante, Defensor);
        
    }
    
    free(paises);

    return 0;

}
