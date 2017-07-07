#include "tCartela.h"

#ifndef TJOGADOR_H
#define TJOGADOR_H

#ifdef __cplusplus
extern "C" {
#endif

    
    typedef struct{
        char nome[201];
        int quantCartelas;
        tCartela cartelas[200];
    }tJogador;
    
    tJogador InicializaNomeParam(tJogador a_jogador);
    tJogador InicializarQuantCartelasParam(tJogador a_jogador);
    tJogador InicializaCartelasDoJogador(tJogador a_jogador, int a_quantCartelas);
    int ChecarSeVenceu(tJogador a_jogador);
    char* ObterNome(tJogador a_jogador);
    
    
    
    



#ifdef __cplusplus
}
#endif

#endif /* TJOGADOR_H */

