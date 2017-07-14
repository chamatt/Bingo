#include "tCartela.h"

#ifndef TJOGADOR_H
#define TJOGADOR_H

#ifdef __cplusplus
extern "C" {
#endif

    
    typedef struct{
        char nome[201];
        int jogadorID;
        int quantCartelas;
        tCartela cartelas[200];
    }tJogador;
    
    void InicializaNomeParam(FILE* config, tJogador *a_jogador);
    void InicializaQuantCartelasParam(FILE* config, tJogador *a_jogador);
    void InicializaCartelasDoJogador(tJogador *a_jogador, tCartela *todasCartelas, int* a_id, int jogadorID, int a_linhas, int a_colunas, int pedras);
    void ObterNome(char* nome, tJogador a_jogador);
    void ImprimeCartelasJogador(tJogador *a_jogador, FILE* arqcartelas);
    void MarcarPedraJogador(tJogador *a_jogador, int numSorteado);
    void ImprimeProgressoJogador(tJogador *a_jogador);
    int ChecarSeVenceu(tJogador *a_jogador);
    int ObterQuantCartelasJogador(tJogador *a_jogador);
    
    
    
    



#ifdef __cplusplus
}
#endif

#endif /* TJOGADOR_H */

