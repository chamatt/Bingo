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
        char bonus[1001];
        char estatisticas_jogo[1001];
    }tArquivos;

 /* Checa se foi passado o argumento referente a localização dos arquivos,
  * Se sim, inicializa as variáveis do tipo tArquivos por meio do argumento passado. 
  * caso contrário, sai do programa. */
 void ParametroDeInicializacao(int a_argc, char** argv, tArquivos *a_arquivos);
 
 /* Exibe uma mensagem de erro para informar o usuário que a leitura do arquivo de 
  * configurações foi mal-sucedida, informa o caminho do arquivo. */
 void ExibirErroNaLeituraConfig(tArquivos *a_arquivos);
 
 void ExibirErroAoGerarCartelas();
 
 void ExibirErroAoGerarEstatisticas();
 
 /* Copia o caminho do diretório mestre (onde todos os outros arquivos ficarão)
  * para dentro de todas as variáveis do tipo char* pertencentes ao tArquivos */
 void CopiaCaminhoAbsoluto(char* caminhoAbsoluto, tArquivos *a_arquivos);
 
 /* Adiciona ao final do caminho, a localização específica de cada arquivo
  * dentro do diretório mestre. */
 void ConcatenaCaminhoVariavel(tArquivos *a_arquivos);
 
 /* Abre o arquivo em modo de leitura */
 FILE* AbreLeArquivo(FILE* arq, char* caminho);
 
 /* Cria o arquivo (ou apaga seu conteúdo caso já exista) e abre o arquivo em 
  * seguida em um modo de escrita que não sobrescreve o conteúdo.
  * Essa função também compara o caminho do arquivo que recebeu com os caminhos
  * armazenados no tipo tArquivo, de forma a exibir chamar uma função que exiba
  * um erro de leitura correspondente ao arquivo em questão. */
 FILE* CriaAbreArquivo(FILE* arq, char* caminho, tArquivos *a_arquivos);

#ifdef __cplusplus
}
#endif

#endif /* TARQUIVOS_H */

