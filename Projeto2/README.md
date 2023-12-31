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

<p>O código utiliza uma estrutura de dados chamada Pessoa, que contém informações sobre o instante em que uma pessoa chega à escada (instante), o sentido do seu movimento na escada (fluxo),<code> 0 da esquerda para direita e 1 da direita para esquerda</code>, e se a pessoa já passou pela escada (computado). A alocação dinâmica de memória é realizada para armazenar as informações de todas as pessoas. A lógica principal do código está na parte do cálculo do tempo total. O código percorre cada pessoa e, para cada uma delas, verifica se há alguma outra pessoa na escada que pode causar conflito de fluxo. Se houver, ajusta o tempo total para garantir que a pessoa atual possa utilizar a escada sem colidir com outras.

No cálculo do tempo total, o programa percorre cada pessoa na escada e determina o tempo necessário pra que ela se mova. O tempo é ajustado com base nas condições específicas: se é a primeira pessoa, o tempo é seu instante de chegada mais 10 segundos, caso contrário, o tempo depende do instante da pessoa anterior e é incrementado em 10 segundos.

Em seguida, o programa verifica as pessoas subsequentes, considerando a direção do fluxo e o espaço entre elas. Se duas pessoas têm o mesmo fluxo, o programa verifica se é possível que a segunda pessoa suba imediatamente após a primeira. Se possível, o tempo total é ajustado e a segunda pessoa é marcada como processada. Se as pessoas têm fluxos opostos, o programa reduz o contador com base no tempo entre elas.

O loop continua para as demais pessoas, garantindo que o tempo total leve em conta as condições específicas de cada caso. O resultado final é o tempo necessário pra que todas as pessoas passem pela escada rolante.  
O loop externo percorre todas as pessoas, e o loop interno compara a pessoa atual com as pessoas subsequentes. Se as condições para utilização da escada são atendidas, o tempo total é ajustado e o contador é reiniciado. Se não, o loop interno é interrompido.

Ao final da execução, o código imprime o tempo total necessário para que todas as pessoas utilizem a escada sem problemas de concorrência.

Ademais, o programa aceita um argumento da linha de comando, representando o modo de povoamento do vetor relativo às pessoas que irão utilizar a escada rolante: manual, pseudoaleatório ou por meio de arquivo. Para o modo manual, as informações relativas a cada pessoa deverão ser indicadas pelo terminal. Para o modo pseudoaleatório, o vetor é populado de acordo com um número pseudoaleatório gerado e mapeado para um intervalo determinado de acordo com o tempo atual, levando em consideração que duas pessoas não podem chegar à escada ao mesmo tempo e que uma pessoa não pode chegar à escada no momento de seu desligamento, a fim de evitar o problema de deadlock. Para o modo de entrada por arquivo, as informações relativas a cada pessoa deverão estar presentes em um arquivo de testes, arquivo cujo nome deve ser informado pelo terminal durante a execução do programa. Ao término da execução, o programa exibe os momentos em que cada pessoa chega à escada rolante, a direção em que irão e, ao fim, o tempo final em que a escada rolante será desligada.

<hr>
<h2>Compilação</h2>
Para realizar a compilação dos códigos-fonte aqui disponibilizados, faz-se necessária a utilização do compilador GCC. Caso não o tenha instalado, basta digitar o seguinte comando em um terminal Linux: <code>sudo yum install gcc</code>. A compilação do arquivo transferencia.c deste repositório pode ser realizada da seguinte forma: <code>gcc escadarolante.c</code>. Após isso, um arquivo <code>a.out</code> será gerado.

<img src = "https://github.com/Hatz-D/ProjetoSOs/blob/main/src/compilacaoProjeto2.png" alt="Compilação">

<hr>
<h2>Execução</h2>
Para executá-lo, basta digitar o seguinte comando: <code>./a.out [Argumento 1]</code>. Caso o arquivo gerado possua um nome diferente, basta substituir o arquivo <code> a.out</code> pelo nome do arquivo gerado no comando anterior.

<img src = "https://github.com/Hatz-D/ProjetoSOs/blob/main/src/projeto2Stderr.png" alt = "Mensagem de erro ao informar parâmetros errôneamente.">

<ul>
<li><code>[Argumento 1]</code>: Modo de povoamento do vetor de pessoas. 0 = manual. 1 = automático. 2 = arquivo.</li>
</ul>

<hr>
<h2>Resultados</h2>
A saída do código mostra os instantes em que cada pessoa chegou à escada rolante e o seu fluxo. Ao fim, também é mostrado o tempo final em que a escada rolante é desligada, isto é, quando não há mais pessoas que irão utilizar a escada.  

<h3>Modo manual</h3>

<img src = "https://github.com/Hatz-D/ProjetoSOs/blob/main/src/projeto2Manual.png" alt="Bateria de testes">

<h3>Modo pseudoaleatório</h3>

<img src = "https://github.com/Hatz-D/ProjetoSOs/blob/main/src/projeto2Pseudoaleatorio.png" alt="Bateria de testes">

<h3>Modo por arquivo</h3>

<img src = "https://github.com/Hatz-D/ProjetoSOs/blob/main/src/projeto2Arquivo.png" alt="Bateria de testes">

<hr>
<h2>Geração do log de execução</h2>

O log de execução do programa foi gerado através do seguinte comando: <code>./escadarolante.bin X >> logs</code>, que representa o append da saída do código no arquivo <code>logs</code>.

<img src = "https://github.com/Hatz-D/ProjetoSOs/blob/main/src/geracaologsProjeto2.png" alt="Geração do log de execução">
