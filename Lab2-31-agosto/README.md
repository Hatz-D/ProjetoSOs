<h1>Laboratório 2</h1>

<h3>Laboratório realizado no dia 31 de agosto</h3>

<ins>Conteúdo:</ins> Escrever

<ins>Integrantes:</ins>

- Diogo Lourenzon Hatz
- Leila Akina Ino
- Livia Alabarse dos Santos

<h2>Índice</h2>

<ul>
<li><code>a</code>: Escrever</li>
<li><code>b</code>: Escrever</li>
</ul>

<h2>Compilação</h2>

Para realizar a compilação dos códigos-fonte aqui disponibilizados, faz-se necessária a utilização do compilador GCC. Caso não o tenha instalado, basta digitar o seguinte comando em um terminal linux: <code>sudo yum install gcc</code>. A compilação dos arquivos .c deste repositório podem ser compilados da seguinte forma: <code>gcc exemplo.c</code>, em que o campo exemplo é substituído pelo nome do arquivo .c. Após isso, um arquivo <code>a.out</code> será gerado. Para executá-lo, basta digitar o seguinte comando: <code>./a.out</code>. Caso o arquivo gerado possua um nome diferente, basta substituir o arquivo <code>a.out</code> pelo nome do arquivo gerado no comando anterior.

<img src="https://drive.google.com/uc?export=view&id=1rAy3DnjoXf5X_61qr8sfgXOGc6aXsoxW" alt="Processo de compilação">

<hr>

<h2>Geração do log de execução</h2>

Para realizar a geração do log de execução dos programas aqui disponibilizados, o método de redirecionamento de saída padrão do Linux foi utilizado por meio do operador de append: <code>>></code>. Os códigos-fonte foram compilados, executados e as suas saídas foram adicionadas ao arquivo "logs" aqui disponível através do seguinte comando: <code>gcc exercicio1.c -o teste.bin && ./teste.bin >> logs</code>. Vale ressaltar que, após a geração do log em sua totalidade, esse foi formatado para melhor visualização das saídas correspodentes a cada exercício. O comando acima foi utilizado para todos os 14 códigos-fonte aqui disponíveis.

<img src="https://drive.google.com/uc?export=view&id=1wPCkqd-13y_8u8O-yeZ8pj5LDkSggAa3" alt="Processo de geração do log">

<h2>Exercícios</h2>

<b>1:</b> Para valores de N grandes, as mensagens serão ordenadas pelo valor de i

<b>2:</b> Caso o programa anterior escreva as mensagens para sys.stdout ao invés de sys.stderr a saída será redirecionada para a saída padrão ao invés de realizar a separação de saída de erro e saída padrão, o que, efetivamente, é o recomendado, considerando que a saída do programa pode ser filtrada para arquivos ou para o terminal. Vale ressaltar que a função <code>fprintf</code> deve ser ajustada para <code>printf</code> de acordo com a mudança realizada no canal de saída do programa: é necessário colocar o argumento stdout explicitamente na função <code>fprintf</code> ou, então, caso seja necessário utilizar a função <code>printf</code>, apagar o argumento de troca de saída, considerando que a saída padrão do <code>printf</code> já é a stdout.
