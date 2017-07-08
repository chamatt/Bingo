#include <stdio.h>
#include <stdlib.h>
#include "tJogo.h"
#include "tJogador.h"
#include "tCartela.h"
int main(int argc, char** argv) {
    tJogo jogo;
    tArquivos arquivos;
    ParametroDeInicializacao(argc, argv, &arquivos);
    CriarJogo(&jogo, &arquivos);
    return (EXIT_SUCCESS);
}

