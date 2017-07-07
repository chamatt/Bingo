#include "tCartela.h"
#include "tJogador.h"
#include "tArquivos.h"

#ifndef TJOGO_H
#define TJOGO_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct{
        int seed;
        int pedras;
        int quantJogadores;
        tArquivos arquivos;
        tJogador jogador[20];
    }tJogo;
    
    void ExibirMensagemDeErro(char* mensagem);
    tJogo CriarJogo(tJogo a_jogo);
    int GerarArquivoDeCartelas(tJogo a_jogo);
    void RealizarJogo(tJogo);
    tJogo ImprimirProgressoJogo(tJogo a_jogo);
    void GerarEstatisticas(tJogo a_jogo);
    tJogo OrdenarCartelasMarcadas(tJogo a_jogo);
    
    
    
    

    
    
    
    
    


#ifdef __cplusplus
}
#endif

#endif /* TJOGO_H */

