# Bingo
>Projeto Final da matéria Programação II (UFES - Eng. Comp. - 1* Período), que utiliza a linguaguem C para ensinar os conceitos iniciais de programação.
>As especificações mais detalhadas do projeto estão na pasta "Especificações".

Esse repositório se trata da **minha** implentação do programa pedido.
Caso deseje utilizar tentar realizar o projeto por você mesmo, reutilize *somente* os arquivos tGeradorAle.h e tGeradorAle.c, pois estes foram fornecidos pelo professor para auxiliar na geração de números "aleatórios" *pero no mucho* para que seja possível ter um resultado consistente e avaliar as saidas do programa comparando com os casos de teste fornecidos.

#### Funcionamento Simplificado do projeto: 
O projeto consiste de um jogo de bingo, em que as configurações do jogo, como tamanho das cartelas, nome dos jogadores, etc são passados por meio de um arquivo de configuração.

Nossa tarefa é criar um programa que leia esses dados e por meio deles gere um jogo de bingo, gerando cartelas "aleatórias" para cada jogador do jogo e alocando as mesmas em um arquivo. Em seguida deve rodar um loop de sorteio de pedras, e marcar essas pedras nas próprias cartelas, sempre imprimindo o resultado parcial para o usuário, parando quando alguma cartela estiver completa, anunciando em seguida o(s) vencedor(es).
Por fim, gerar um arquivo com as estatísticas de jogo, onde será apresentado cada cartela e seu respectivo dono de forma ordenada.
