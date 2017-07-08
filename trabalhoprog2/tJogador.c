#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tJogador.h"
#include "tGeradorAle.h"
#include "tCartela.h"



 void InicializaNomeParam(FILE* config, tJogador *a_jogador, int a_id)
 {
     fscanf(config, " %[^\n]s", a_jogador[a_id]->nome);
 }

 void InicializaQuantCartelasParam(FILE* config, tJogador *a_jogador, int a_id)
 {
     fscanf(config, " %[^\n]s", a_jogador[a_id]->quantCartelas);
 }
 void InicializaCartelasDoJogador(tJogador *a_jogador, int a_quantCartelas, int a_id, int a_linhas, int a_colunas){
     int i;
     for(i = 0; i < a_quantCartelas; i++)
     {
         CriarCartela(&(a_jogador->cartelas[i]), a_id, i, a_linhas, a_colunas);
     }
 }
 
 void ImprimeCartelasJogador(tJogador *a_jogador, FILE* arqcartelas)
 {
     fprintf(arqcartelas, "Jogador:%s\n", a_jogador->nome);
     for(i = 0; i < a_jogador->quantCartelas; i++)
     {
         ImprimirCartelaArquivo(*(a_jogador->cartelas[i]), arqcartelas);
     }
 }
 
    int ChecarSeVenceu(tJogador a_jogador);


