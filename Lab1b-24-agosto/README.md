<h1>Laboratório 1b</h1>

<h3>Laboratório realizado no dia 24 de agosto</h3>

<ins>Conteúdo:</ins> Realizamos uma lista de exercícios sobre matrizes na linguagem de programação C em um ambiente AWS Cloud através de uma VM Linux. Os códigos-fonte dos exercícios foram compilados e executados no ambiente cloud. Vale ressaltar, no entanto, que os arquivos de compilação gerados pelo GCC não foram aqui disponibilizados, somente os códigos-fonte.

<ins>Integrantes:</ins>

- Diogo Lourenzon Hatz
- Leila Akina Ino
- Livia Alabarse dos Santos

<h2>Índice</h2>

<ul>
<li><code>exercício{1..14}.c</code>: Códigos-fonte dos exercícios propostos.</li>
<li><code>logs</code>: Logs de execução dos exercícios propostos no ambiente AWS</li>
</ul>

<h2>Compilação</h2>

Para realizar a compilação dos códigos-fonte aqui disponibilizados, faz-se necessária a utilização do compilador GCC. Caso não o tenha instalado, basta digitar o seguinte comando em um terminal linux: <code>sudo yum install gcc</code>. A compilação dos arquivos .c deste repositório podem ser compilados da seguinte forma: <code>gcc exemplo.c</code>, em que o campo exemplo é substituído pelo nome do arquivo .c. Após isso, um arquivo <code>a.out</code> será gerado. Para executá-lo, basta digitar o seguinte comando: <code>./a.out</code>. Caso o arquivo gerado possua um nome diferente, basta substituir o arquivo <code>a.out</code> pelo nome do arquivo gerado no comando anterior.

<img src="https://drive.google.com/uc?export=view&id=1rAy3DnjoXf5X_61qr8sfgXOGc6aXsoxW" alt="Processo de compilação">

<hr>

<h2>Geração do log de execução</h2>

Para realizar a geração do log de execução dos programas aqui disponibilizados, o método de redirecionamento de saída padrão do Linux foi utilizado por meio do operador de append: <code>>></code>. Os códigos-fonte foram compilados, executados e as suas saídas foram adicionadas ao arquivo "logs" aqui disponível através do seguinte comando: <code>gcc exercicio1.c -o teste.bin && ./teste.bin >> logs</code>. Vale ressaltar que, após a geração do log em sua totalidade, esse foi formatado para melhor visualização das saídas correspodentes a cada exercício. O comando acima foi utilizado para todos os 14 códigos-fonte aqui disponíveis.

<img src="https://drive.google.com/uc?export=view&id=1wPCkqd-13y_8u8O-yeZ8pj5LDkSggAa3" alt="Processo de geração do log">
