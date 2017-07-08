/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tArquivos.h
 * Author: mathe
 *
 * Created on 6 de Julho de 2017, 23:20
 */

#ifndef TARQUIVOS_H
#define TARQUIVOS_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct{
        char caminhoPadrao[1001];
        char jogo_config[1001];
        char cartelas_jogador[1001];
        char saida[1001];
        char estatisticas_jogo[1001];
    }tArquivos;

 void ParametroDeInicializacao(int a_argc, char** argv, tArquivos *a_arquivos);
 void CopiaCaminhoAbsoluto(char* caminhoAbsoluto, tArquivos *a_arquivos);
 void ConcatenaCaminhoVariavel(tArquivos *a_arquivos);

#ifdef __cplusplus
}
#endif

#endif /* TARQUIVOS_H */

