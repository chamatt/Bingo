#include <stdio.h>
#include <stdlib.h>
#include "tJogo.h"
#include "tJogador.h"
#include "tCartela.h"
#include "tArquivos.h"
int main(int argc, char** argv) {
    tJogo jogo;
    tArquivos arquivos;
    ParametroDeInicializacao(argc, argv, &arquivos);
    CriarJogo(&jogo, &arquivos);
    RealizarJogo(&jogo, &arquivos);
    GerarEstatisticasJogo(&jogo, &arquivos);
    GerarBonus(&jogo, &arquivos);
    return (EXIT_SUCCESS);
}

