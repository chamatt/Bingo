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
    }tCartela;
    
    void CriarCartela(tCartela *a_cartela, int *id, int linhas, int colunas, int pedras);
    int ObterID(tCartela a_cartela);
    void OrdenaVetor(int vet[], int qntNumeros);
    int OrdemCrescente (int vetor[], int qntNumeros);
    int OrdemDecrescente (int vetor[], int qntNumeros);
    void ImprimirCartelaArquivo(tCartela *a_cartela, FILE* arqcartelas);
    void MarcarPedraCartela(tCartela *a_cartela, int numSorteado);
    int ChecarSeCompleta(tCartela *a_cartela);
    void ImprimirProgressoCartela(tCartela *a_cartela, FILE* arqsaida);
    int ObterQuantMarcada(tCartela a_cartela); 
    int EhQuantMarcada1MaiorQue2(tCartela a_cartela1, tCartela a_cartela2);
    
    
    
    



#ifdef __cplusplus
}
#endif

#endif /* TCARTELAS_H */

