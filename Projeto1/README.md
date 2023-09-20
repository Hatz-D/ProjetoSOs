<h1>PROJETO 1 – SISTEMAS OPERACIONAIS</h1>

<h3>Introdução</h3>

<ins>Conteúdo:</ins> O objetivo principal deste projeto é desenvolver uma solução para resolver o problema de concorrência identificado na implementação de um sistema de transferência de fundos entre as contas "from" e "to".

<ins>Integrantes:</ins>

- Diogo Lourenzon Hatz
- Leila Akina Ino
- Livia Alabarse dos Santos

<h2>Índice</h2>

<ul>
<li><code>transferencia.c</code>: Código-fonte do projeto.</li>
<li><code>log</code>: Registro de execução criado no ambiente virtual da AWS.</li>
</ul>

<h2>Compilação</h2>

Para realizar a compilação dos códigos-fonte aqui disponibilizados, faz-se necessária a utilização do compilador GCC. Caso não o tenha instalado, basta digitar o seguinte comando em um terminal Linux: <code>sudo yum install gcc</code>. A compilação do arquivo transferencia.c deste repositório pode ser realizada da seguinte forma: <code>gcc  transferencia.c -lpthread</code>. Após isso, um arquivo <code>a.out</code> será gerado.

<hr>
<h2>Execução</h2>

Para executá-lo, basta digitar o seguinte comando: ./a.out [Argumento 1] [Argumento 2] [Argumento 3]. Caso o arquivo gerado possua um nome diferente, basta substituir o arquivo a.out pelo nome do arquivo gerado no comando anterior com -o.

<hr>
<h2>Resultados</h2>
