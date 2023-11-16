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

<p>O problema apresentado no exercício refere-se à competição pelo uso da escada rolante bidirecional, especificamente em relação à direção em que ela estará funcionando (da ponta esquerda para a ponta direita ou vice-versa). Isso permite que os pedestres possam mudar de andar conforme a ordem em que chegam à escada e a direção da mesma. Além disso, é essencial calcular o momento em que a escada será desligada, ou seja, quando não houver mais pessoas para utilizá-la.</p>

<hr>
<h3>Solução</h3>
<h4>escadarolante.c</h4>
<p>O código desenvolvido para solucionar o problema supracitado é baseado em um método iterativo, uma vez que dessa forma é mais fácil de realizar comparações entre os momentos em que as pessoas chegam à escada e responder de acordo. Ademais, o método iterativo também possibilita um maior controle em relação à ordem em que as pessoas serão processads/computadas para o cálculo do tempo final em que a escada rolante irá ser desligada, que é a principal estratégia adotada pelo grupo para a solução do problema.</p>

<p>Inicialmente o código importa as bibliotecas necessárias, como <code>stdio</code> para entrada e saída padrão, <code>stdlib</code> para alocação de memória e <code>time</code> para geração de números aleatórios relativos aos momentos em que as pessoas chegam à escada rolante e a direção em que irão. Após isso, três vetores relativos aos momentos em que as pessoas chegam à escada rolante, as direções de cada pessoa e as pessoas que já foram computados são criados dinamicamente. Em seguida, o código procede para popular os vetores de instantes e fluxos de pessoas de acordo com um número pseudoaleatório gerado e mapeado para um intervalo determinado de acordo com o tempo atual, levando em consideração que duas pessoas não podem chegar à escada ao mesmo tempo e que uma pessoa não pode chegar à escada no momento de seu desligamento, a fim de evitar o problema de deadlock. Por fim, manifestando-se através de dois laços aninhados while, inicialmente a primeira pessoa a chegar na escada é computada seguida por todas aquelas que irão utilizar a escada rolante anteriormente ao seu primeiro desligamento. Em seguida, a primeira pessoa a chegar na escada rolante no fluxo oposto da primeira pessoa é computada, assim como todas as pessoas que irão seguir no mesmo fluxo anteriormente ao próximo desligamento da escada. O algoritmo segue essa sequência de passos, calculando os tempos parciais de desligamento da escada rolante.</p>

<p>O programa aceita um argumento da linha de comando, representando a quantidade de pessoas que irão utilizar a escada rolante. Ao término da execução, o programa exibe os momentos em que cada pessoa chega à escada rolante, a direção em que irão e, ao fim, o tempo final em que a escada rolante será desligada.</p>


<h4>escadarolante2.c</h4>
<p>O código utiliza uma estrutura de dados chamada Pessoa, que contém informações sobre o instante em que uma pessoa chega à escada (instante) e o sentido do seu movimento na escada (fluxo),<code> 0 da esquerda para direita e 1 da direita para esquerda</code>. A alocação dinâmica de memória é realizada para armazenar as informações de todas as pessoas. A lógica principal do código está na parte do cálculo do tempo total. O código percorre cada pessoa e, para cada uma delas, verifica se há alguma outra pessoa na escada que pode causar conflito de fluxo. Se houver, ajusta o tempo total para garantir que a pessoa atual possa utilizar a escada sem colidir com outras.

No cálculo do tempo total, o programa percorre cada pessoa na escada e determina o tempo necessário pra que ela se mova. O tempo é ajustado com base nas condições específicas: se é a primeira pessoa, o tempo é seu instante de chegada mais 10 segundos, caso contrário, o tempo depende do instante da pessoa anterior e é incrementado em 10 segundos.

Em seguida, o programa verifica as pessoas subsequentes, considerando a direção do fluxo e o espaço entre elas. Se duas pessoas têm o mesmo fluxo, o programa verifica se é possível que a segunda pessoa suba imediatamente após a primeira. Se possível, o tempo total é ajustado e a segunda pessoa é marcada como processada. Se as pessoas têm fluxos opostos, o programa reduz o contador com base no tempo entre elas.

O loop continua para as demais pessoas, garantindo que o tempo total leve em conta as condições específicas de cada caso. O resultado final é o tempo necessário pra que todas as pessoas passem pela escada rolante.  
O loop externo percorre todas as pessoas, e o loop interno compara a pessoa atual com as pessoas subsequentes. Se as condições para utilização da escada são atendidas, o tempo total é ajustado e o contador é reiniciado. Se não, o loop interno é interrompido.

Ao final da execução, o código imprime o tempo total necessário para que todas as pessoas utilizem a escada sem problemas de concorrência.


<hr>
<h2>Compilação</h2>

Para realizar a compilação dos códigos-fonte aqui disponibilizados, faz-se necessária a utilização do compilador GCC. Caso não o tenha instalado, basta digitar o seguinte comando em um terminal Linux: <code>sudo yum install gcc</code>. A compilação do arquivo transferencia.c deste repositório pode ser realizada da seguinte forma: <code>gcc escadarolante.c</code>. Após isso, um arquivo <code>a.out</code> será gerado.

<img src = "https://github.com/Hatz-D/ProjetoSOs/blob/main/src/compilacaoProjeto2.png" alt="Compilação">

<hr>
<h2>Execução</h2>
<h3>escadarolante.c</h3>
h
Para executá-lo, basta digitar o seguinte comando: <code>./a.out [Argumento 1]</code>. Caso o arquivo gerado possua um nome diferente, basta substituir o arquivo <code> a.out</code> pelo nome do arquivo gerado no comando anterior.

<img src = "https://github.com/Hatz-D/ProjetoSOs/blob/main/src/stderrProjeto2.png" alt = "Mensagem de erro ao informar parâmetros errôneos">

<ul>
<li><code>[Argumento 1]</code>: Quantidade de pessoas a utilizar a escada rolante (inteiro).</li>
</ul>


<h3>escadarolante2.c</h3>
<hr>
<h2>Resultados</h2>

A saída do código mostra os instantes em que cada pessoa chegou à escada rolante e o seu fluxo. Ao fim, também é mostrado o tempo final em que a escada rolante é desligada, isto é, quando não há mais pessoas que irão utilizar a escada.  

<img src = "https://github.com/Hatz-D/ProjetoSOs/blob/main/src/execucaoProjeto2.png" alt="Bateria de testes">

<hr>
<h2>Geração do log de execução</h2>

O log de execução do programa foi gerado através do seguinte comando: <code>./escadarolante.bin X >> logs</code>, que representa o append da saída do código no arquivo <code>logs</code>.

<img src = "https://github.com/Hatz-D/ProjetoSOs/blob/main/src/geracaologsProjeto2.png" alt="Geração do log de execução">
