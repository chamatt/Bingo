#include "tGeradorAle.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_NAO_REPETIDO 1000
#define MAX_NUM_REPETIDO 32767

typedef struct{
    int numeros[MAX_NUM_NAO_REPETIDO];
    int qtdNumeros;
} tGeradorAle;

static tGeradorAle gerador;
static unsigned long int next = 1;

int GeraNumeroComRepeticao(void) 
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next/65536) % (MAX_NUM_REPETIDO+1);
}

void ReiniciaGerador(unsigned int semente, int qtdNumeros) 
{
    int i;
    
    if (qtdNumeros > MAX_NUM_REPETIDO){
        printf("qtdNumeros deve ser menor ou igual a %d", MAX_NUM_REPETIDO);
        exit(1);
    }
    
    next = semente;
    gerador.qtdNumeros = qtdNumeros;
    for(i = 0; i < qtdNumeros; i++){
        gerador.numeros[i] = i+1;
    }
}

int GeraProxNumero(void) 
{
    int num;
    int aux;
    
    if (gerador.qtdNumeros <= 0){
        printf("Voce fez mais chamadas a GeraProxNumero do que a quantidade de numeros definida na ReiniciaGerador!");
        exit(1);
    }
    
    num = GeraNumeroComRepeticao() % (gerador.qtdNumeros);
    aux = gerador.numeros[num];
    gerador.numeros[num] = gerador.numeros[gerador.qtdNumeros-1];
    gerador.qtdNumeros--;
    
    return aux;
}