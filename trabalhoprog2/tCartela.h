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
    }tCartela;
    
    tCartela CriarCartela(tCartela a_cartela, int linhas, int colunas);
    int ObterID(tCartela a_cartela);
    tCartela OrdenarCartela(tCartela a_cartela);
    int ChecarSeCompleta(tCartela a_cartela);
    int ObterQuantMarcada(tCartela a_cartela); 
    int EhQuantMarcada1MaiorQue2(tCartela a_cartela1, tCartela a_cartela2);
    
    
    
    



#ifdef __cplusplus
}
#endif

#endif /* TCARTELAS_H */

