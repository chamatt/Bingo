#ifndef TGERADORALE_H
#define	TGERADORALE_H

/* Funcao que inicia o gerador aleatorio. Ela recebe uma 
 * semente que indica a aleatoriedade do problema, ou seja,
 * uma chamadas da funcao GeraProxNumero com uma mesma semente
 * irao gerar uma mesma sequencia de numeros. Ela recebe 
 * tambem uma quantidade de numeros a serem sorteados, ou seja,
 * a quantidade maxima de vezes que a funcao GeraProxNumero
 * pode ser chamada sem ter que reiniciar o gerador.  
 * chamada uma vez antes. 
 */
void ReiniciaGerador(unsigned int semente, int qtdNumeros);

/* Funcao que sorteia um numero aleatorio de uma lista
 * com a quantidade de numeros definida com a funcao
 * ReiniciaGerador. 
 * Exemplo: se ReiniciaGerador for chamada com qtdNumeros=5,
 * o sorteio considerara uma lista com os numeros 
 * 1, 2, 3, 4, 5. Cada chamada de GeraProxNumero retirara um
 * numero aleatoriamente da lista e esse nao sera mais sorteado,
 * a nao ser que o gerador seja reiniciado.  */
int GeraProxNumero(void);

#endif	/* TJOGO_H */

