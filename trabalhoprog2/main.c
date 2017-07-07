#include <stdio.h>
#include <stdlib.h>
#include "tJogo.h"
#include "tJogador.h"
#include "tCartela.h"
int main(int argc, char** argv) {
    tJogo jogo;
    tArquivos arquivos;
    arquivos = ParametroDeInicializacao(argc, argv);
    printf("%s", arquivos.estatisticas_jogo);
    
    return (EXIT_SUCCESS);
}

