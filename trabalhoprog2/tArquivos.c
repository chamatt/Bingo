#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tArquivos.h"
#include "tJogo.h"

void ExibirMensagemDeErro(char* mensagem){
    printf("%s\n", mensagem);
}
void ExibirErroNaLeituraConfig(tArquivos *a_arquivos)
{
    char mensagem[1001] = "ERRO: Nao foi possível ler o arquivo <jogo_config.txt> localizado em:\n";
    strcat(mensagem, a_arquivos->caminhoPadrao);
    strcat(mensagem, "/input");
    ExibirMensagemDeErro(mensagem);
    exit(0);
}

void ExibirErroAoGerarCartelas()
{
    printf("ERRO: Nao foi possível salvar arquivo com as cartelas dos jogadores.");
}


 void ParametroDeInicializacao(int a_argc, char** argv, tArquivos *a_arquivos)
 {       
     /* Checa se foi passado o argumento referente a localização dos arquivos, 
      * caso contrário, sai do programa */
     if(a_argc < 2)
     {
         ExibirMensagemDeErro("ERRO: O diretorio de arquivos de configuração nao foi informado!");
         exit(0);
     }
     else{
         char caminhoAbsoluto[1001];
         strcpy(caminhoAbsoluto, argv[1]);
         CopiaCaminhoAbsoluto(caminhoAbsoluto, a_arquivos);
         ConcatenaCaminhoVariavel(a_arquivos);
     } 
 }

 
 /* Copia o Caminho absoluto até a pasta onde estão os arquivos de teste  */
void CopiaCaminhoAbsoluto(char* caminhoAbsoluto, tArquivos *a_arquivos)
{
    strcpy(a_arquivos->caminhoPadrao, caminhoAbsoluto);
    strcpy(a_arquivos->cartelas_jogador, caminhoAbsoluto);
    strcpy(a_arquivos->estatisticas_jogo, caminhoAbsoluto);
    strcpy(a_arquivos->jogo_config, caminhoAbsoluto);
    strcpy(a_arquivos->saida, caminhoAbsoluto);
}

/* Concatena o caminho específico de cada arquivo ao final do caminho absoluto */
void ConcatenaCaminhoVariavel(tArquivos *a_arquivos)
{
     char* jogo_config = "/input/jogo_config.txt";
     char* cartelas_jogador = "/output/cartelas_jogador.txt";
     char* saida = "/output/saida.txt";
     char* estatisticas_jogo = "/output/estatisticas_jogo.txt";
     strcat(a_arquivos->jogo_config, jogo_config);
     strcat(a_arquivos->cartelas_jogador, cartelas_jogador);
     strcat(a_arquivos->saida, saida);
     strcat(a_arquivos->estatisticas_jogo, estatisticas_jogo);
}

FILE* AbreLeArquivo(FILE* arq, char* caminho)
{
    arq = fopen(caminho, "r");
}

FILE* CriaAbreArquivo(FILE* arq, char* caminho)
{
    tArquivos arquivos;
    //arq = fopen(caminho, "w+");
    fclose(arq);
    arq = fopen(caminho, "a+");
    return arq;
}

 void ImprimirNoArquivoETela(FILE* arq, char* string)
 {
     fprintf(arq, "%s", string);
     
 }