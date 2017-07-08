#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tJogador.h"
#include "tGeradorAle.h"
#include "tCartela.h"



 void InicializaNomeParam(FILE* config, tJogador *a_jogador)
 {
     fscanf(config, " %[^\n^;]s", a_jogador->nome);
 }

 void InicializaQuantCartelasParam(FILE* config, tJogador *a_jogador)
 {
     fscanf(config, ";%d", &(a_jogador->quantCartelas));
 }
 void InicializaCartelasDoJogador(tJogador *a_jogador, int* a_id, int a_linhas, int a_colunas, int pedras){
     int i;
     for(i = 0; i < a_jogador->quantCartelas; i++)
     {
         CriarCartela(&(a_jogador->cartelas[i]), a_id, a_linhas, a_colunas, pedras);
         (*a_id)++;
     }
 }
 
 void ImprimeCartelasJogador(tJogador *a_jogador, FILE* arqcartelas)
 {
     int i;
     fprintf(arqcartelas, "Jogador:%s\n", a_jogador->nome);
     for(i = 0; i < a_jogador->quantCartelas; i++)
     {
         ImprimirCartelaArquivo(&(a_jogador->cartelas[i]), arqcartelas);
         fprintf(arqcartelas, "\n");
     }
 }
 
    int ChecarSeVenceu(tJogador a_jogador);


