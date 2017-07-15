#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tJogo.h"
#include "tGeradorAle.h"
#include "tArquivos.h"
#include "tJogador.h"

void ExibirMensagemDeErro(char* mensagem){
    printf("%s\n", mensagem);
}

void CriarJogo(tJogo *a_jogo, tArquivos *a_arquivos)
{
    FILE* config;
    int i, idinit = 0;
    int* id = &idinit;
    //config = AbreLeArquivo(config, a_arquivos->jogo_config);
    config = fopen(a_arquivos->jogo_config, "r");
    LeConfiguracoes(a_jogo, a_arquivos, config);
    for(i = 0; i<a_jogo->quantJogadores; i++)
    {
        InicializaNomeParam(config, &(a_jogo->jogador[i]));
        InicializaQuantCartelasParam(config, &(a_jogo->jogador[i]));
        InicializaCartelasDoJogador(&(a_jogo->jogador[i]), id, i, a_jogo->linhas, a_jogo->colunas, a_jogo->pedras);
    }
    GerarArquivoDeCartelas(a_jogo, a_arquivos);
    fclose(config);
    
}
void LeConfiguracoes(tJogo *a_jogo, tArquivos *a_arquivos, FILE* config)
{
    int i;
    if(!config)
    {
        ExibirErroNaLeituraConfig(a_arquivos);
    }
    else{
        fscanf(config, "%d;%d;%d;%d;%d", &(a_jogo->seed), &(a_jogo->pedras), 
                &(a_jogo->linhas), &(a_jogo->colunas), &(a_jogo->quantJogadores));
    }
}

void GerarArquivoDeCartelas(tJogo *a_jogo, tArquivos *a_arquivos)
{
    FILE* arqcartelas;
    int i;
    arqcartelas = CriaAbreArquivo(arqcartelas, a_arquivos->cartelas_jogador, a_arquivos);
    for(i = 0; i < a_jogo->quantJogadores; i++)
    {
        ImprimeCartelasJogador(&(a_jogo->jogador[i]), arqcartelas);
        fprintf(arqcartelas, "\n");
    }
    fclose(arqcartelas); 
}




void RealizarJogo(tJogo *a_jogo, tArquivos *a_arquivos)
{
    int numSorteado, qntVenceu, i;
    ReiniciaGerador(a_jogo->seed, a_jogo->pedras);
    InicializaContadorDePedrasMarcadasJogo(a_jogo);
    for(i = 0; i < a_jogo->pedras; i++)
    {
        numSorteado = GeraProxNumero();
        printf("Pedra:%d\n", numSorteado);
        ImprimirProgressoJogo(a_jogo);
        MarcarPedra(a_jogo, numSorteado);
        qntVenceu = ChecarSeJogadoresVenceram(a_jogo);
        if(qntVenceu> 0) break;
    }
    ImprimirProgressoJogo(a_jogo);
    ImprimirVencedores(a_jogo, qntVenceu);
}

void MarcarPedra(tJogo *a_jogo, int numSorteado)
{
    int i;
    for(i = 0; i < a_jogo->quantJogadores; i++)
    {
        MarcarPedraJogador(&(a_jogo->jogador[i]), numSorteado);
    }
    
}

int ChecarSeJogadoresVenceram(tJogo *a_jogo)
{
    int i, venceu, qntVenceu = 0;
    char nome[1001];
    for(i = 0; i < a_jogo->quantJogadores; i++)
    {
        ObterNome(nome, a_jogo->jogador, i);
        venceu = 0;
        venceu = ChecarSeVenceu(&(a_jogo->jogador[i]));
        if(venceu)
        {
            strcpy(a_jogo->vencedores[qntVenceu], nome);
            qntVenceu++;
        }
       
    }
    return qntVenceu;
}


void ImprimirVencedores(tJogo *a_jogo, int qntVenceu)
{
    int i;
    if(qntVenceu==1)
    {
        printf("Jogador Venceu!\n");
    }
    else
    {
        printf("Jogadores Empataram!\n");
    }
    for(i = 0; i < qntVenceu; i++)
    {
        printf("%s\n", a_jogo->vencedores[i]);
    }
}

void InicializaContadorDePedrasMarcadasJogo(tJogo *a_jogo)
{
    int i, j;
    for(i = 0; i < a_jogo->quantJogadores; i++)
    {
        InicializaContadorDePedrasMarcadasJogador(&(a_jogo->jogador[i]));
    }
}

void ImprimirProgressoJogo(tJogo *a_jogo)
{
    int i;
    for(i = 0; i < a_jogo->quantJogadores; i++)
    {
        ImprimeProgressoJogador(&(a_jogo->jogador[i]));
        printf("\n");
    }
}


