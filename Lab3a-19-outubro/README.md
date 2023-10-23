<h1>Laboratório 3a</h1>

<h3>Laboratório realizado no dia 19 de outubro</h3>

<ins>Conteúdo:</ins> Neste laboratório, exploramos a multiplicação de matrizes com o uso de threads em C. O programa realiza a multiplicação de duas matrizes, A e B, para obter a matriz resultante C. O código utiliza threads para distribuir o trabalho de multiplicação entre diferentes processos.

<ins>Integrantes:</ins>

- Diogo Lourenzon Hatz
- Leila Akina Ino
- Livia Alabarse dos Santos

<h2>Índice</h2>

<ul>
<li><code>multiplicamatrizes.c</code>: Código-fonte do exercício proposto. 
<li><code>log</code>: Log das saída relativa à execução do programa acima.
</ul>

<h2>Compilação</h2>

Para realizar a compilação dos códigos-fonte aqui disponibilizados, faz-se necessária a utilização do compilador GCC. Caso não o tenha instalado, basta digitar o seguinte comando em um terminal linux: <code>sudo yum install gcc</code>. A compilação dos arquivos .c deste repositório podem ser compilados da seguinte forma: <code>gcc exemplo.c</code>, em que o campo exemplo é substituído pelo nome do arquivo .c. Após isso, um arquivo <code>a.out</code> será gerado

<img src="https://github.com/Hatz-D/ProjetoSOs/blob/main/src/3a-compilacao.png" alt="Processo de compilação">

<hr>
<h2>Execução</h2>
Para executá-lo, basta digitar o seguinte comando: <code>./a.out</code>. Caso o arquivo gerado possua um nome diferente, basta substituir o arquivo <code> a.out</code> pelo nome do arquivo gerado no comando anterior.
<img src="https://github.com/Hatz-D/ProjetoSOs/blob/main/src/3a-execucao.png" alt="Processo de execução">

<hr>
<h2>Geração do log de execução</h2>

Para realizar a geração do log de execução dos programas aqui disponibilizados, o método de redirecionamento de saída padrão do Linux foi utilizado por meio do operador de append: <code>>></code>. O código-fonte foi compilado e executado, suas saídas foram adicionadas ao arquivo "log" aqui disponível através do seguinte comando: <code>gcc multiplicamatrizes.c -o teste.bin -lpthread && ./teste.bin >> log</code>.

<img src="https://github.com/Hatz-D/ProjetoSOs/blob/main/src/3a-logs.png" alt="Processo de geração do log">

<hr>
<h2>Exercício</h2>
A função multiplicamatrizes é responsável por calcular cada célula da matrizC. Ela recebe um argumento com as coordenadas da célula a ser calculada (<code>i</code> e <code>j</code>), bem como o número de colunas n da matriz A, que é igual ao número de linhas n da matriz B (<code>n</code>). As threads criadas posteriormente executarão essa função para efetuar os cálculos.

A função imprimematriz é utilizada para exibir as matrizes na tela, facilitando a visualização dos resultados.

Na função main, as dimensões das matrizes A e B são obtidas e verificadas para garantir que sejam compatíveis para a multiplicação. O programa, então, aloca um array de threads chamado <code>thread_array</code>.

Um loop aninhado percorre as coordenadas das células de matrizC. Para cada célula, uma nova thread é criada utilizando <code>pthread_create</code>.

Depois de criar todas as threads, um segundo loop (for) aguarda a conclusão de cada uma com pthread_join, garantindo que todas as threads tenham terminado seus cálculos antes de prosseguir.

Por fim, as matrizes A, B e C são impressas na tela usando a função imprimematriz, permitindo que você veja o resultado da multiplicação.
