#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tJogo.h"
#include "tGeradorAle.h"



void ExibirMensagemDeErro(char* mensagem){
    printf("%s\n", mensagem);
}

tJogo CriarJogo(tJogo a_jogo);
int GerarArquivoDeCartelas(tJogo a_jogo);
void RealizarJogo(tJogo);
tJogo ImprimirProgressoJogo(tJogo a_jogo);
void GerarEstatisticas(tJogo a_jogo);
tJogo OrdenarCartelasMarcadas(tJogo a_jogo);


