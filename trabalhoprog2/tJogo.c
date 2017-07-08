#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tJogo.h"
#include "tGeradorAle.h"
#include "tArquivos.h"
#include "tJogador"
#define NULL 0

void ExibirMensagemDeErro(char* mensagem){
    printf("%s\n", mensagem);
}

tJogo CriarJogo(tJogo *a_jogo, tArquivos *a_arquivos)
{
    FILE* config;
    int i;
    config = fopen(a_arquivos.jogo_config, "r");
    LeConfiguracoes(a_jogo, a_arquivos, config);
    for(i = 0; i<a_jogo->quantJogadores; i++)
    {
        InicializaNomeParam(config, &(a_jogo->jogador), i);
        InicializaQuantCartelasParam(config, &(a_jogo->jogador), i);
        InicializaCartelasDoJogador(&(a_jogo->jogador), a_jogo->jogador->quantCartelas, i, a_jogo->linhas, a_jogo->colunas);

    }
    fclose(config);
    
}
void LeConfiguracoes(tJogo *a_jogo, tArquivos *a_arquivos, FILE* config)
{
    int i;
    if(!config)
    {
        char mensagem[1001] = "ERRO: Nao foi possível ler o arquivo <jogo_config.txt> localizado em:\n";
        strcat(mensagem, a_arquivos->caminhoPadrao);
        strcat(mensagem, "/input");
        ExibirMensagemDeErro(mensagem);
        exit();
    }
    else{
        fscanf(config, "%d;%d;%d;%d;%d", a_jogo->seed, a_jogo->pedras, 
                a_jogo->linhas, a_jogo->colunas, a_jogo->quantJogadores);
    }
}

int GerarArquivoDeCartelas(tJogo *a_jogo, tArquivos *a_arquivos)
{
    FILE* arqcartelas;
    int i;
    arqcartelas = fopen(a_arquivos->cartelas_jogador, "w+");
    fclose(arqcartelas);
    arqcartelas = fopen(a_arquivos->cartelas_jogador, "a+");
    for(i = 0; i < a_jogo->quantJogadores; i++)
    {
        ImprimeCartelasJogador(&(a_jogo->jogador[i]), arqcartelas);
    }
    
}
void RealizarJogo(tJogo);
tJogo ImprimirProgressoJogo(tJogo a_jogo);
void GerarEstatisticas(tJogo a_jogo);
tJogo OrdenarCartelasMarcadas(tJogo a_jogo);


