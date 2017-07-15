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
    
    /* Realiza a leitura de uma string no arquivo recebido como parâmetro,
     * parando ao encontrar o caractere ';' e armazena essa string na variável
     * correspondente ao nome do jogador, dentro do tipo tJogador. */
    void InicializaNomeParam(FILE* config, tJogador *a_jogador);
    
    /* Realiza a leitura de um inteiro no arquivo recebido como parâmetro,
     * este na variável correspondente a quantidade de cartelas do jogador,
     * dentro do tipo tJogador. */
    void InicializaQuantCartelasParam(FILE* config, tJogador *a_jogador);
    
    /* Armazena o ID do jogador numa váriavel do tJogador e cria um loop que
     * que chama uma função auxiliar para inicializar cada cartela do jogador. */
    void InicializaCartelasDoJogador(tJogador *a_jogador, int* a_id, int jogadorID, int a_linhas, int a_colunas, int pedras);
    
    /* Estabelece um loop que percorre cada cartela do jogador e chama uma função 
     * auxiliar para inicializar uma variável do tCartela, que será 
     * utilizada para armazenar a quantidade de pedras marcadas de cada cartela
     * do jogador.  */
    void InicializaContadorDePedrasMarcadasJogador(tJogador *a_jogador);
    
    /* Percorre todas as cartelas de um determinado jogador e adiciona essas
     * linearmente (seguindo o indice do contador recebido como parâmetro)
     * a um vetor que irá armazenar todas as cartelas do jogo. */
    void CopiaTodasCartelasParaUmVetorAUX(tJogador *a_jogador, tCartela *todasCartelas, int* count);
    
    /* Modifica o parâmetro "nome" recebido mudando seu valor para uma string 
     * que representa o nome do jogador (indicado pela ID do mesmo) */
    void ObterNome(char* nome, tJogador a_jogador[], int jogadorID);
    
    /* Imprime o nome do jogador e chama uma função auxiliar papra imprimir
     * cada uma de suas cartelas em um arquivo. */
    void ImprimeCartelasJogador(tJogador *a_jogador, FILE* arqcartelas);
    
    /* Percorres cada cartela do jogador e utiliza uma função auxiliar para 
     * marcar os elementos de cada uma delas caso possuam o numero sorteado. */
    void MarcarPedraJogador(tJogador *a_jogador, int numSorteado);
    
    /* Imprime o nome do jogador e chama uma função auxiliar para imprimir
     * o estado de cada uma de suas cartelas no momento da chamada da função, 
     * com seus elemente marcados propriamente representados por "---"
     * em um arquivo. */
    void ImprimeProgressoJogador(tJogador *a_jogador);
    
    /* Percorre todas as cartelas do jogador e checa se estão
     * completas, caso alguma esteja, retorna verdadeiro (1), representando que
     * venceu o jogo, ou falso (0). */
    int ChecarSeVenceu(tJogador *a_jogador);
    
    /* Retorna a quantidade de cartelas que o jogador possui.*/
    int ObterQuantCartelasJogador(tJogador *a_jogador);
    
    
    /* Percorre as cartelas do jogador e retorna a menor quantidade de cartela 
     * marcada que o jogador possuir. */
    int ObterMenosMarcadaJogador(tJogador *a_jogador);
    
    /* Imprime o nome do jogador e sua menor quantidade de cartela marcada. */
    void ImprimirMenosMarcada(FILE* arq, char* nome, int menosMarcada);
    
    
    
    



#ifdef __cplusplus
}
#endif

#endif /* TJOGADOR_H */