void GerarEstatisticasJogo(tJogo *a_jogo, tArquivos *a_arquivos)
{  
    int i;
    char nome[1001];
    int quantCartelasTotais = 0;
    FILE* arqestatisticas;
    arqestatisticas = CriaAbreArquivo(arqestatisticas, a_arquivos->estatisticas_jogo, a_arquivos);
    quantCartelasTotais = ObterQuantCartelasTotais(a_jogo);
    CopiaTodasCartelasParaUmVetor(a_jogo);
    OrdenaCartelasEstatisticas(a_jogo, a_jogo->todasCartelas, quantCartelasTotais);
    for(i = 0; i < quantCartelasTotais; i++)
    {
        ObterNome(nome, a_jogo->jogador, a_jogo->todasCartelas[i].jogadorDono);
        fprintf(arqestatisticas , "%d - %d - %s\n", ObterQuantMarcada(a_jogo->todasCartelas[i]), ObterID(a_jogo->todasCartelas[i]), nome);
    }
    fclose(arqestatisticas);
}

void CopiaTodasCartelasParaUmVetor(tJogo *a_jogo)
{
    int i;
    int count = 0;
    for(i = 0; i < a_jogo->quantJogadores; i++)
    {
        CopiaTodasCartelasParaUmVetorAUX(&(a_jogo->jogador[i]), a_jogo->todasCartelas, &count);
    }
}

int ObterQuantCartelasTotais(tJogo *a_jogo)
{
    int i, total = 0;
    for(i = 0; i < a_jogo->quantJogadores; i++)
    {
        total += ObterQuantCartelasJogador(&(a_jogo->jogador[i]));
    }
    return total;
}


int OrdenaCartelasEstatisticas(tJogo *a_jogo, tCartela *todasCartelas, int qntCartelas)
{
   int i, j;
   char nomeCartelaJ[1001];
   char nomeCartelaJmais1[1001];
   tCartela aux;
    for (i = 0; i < qntCartelas-1; i++) 
    {
        for (j = 0; j < qntCartelas-1; j++)
        {
            ObterNome(nomeCartelaJ, a_jogo->jogador, todasCartelas[j].jogadorDono);
            ObterNome(nomeCartelaJmais1, a_jogo->jogador, todasCartelas[j+1].jogadorDono);
            if (todasCartelas[j].qntPedrasMarcadas < todasCartelas[j+1].qntPedrasMarcadas) 
            {
                aux = todasCartelas[j];
                todasCartelas[j] = todasCartelas[j+1];
                todasCartelas[j+1] = aux;
            }
            else if(todasCartelas[j].qntPedrasMarcadas == todasCartelas[j+1].qntPedrasMarcadas
                    && strcmp(nomeCartelaJ, nomeCartelaJmais1) > 0)
            {
                aux = todasCartelas[j];
                todasCartelas[j] = todasCartelas[j+1];
                todasCartelas[j+1] = aux;
            }
            else if(todasCartelas[j].qntPedrasMarcadas == todasCartelas[j+1].qntPedrasMarcadas
                    && strcmp(nomeCartelaJ, nomeCartelaJmais1) == 0 && todasCartelas[j].id > todasCartelas[j+1].id)
            {
                aux = todasCartelas[j];
                todasCartelas[j] = todasCartelas[j+1];
                todasCartelas[j+1] = aux;
            }
        }
    }
}

void GerarBonus(tJogo *a_jogo, tArquivos *a_arquivos)
{
    int i, menosMarcada[20];
    FILE* arqbonus;
    char nome[20][1001];
    arqbonus = CriaAbreArquivo(arqbonus, a_arquivos->bonus, a_arquivos);
    for(i = 0; i < a_jogo->quantJogadores; i++)
    {
        menosMarcada[i] = ObterMenosMarcadaJogador(&(a_jogo->jogador[i]));
        ObterNome(nome[i], a_jogo->jogador, i);
    }
    OrganizarBonus(nome, menosMarcada, a_jogo->quantJogadores);
    for(i=0; i < a_jogo->quantJogadores; i++)
    {
        ImprimirMenosMarcada(arqbonus, nome[i], menosMarcada[i]);
    }
    fclose(arqbonus);
}

void OrganizarBonus(char nome[][1001],int* menosMarcada, int qntNumeros)
{
    int i, j, auxmarcada;
    char auxnome[1001];
    for (i = 0; i < qntNumeros-1; i++) 
    {
        for (j = 0; j < qntNumeros-i-1; j++)
        {
            if (menosMarcada[j] < menosMarcada[j+1] ||
                    (menosMarcada[j] == menosMarcada[j+1] && strcmp(nome[j], nome[j+1]) > 0)) 
            {
                auxmarcada = menosMarcada[j];
                menosMarcada[j] = menosMarcada[j+1];
                menosMarcada[j+1] = auxmarcada;
                strcpy(auxnome, nome[j]);
                strcpy(nome[j], nome[j+1]);
                strcpy(nome[j+1], auxnome);
            }
        }
    }
}