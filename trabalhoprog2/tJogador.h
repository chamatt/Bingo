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
    
    void InicializaNomeParam(FILE* config, tJogador *a_jogador, int a_id);
    void InicializaQuantCartelasParam(FILE* config, tJogador *a_jogador, int a_id);
    void InicializaCartelasDoJogador(tJogador *a_jogador, int a_quantCartelas, int a_id, int linhas, int colunas);
    void ImprimeCartelasJogador(tJogador *a_jogador, FILE* arqcartelas);
    int ChecarSeVenceu(tJogador a_jogador);
    char* ObterNome(tJogador a_jogador);
    
    
    
    



#ifdef __cplusplus
}
#endif

#endif /* TJOGADOR_H */

