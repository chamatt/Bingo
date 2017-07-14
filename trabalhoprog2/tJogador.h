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
    
    void InicializaNomeParam(FILE* config, tJogador *a_jogador);
    void InicializaQuantCartelasParam(FILE* config, tJogador *a_jogador);
    void InicializaCartelasDoJogador(tJogador *a_jogador, int* a_id,  int linhas, int colunas, int pedras);
    void ObterNome(char* nome, tJogador a_jogador);
    void ImprimeCartelasJogador(tJogador *a_jogador, FILE* arqcartelas);
    void MarcarPedraJogador(tJogador *a_jogador, int numSorteado);
    void ImprimeProgressoJogador(tJogador *a_jogador);
    int ChecarSeVenceu(tJogador *a_jogador);
    
    
    
    



#ifdef __cplusplus
}
#endif

#endif /* TJOGADOR_H */

