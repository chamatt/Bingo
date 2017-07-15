#ifndef TCARTELAS_H
#define TCARTELAS_H

#ifdef __cplusplus
extern "C" {
#endif


    typedef struct{
        int linhas;
        int colunas;
        int id;
        int cartela[20][20];
        int qntPedrasMarcadas;
        int jogadorDono;
    }tCartela;
    
    /* Pega os parâmetros recebidos na chamada da função e os associa as 
     * váriaveis correspondentes dentro do tipo tCartela.
     * Também utiliza uma função de geração aleatória de numeros para gerar
     * todos os números necessários para preencher um cartela, e coloca esses
     * números em um vetor, que será ordenado para estão passar o conteúdo deste
     * vetor para a matriz que representa a cartela. */
    void CriarCartela(tCartela *a_cartela, int *id, int jogadorID, int linhas, int colunas, int pedras);
    
    /* Retorna um inteiro correspondente a ID de uma cartela */
    int ObterID(tCartela a_cartela);
    
    /* Recebe um vetor e o ordena de acordo com a função que está sendo chamada
     * dentro dele, no caso, na ordem crescente. */
    void OrdenaVetor(int vet[], int qntNumeros);
    
    /* Ordena um vetor recebido na ordem crescente por meio da ordenação
     * Bubble Sort */
    void OrdemCrescente (int vetor[], int qntNumeros);
    
    /* Imprime informações referentes a cartela (ID e os elementos da cartela)
     * no arquivo recebido como parâmetro.  */
    void ImprimirCartelaArquivo(tCartela *a_cartela, FILE* arqcartelas);
    
    /* Inicializa todos os valores da variável qntPedrasMarcadas presente no tipo 
     * tCartela com o valor 0, para ser usada posteriormente como um contador.
     * de pedras marcadas. */
    void InicializaContadorDePedrasMarcadasCartela(tCartela *a_cartela);
    
    /* Percorre a matriz da cartela e checa de o numero sorteado, recebido como
     * parâmetro, é igual a algum elemento da matriz. Se for, este elemente é
     * alterado para o valor -1, de forma a marcá-lo e é adicionado 1 a quantidade
     * de pedras marcadas da cartela específica. */
    void MarcarPedraCartela(tCartela *a_cartela, int numSorteado);
    
    /* Percorre a matriz da cartela para checar se todos elementos da mesma estão
     * marcados com -1, estando portanto completa. Retorna verdadeiro (1) se estiver
     * completa. */
    int ChecarSeCompleta(tCartela *a_cartela);
    
    /* Imprime informações referentes a cartela (ID e os elementos da cartela)
     * no momento da chamada da função em um arquivo, com os elementos que estão marcados 
     * representados por "---" e os que não estão, pelos seus respectivos números. */
    void ImprimirProgressoCartela(tCartela *a_cartela);
    
    /* Retorna a quantidade de elementos marcados em na cartela. */
    int ObterQuantMarcada(tCartela a_cartela);
    
    /* Compara de a quantidade de elementos marcados em uma cartela é menor
     * que de outra, retornando verdadeiro(1) caso seja, falso(0) caso contrário. */
    int EhQuantMarcada1MenorQue2(int qntMarcada1, int qntMarcada2);
    
    
    
    



#ifdef __cplusplus
}
#endif

#endif /* TCARTELAS_H */

