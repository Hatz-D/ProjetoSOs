<h1>PROJETO 2 – SISTEMAS OPERACIONAIS</h1>

<h3>Introdução</h3>

<ins>Conteúdo:</ins> O objetivo principal deste projeto é desenvolver uma solução para resolver o problema de concorrência identificado na implementação de uma escada rolante bidirecional, tal qual proposto na maratona de programação da SBC 2021.

<ins>Integrantes:</ins>

- Diogo Lourenzon Hatz
- Leila Akina Ino
- Livia Alabarse dos Santos

<h2>Índice</h2>

<ul>
<li><code>escadarolante.c</code>: Código-fonte do projeto.</li>
<li><code>logs</code>: Registro de execução criado no ambiente virtual da AWS.</li>
</ul>

<h2>Desnvolvimento</h2>
<h3>Problema</h3>
O problema identificado no exercício proposto é a concorrência relativa ao uso da escada rolante bidirecional, mais precisamente no que diz respeito ao sentido em que ela estará operando (da ponta esquerda para a ponta direita ou vice-versa) para que os transeuntes possam mudar de andar de acordo com a ordem em que chegam à escada. Ademais, também é necessário calcular o tempo final em que a escada será desligada, ou seja, o momento em que não há mais pessoas para utilizar a escada rolante.

<hr>
<h3>Solução</h3>
O código desenvolvido para solucionar o problema supracitado é baseado em um método iterativo, uma vez que dessa forma é mais fácil de realizar comparações entre os momentos em que as pessoas chegam à escada e responder de acordo. Ademais, o método iterativo também possibilita um maior controle em relação à ordem em que as pessoas serão processads/computadas para o cálculo do tempo final em que a escada rolante irá ser desligada, que é a principal estratégia adotada pelo grupo para a solução do problema.

Inicialmente o código importa as bibliotecas necessárias, como <code>stdio</code> para entrada e saída padrão, <code>stdlib</code> para alocação de memória e <code>time</code> para geração de números aleatórios relativos aos momentos em que as pessoas chegam à escada rolante e a direção em que irão. Após isso, três vetores relativos aos momentos em que as pessoas chegam à escada rolante, as direções de cada pessoa e as pessoas que já foram computados são criados dinamicamente. Em seguida, o código procede para popular os vetores de instantes e fluxos de pessoas de acordo com um número pseudoaleatório gerado e mapeado para um intervalo determinado de acordo com o tempo atual, levando em consideração que duas pessoas não podem chegar à escada ao mesmo tempo e que uma pessoa não pode chegar à escada no momento de seu desligamento, a fim de evitar o problema de deadlock. Por fim, manifestando-se através de dois laços aninhados while, inicialmente a primeira pessoa a chegar na escada é computada seguida por todas aquelas que irão utilizar a escada rolante anteriormente ao seu primeiro desligamento. Em seguida, a primeira pessoa a chegar na escada rolante no fluxo oposto da primeira pessoa é computada, assim como todas as pessoas que irão seguir no mesmo fluxo anteriormente ao próximo desligamento da escada. O algoritmo segue essa sequência de passos, calculando os tempos parciais de desligamento da escada rolante.

O programa aceita um argumento da linha de comando, representando a quantidade de pessoas que irão utilizar a escada rolante. Ao término da execução, o programa exibe os momentos em que cada pessoa chega à escada rolante, a direção em que irão e, ao fim, o tempo final em que a escada rolante será desligada.

<hr>
<h2>Compilação</h2>

Para realizar a compilação dos códigos-fonte aqui disponibilizados, faz-se necessária a utilização do compilador GCC. Caso não o tenha instalado, basta digitar o seguinte comando em um terminal Linux: <code>sudo yum install gcc</code>. A compilação do arquivo transferencia.c deste repositório pode ser realizada da seguinte forma: <code>gcc escadarolante.c</code>. Após isso, um arquivo <code>a.out</code> será gerado.

<img src = "https://github.com/Hatz-D/ProjetoSOs/blob/main/src/compilacaoProjeto2.png" alt="Compilação">

<hr>
<h2>Execução</h2>

Para executá-lo, basta digitar o seguinte comando: <code>./a.out [Argumento 1]</code>. Caso o arquivo gerado possua um nome diferente, basta substituir o arquivo <code> a.out</code> pelo nome do arquivo gerado no comando anterior.

<img src = "https://github.com/Hatz-D/ProjetoSOs/blob/main/src/stderrProjeto2.png" alt = "Mensagem de erro ao informar parâmetros errôneos">

<ul>
<li><code>[Argumento 1]</code>: Quantidade de pessoas a utilizar a escada rolante (inteiro).</li>
</ul>

<hr>
<h2>Resultados</h2>

A saída do código mostra os instantes em que cada pessoa chegou à escada rolante e o seu fluxo. Ao fim, também é mostrado o tempo final em que a escada rolante é desligada, isto é, quando não há mais pessoas que irão utilizar a escada.  

<img src = "https://github.com/Hatz-D/ProjetoSOs/blob/main/src/execucaoProjeto2.pngg" alt="Bateria de testes">

<hr>
<h2>Geração do log de execução</h2>

O log de execução do programa foi gerado através do seguinte comando: <code>./escadarolante.bin X >> logs</code>, que representa o append da saída do código no arquivo <code>logs</code>.

<img src = "https://github.com/Hatz-D/ProjetoSOs/blob/main/src/geracaologsProjeto2.png" alt="Geração do log de execução">
