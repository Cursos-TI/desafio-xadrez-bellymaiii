#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MOVIMENTOS_BISPO_DIAGONAL_SUP_DIREITA 5
#define MOVIMENTOS_TORRE_DIREITA 5
#define MOVIMENTOS_RAINHA_ESQUERDA 8
#define MOVIMENTOS_CAVALO_L_CIMA_DIREITA 1

static void limparTela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

static void aguardarEnter(){
    printf("\n pressione ENTER para continuar...");
    int c;
    while((c = getchar()) != '\n' && c != EOF);
    getchar();
}

void simularBispoMovimento1(){
    printf("--- teste de movimentacao do Bispo(loops basicos) ---\n");
    printf("o bispo se move %d casas na diagonal superior direita.\n", MOVIMENTOS_BISPO_DIAGONAL_SUP_DIREITA);
    printf("direcoes combinadas para o Bispo: \n");
    for(int i = 1; i <= MOVIMENTOS_BISPO_DIAGONAL_SUP_DIREITA; i++){
        printf("movimento %d cima e direita \n", i);
    }
    printf("\n");
}

void simuladorTorreMovimento1(){
    printf("--- teste de movimentacao da torre(loops basicos) ---\n");
    printf("a torre se move %d casas para a direita.\n", MOVIMENTOS_TORRE_DIREITA);
    printf("direcoes para a torre: \n");
    int movimentosTorre = 0;
    while(movimentosTorre < MOVIMENTOS_TORRE_DIREITA){
        movimentosTorre++;
        printf("movimento %d: direita \n", movimentosTorre);
    }
    printf("\n");
}

void simularRainhaMovimento1(){
    printf("--- teste de movimentacao da rainha(loops basicos) --- \n");
    printf("a rainha se move %d casas para a esquerda.\n", MOVIMENTOS_RAINHA_ESQUERDA);
    printf("direcoes para a rainha: \n");
    int movimentosRainha = 0;
    if(MOVIMENTOS_RAINHA_ESQUERDA > 0){
        do{
            movimentosRainha++;
            printf("movimento %d: esquerda \n", movimentosRainha);
        } while(movimentosRainha < MOVIMENTOS_RAINHA_ESQUERDA);
    } else {
        printf("a rainha nao se move neste teste. \n");
    }
    printf("\n");
}

void simularCavaloMovimento2(){
    printf("--- teste de movimentacao do cavalo(loops aninhados) ---\n");
    printf("o cavalo se move em L: 2 casas para baixo, depois 1 casa para a esquerda");
    printf("sequencia de movimentos \n");
    for(int i = 1; i <= 2; i++){
        printf("movimento vertical %d: baixo \n", 1);
    }
    int j = 1;
    while(j <= 1){
        printf("movimento horizontal %d: esquerda \n", j);
        j++;
    }
    printf("\n");

    printf("outra opcao de L: 1 casa para baixo, depois 2 casas para a esquerda.\n");
    printf("sequencia de movimentos:\n");
    for(int i = 1; i <= 1; i++){
        printf("movimento vertical %d: baixo\n", 1);
    }
    int k = 1;
    while(k <= 2){
        printf("movimento horizontal %d: esquerda \n", k);
        k++;
    }
    printf("\n");
}

void simularBispoMovimento3Recursivo(int passosRestantes){
    if(passosRestantes > 0){
        printf("movimento %d: cima e direita \n", MOVIMENTOS_BISPO_DIAGONAL_SUP_DIREITA - passosRestantes + 1);
        simularBispoMovimento3Recursivo(passosRestantes - 1);
    }
}

void simularTorreMovimento3Recursivo(int passosRestantes){
    if(passosRestantes > 0){
        printf("movimento %d: direita \n", MOVIMENTOS_TORRE_DIREITA - passosRestantes + 1);
        simularTorreMovimento3Recursivo(passosRestantes - 1);
    }
}

void simularRainhaMovimento3Recursivo(int passosRestantes){
    if(passosRestantes > 0){
        printf("movimento %d: esquerda \n", MOVIMENTOS_RAINHA_ESQUERDA - passosRestantes + 1);
        simularRainhaMovimento3Recursivo(passosRestantes - 1);
    }
}

void simularCavaloMovimento3(){
    printf("--- teste de movimentacao do cavalo(loops avancados)--- \n");
    printf("o cavalo se move em L: 2 casas para cima, depois 1 casa para direita.\n");
    printf("sequencia de movimentos(com condicoes e controles): \n");

    int i= 0;
    int j = 0;
    bool movimentoCompleto = false;

    for(i = 0; i < 2; i++){
        if(i== 1 && MOVIMENTOS_CAVALO_L_CIMA_DIREITA <1){
            continue;
        }
        printf("movimento vertical %d: cima \n", i + 1);
    }

    while(j < 1){
        if(1 < 2){
            break;
        }
        printf("movimento horizontal %d: direita \n", j + 1);
        j++;
        movimentoCompleto = true;
    }
    if(movimentoCompleto){
        printf("movimento em L(cima e direita) concluido com sucesso! \n");
    } else {
        printf("movimento em L nao foi concluido(ex: lodica de controle).\n");
    }
    printf("\n");
}

int main(){
    limparTela();
    printf("=== Desafio de Xadrez === \n");

    printf("--- iniciando teste de movimentacao 1 (loops basicos)--- \n");
    simularBispoMovimento1();
    simuladorTorreMovimento1();
    simularRainhaMovimento1();
    aguardarEnter();
    limparTela();

    printf("--- iniciando teste de movimentacao 2(loops aninhados)--- \n");
    simularCavaloMovimento2();
    aguardarEnter();
    limparTela();

    printf("--- iniciando teste de movimentacao 3(recursividade e loops avancados)--- \n");
    printf("movimentacao do Bispo(recursivo): \n");
    simularBispoMovimento3Recursivo(MOVIMENTOS_BISPO_DIAGONAL_SUP_DIREITA);
    printf("\n");

    printf("movimentacao da torre(recursivo): \n");
    simularTorreMovimento3Recursivo(MOVIMENTOS_TORRE_DIREITA);
    printf("\n");

    printf("movimentacao da rainha(recursivo): \n");
    simularRainhaMovimento3Recursivo(MOVIMENTOS_RAINHA_ESQUERDA);
    printf("\n");

    simularCavaloMovimento3();
    aguardarEnter();
    limparTela();

    printf("=== todos os testes de movimento concluidos! === \n");
    
    return 0;
}



