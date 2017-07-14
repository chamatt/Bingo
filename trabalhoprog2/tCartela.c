#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tCartela.h"
#include "tGeradorAle.h"

void CriarCartela(tCartela *a_cartela, int *id, int jogadorID, int linhas, int colunas, int pedras)
{
    int qntNumeros = linhas * colunas, i, j, k, proxNum;
    a_cartela->id = *id;
    a_cartela->linhas = linhas;
    a_cartela->colunas = colunas;
    a_cartela->jogadorDono = jogadorID;
    ReiniciaGerador(*id, pedras);
    int vetor[qntNumeros];
    for(i = 0; i < qntNumeros; i++)
    {
        proxNum = GeraProxNumero();
        vetor[i] = proxNum;
    }
    OrdenaVetor(vetor, qntNumeros);
    k = 0;
    for(int i = 0; i < colunas; i++)
    {
        for(j = 0; j < linhas; j++)
        {
            a_cartela->cartela[j][i] = vetor[k];
            k++;
        }
    } 
}

int ObterID(tCartela a_cartela);
void OrdenaVetor(int vet[], int qntNumeros)
{
    OrdemCrescente(vet, qntNumeros);
    //OrdemDecrescente(vet, qntNumeros);
}

int OrdemCrescente (int vetor[], int qntNumeros)
{
   int i, j, aux;
    for (i = 0; i < qntNumeros-1; i++) 
    {
        for (j = 0; j < qntNumeros-i-1; j++)
        {
            if (vetor[j] > vetor[j+1]) 
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}
int OrdemDecrescente (int vetor[], int qntNumeros)
{
   int i, j, aux;
    for (i = 0; i < qntNumeros-1; i++) 
    {
        for (j = 0; j < qntNumeros-i-1; j++)
        {
            if (vetor[j] < vetor[j+1]) 
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}

void ImprimirCartelaArquivo(tCartela *a_cartela, FILE* arqcartelas)
{
    int i, j;
    fprintf(arqcartelas, "Cartela ID:%d\n", a_cartela->id);
    for(i = 0; i < a_cartela->linhas; i++)
    {
        fprintf(arqcartelas, "\t|");
        for(j = 0; j < a_cartela->colunas; j++)
        {
            fprintf(arqcartelas, "%03d|", a_cartela->cartela[i][j]);
        }
        fprintf(arqcartelas, "\n");
    }
}






void MarcarPedraCartela(tCartela *a_cartela, int numSorteado)
{
    int i, j;
    for(i = 0; i<a_cartela->colunas; i++)
    {
        for(j = 0; j<a_cartela->linhas; j++)
        {
            if(a_cartela->cartela[j][i] == numSorteado)
            {
                a_cartela->cartela[j][i] = -1;
                a_cartela->qntPedrasMarcadas += 1;
                return;
            }
        }
        
    }
    
}

int ChecarSeCompleta(tCartela *a_cartela){
    int i, j, count = 0;
    int qntNumeros = a_cartela->linhas * a_cartela->colunas;
    for(i = 0; i<a_cartela->colunas; i++)
    {
        for(j = 0; j<a_cartela->linhas; j++)
        {
            if(a_cartela->cartela[j][i] == -1)
                count++;
        }
    }
    if(count == qntNumeros)
        return 1;
    return 0;
}

void ImprimirProgressoCartela(tCartela *a_cartela)
{
    int i, j;
    //fprintf(arqsaida, "Cartela ID:%d\n", a_cartela->id);
    printf("Cartela ID:%d\n", a_cartela->id);
    for(i = 0; i < a_cartela->linhas; i++)
    {
        //fprintf(arqsaida, "\t|");
        printf("\t|");
        for(j = 0; j < a_cartela->colunas; j++)
        {
            if(a_cartela->cartela[i][j] == -1)
            {
                //fprintf(arqsaida, "---|");
                printf("---|");
            }
            else
            {
                //fprintf(arqsaida, "%03d|", a_cartela->cartela[i][j]);
                printf("%03d|", a_cartela->cartela[i][j]);
            }
        }
        //fprintf(arqsaida, "\n");
        printf("\n");
    }
}



int ObterQuantMarcada(tCartela a_cartela); 
int EhQuantMarcada1MaiorQue2(tCartela a_cartela1, tCartela a_cartela2);

