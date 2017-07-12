#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tJogo.h"
#include "tGeradorAle.h"
#include "tArquivos.h"
#include "tJogador.h"


void CriarJogo(tJogo *a_jogo, tArquivos *a_arquivos)
{
    
    FILE* config;
    int i, idinit = 0;
    int* id = &idinit;
    AbreLeArquivo(config, a_arquivos->jogo_config);
    //config = fopen(a_arquivos->jogo_config, "r");
    LeConfiguracoes(a_jogo, a_arquivos, config);
    for(i = 0; i<a_jogo->quantJogadores; i++)
    {
        InicializaNomeParam(config, &(a_jogo->jogador[i]));
        InicializaQuantCartelasParam(config, &(a_jogo->jogador[i]));
        InicializaCartelasDoJogador(&(a_jogo->jogador[i]), id, a_jogo->linhas, a_jogo->colunas, a_jogo->pedras);

    }
    GerarArquivoDeCartelas(a_jogo, a_arquivos);
    fclose(config);
    
}
void LeConfiguracoes(tJogo *a_jogo, tArquivos *a_arquivos, FILE* config)
{
    int i;
    if(!config)
    {
        ExibirErroNaLeituraConfig(a_arquivos);
    }
    else{
        fscanf(config, "%d;%d;%d;%d;%d", &(a_jogo->seed), &(a_jogo->pedras), 
                &(a_jogo->linhas), &(a_jogo->colunas), &(a_jogo->quantJogadores));
    }
}

int GerarArquivoDeCartelas(tJogo *a_jogo, tArquivos *a_arquivos)
{
    FILE* arqcartelas;
    int i;
    CriaAbreArquivo(arqcartelas, a_arquivos->cartelas_jogador);
    if(!arqcartelas)
    {
        ExibirErroAoGerarCartelas();
        exit(0);
    }
    /*
     * arqcartelas = fopen(a_arquivos->cartelas_jogador, "w+");
    fclose(arqcartelas);
    arqcartelas = fopen(a_arquivos->cartelas_jogador, "a+");
     * */
    for(i = 0; i < a_jogo->quantJogadores; i++)
    {
        ImprimeCartelasJogador(&(a_jogo->jogador[i]), arqcartelas);
        fprintf(arqcartelas, "\n");
    }
    
}




void RealizarJogo(tJogo *a_jogo, tArquivos *a_arquivos)
{
    int numSorteado, qntVenceu, i;
    FILE* arqsaida;
    //arqsaida = CriaAbreArquivo(arqsaida, a_arquivos->saida);
    /* Cria o arquivo se não existir, apaga conteúdo se existir 
     * arqsaida = fopen(a_arquivos->saida, "w+");
    fclose(arqsaida);
    arqsaida = fopen(a_arquivos->saida, "a+");
     */
    ReiniciaGerador(a_jogo->seed, a_jogo->pedras);
    InicializaContadorDePedras(a_jogo);
    for(i = 0; i < a_jogo->pedras; i++)
    {
        numSorteado = GeraProxNumero();
        fprintf(arqsaida, "Pedra:%d\n", numSorteado);
        printf("Pedra:%d\n", numSorteado);
        ImprimirProgressoJogo(a_jogo, arqsaida);
        MarcarPedra(a_jogo, numSorteado);
        qntVenceu = ChecarSeJogadoresVenceram(a_jogo);
        if(qntVenceu> 0) break;
    }
    ImprimirProgressoJogo(a_jogo, arqsaida);
    ImprimirVencedores(arqsaida, a_jogo, qntVenceu);
}
void MarcarPedra(tJogo *a_jogo, int numSorteado)
{
    int i;
    for(i = 0; i < a_jogo->quantJogadores; i++)
    {
        MarcarPedraJogador(&(a_jogo->jogador[i]), numSorteado);
    }
    
}

int ChecarSeJogadoresVenceram(tJogo *a_jogo)
{
    int i, venceu, qntVenceu = 0;
    char nome[1001];
    for(i = 0; i < a_jogo->quantJogadores; i++)
    {
        venceu = ChecarSeVenceu(&(a_jogo->jogador[i]));
        if(venceu)
        {
            ObterNome(nome, a_jogo->jogador[i]);
            strcpy(a_jogo->vencedores[qntVenceu], nome);
            qntVenceu++;
        }
       
    }
    return qntVenceu;
}


void ImprimirVencedores(FILE* arq, tJogo *a_jogo, int qntVenceu)
{
    int i;
    if(qntVenceu==1)
    {
        /*
        printf("Jogador Venceu!\n");
        fprintf(arq, "Jogador Venceu!\n");
         */
        ImprimirNoArquivoETela(arq, "Jogador Venceu!\n");
    }
    else
    {
        /*
        printf("Jogadores Empataram!\n");
        fprintf(arq, "Jogadorem Empataram!\n"); 
         */
        ImprimirNoArquivoETela(arq, "Jogadorem Empataram!\n");
    }
        
    for(i = 0; i < qntVenceu; i++)
    {
        /*
        printf("%s\n", a_jogo->vencedores[i]);
        fprintf(arq ,"%s\n", a_jogo->vencedores[i]); 
         */
        ImprimirNoArquivoETela(arq, a_jogo->vencedores[i]); 
        ImprimirNoArquivoETela(arq, "\n"); 
    }
}

void InicializaContadorDePedras(tJogo *a_jogo)
{
    int i, j;
    for(i = 0; i < a_jogo->quantJogadores; i++)
    {
        for(j = 0; j < a_jogo->jogador->quantCartelas; j++)
        {
            a_jogo->jogador->cartelas->qntPedrasMarcadas = 0;
        }
    }
}

void ImprimirProgressoJogo(tJogo *a_jogo, FILE* arqsaida)
{
    int i;
    for(i = 0; i < a_jogo->quantJogadores; i++)
    {
        ImprimeProgressoJogador(&(a_jogo->jogador[i]), arqsaida);
        printf("\n");
        //fprintf(arqsaida, "\n");
    }
}


void GerarEstatisticas(tJogo a_jogo);
tJogo OrdenarCartelasMarcadas(tJogo a_jogo);


