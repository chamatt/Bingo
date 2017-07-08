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
        int linhas;
        int colunas;
        int pedrasMarcadas[900];
        tJogador jogador[20];
    }tJogo;
    
    void ExibirMensagemDeErro(char* mensagem);
    void CriarJogo(tJogo *a_jogo, tArquivos *a_arquivos);
    void LeConfiguracoes(tJogo *a_jogo, tArquivos *a_arquivos, FILE* config);
    int GerarArquivoDeCartelas(tJogo *a_jogo, tArquivos *a_arquivos);
    void RealizarJogo(tJogo);
    tJogo ImprimirProgressoJogo(tJogo a_jogo);
    void GerarEstatisticas(tJogo a_jogo);
    tJogo OrdenarCartelasMarcadas(tJogo a_jogo);
    
    
    
    

    
    
    
    
    


#ifdef __cplusplus
}
#endif

#endif /* TJOGO_H */

