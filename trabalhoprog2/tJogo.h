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
        char vencedores[20][1001];
        tCartela todasCartelas[200];
    }tJogo;
    
    /* Imprime uma mensagem qualquer recebida como parâmetro */ 
    void ExibirMensagemDeErro(char* mensagem);
    
    /* Chama uma função para realizar a leitura dos parâmetros necessários 
     * do arquivo de configurações.
     * Também percorre os jogadores e chama funções auxiliares para inicializar
     * suas variáveis.
     * Por fim, chama uma funçao para inicializar a geração das cartelas dos 
     * jogadores e chama uma função para imprimir-las em arquivo. */
    void CriarJogo(tJogo *a_jogo, tArquivos *a_arquivos);
    
    /* Le os parâmetros necessários para o jogo de dentro do arquivo e armazena
     * em variáveis correspondentes na estrutura de tipo tJogo.
     * Caso não consiga ler*/
    void LeConfiguracoes(tJogo *a_jogo, tArquivos *a_arquivos, FILE* config);
    
    /* Gera um arquivo que armazena o estado inicial das cartelas do jogo 
     * com todas as cartelas de cada um dos jogadores representadas. */
    void GerarArquivoDeCartelas(tJogo *a_jogo, tArquivos *a_arquivos);
    
    /* Sorteia pedras, marca esses sorteio em todas as cartelas que possuam
     * o número sorteado, sempre chechando se alguma delas está totalmente 
     * completa e imprime o estado de todas as cartelas do jogo na saída padrão
     * após cada sorteio. Caso alguma(s) cartelas sejam  completadas, pára o 
     * sorteio e imprime a(s) vencedora{s) na saída padrão. */
    void RealizarJogo(tJogo *a_jogo, tArquivos *a_arquivos);
    
    /* Percorre todas os jogadores e suas cartelas e adiciona essas
     * linearmente (seguindo o indice de um contador) a um vetor do tipo tCartela
     * que irá armazenar todas as cartelas do jogo. */
    void InicializaContadorDePedrasMarcadasJogo(tJogo *a_jogo);
    
    /* Percorre todas as cartelas, e se elas possuirem a pedra sorteada,
     * seu elemento correspondente na cartela tem seu valor marcado e a contagem
     * de elementos marcados da cartela respectiva é aumentado em 1. */
    void MarcarPedra(tJogo *a_jogo, int numSorteado);
    
    /* Percorre todos os jogadores e chama uma função que checa se algum deles 
     * venceu, e de acordo com o retorno dessa função auxiliar, retorna a
     * quantidade de jogadores que completaram alguma cartela naquela rodada. */
    int ChecarSeJogadoresVenceram(tJogo *a_jogo);
    
    /* Checa a quantidade de jogadores que completaram a cartela, se for um só
     * imprime somente este como vencedor, se for mais, imprime os jogadores
     * empatados, na saída padrão. */
    void ImprimirVencedores(tJogo *a_jogo, int qntVenceu);
    
    /* Percorre os jogadores e imprime seus nomes e suas respectivas cartelas, 
     * com todos seus elementos no formato de uma matriz, com o número apropriado
     * de linhas e colunas, de acordo com as configurações da cartela, e com
     * elementos já sorteados e marcados indicados com "---". */
    void ImprimirProgressoJogo(tJogo *a_jogo);
    
    /* Coloca todas as cartelas do jogo em um vetor do tipo tCartelas, 
     * as ordena por meio de uma função auxiliar, e imprime-as em ordem. */
    void GerarEstatisticasJogo(tJogo *a_jogo, tArquivos *a_arquivos);
    
    /* Percorre as cartelas de cada jogador e suas cartelas e coloca em um vetor 
     de tCartelas organizado por meio do ID de cada cartela. */
    void CopiaTodasCartelasParaUmVetor(tJogo *a_jogo);
    
    /* Percorre todas as cartelas e conta a quantidade de cartela total por meio
     * de um contador*/
    int ObterQuantCartelasTotais(tJogo *a_jogo);
    
    /* Ordenada a lista de cartelas do jogo de forma decrescente pela quantidade
     * de pedras marcadas na cartela e tendo como primeiro critério de desempate
     *  o nome do jogador dono da cartela (crescentemente) e como segundo 
     * critério, a ID da cartela. Tudo isso é feito por meio de uma implementação
     * do método de ornação Bubble Sort.*/
    int OrdenaCartelasEstatisticas(tJogo *a_jogo, tCartela *todasCartelas, int qntCartelas);
    
    /* Por meio de funções auxiliarem obtem as cartelas menos marcadas e o nome
     * de seus donos e imprime em um arquivo essas informaçoes organizadas em
     * ordem alfabética dos nomes dos donos das cartelas. */
    void GerarBonus(tJogo *a_jogo, tArquivos *a_arquivos);
    
    /* Organiza as menores quantidade de elementos marcados e organiza em 
     * conjunto com o nome do dono pela ordem alfabética */
    void OrganizarBonus(char nome[][1001],int* menosMarcada, int qntNumeros);
    
    
    
    
    

    
    
    
    
    


#ifdef __cplusplus
}
#endif

#endif /* TJOGO_H */

