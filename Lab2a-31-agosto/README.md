<h1>Laboratório 2</h1>

<h3>Laboratório realizado no dia 31 de agosto</h3>

<ins>Conteúdo:</ins> Escrever

<ins>Integrantes:</ins>

- Diogo Lourenzon Hatz
- Leila Akina Ino
- Livia Alabarse dos Santos

<h2>Índice</h2>

<ul>
<li><code>fork.c</code>: Código-fonte relativo ao slide de número 7 do powerpoint de Processos</li>
<li><code>forkPaieFilho.c/code>: Código-fonte relativo ao slide de número 8 do powerpoint de Processos</li>
<li><code>ProcessID.c</code>: Código-fonte relativo ao slide de número 2 do powerpoint de Processos</li>
<li><code>ProcessosID.c</code>: Código-fonte relativo ao slide de número 9 do powerpoint de Processos</li>
<li><code>cadeiaProcessoStdout.c</code>: Código-fonte relativo ao slide de número 10 do powerpoint de Processos</li>
<li><code>cadeiaProcessoStderr.c</code>: Código-fonte relativo ao slide de número 10 do powerpoint de Processos</li>
</ul>

<h2>Compilação</h2>

Para realizar a compilação dos códigos-fonte aqui disponibilizados, faz-se necessária a utilização do compilador GCC. Caso não o tenha instalado, basta digitar o seguinte comando em um terminal linux: <code>sudo yum install gcc</code>. A compilação dos arquivos .c deste repositório podem ser compilados da seguinte forma: <code>gcc exemplo.c</code>, em que o campo exemplo é substituído pelo nome do arquivo .c. Após isso, um arquivo <code>a.out</code> será gerado. Para executá-lo, basta digitar o seguinte comando: <code>./a.out</code>. Caso o arquivo gerado possua um nome diferente, basta substituir o arquivo <code>a.out</code> pelo nome do arquivo gerado no comando anterior.

<img src="https://github.com/Hatz-D/ProjetoSOs/blob/main/src/lab2a-gccpng.png" alt="Processo de compilação">

<hr>

<h2>Geração do log de execução</h2>

Para realizar a geração do log de execução dos programas aqui disponibilizados, o método de redirecionamento de saída padrão do Linux foi utilizado por meio do operador de append: <code>>></code>. Os códigos-fonte foram compilados, executados e as suas saídas foram adicionadas ao arquivo "logs" aqui disponível através do seguinte comando: <code>gcc fork.c -o compilado.bin && ./compilado.bin >> logs</code>. Vale ressaltar que, após a geração do log em sua totalidade, esse foi formatado para melhor visualização das saídas correspodentes a cada exercício. O comando acima foi utilizado para todos os 6 códigos-fonte aqui disponíveis. Vale ressaltar, no entanto, que para o append da saída do código-fonte <code>cadeiaProcessoStderr.c</code> foi necessário realizar o redirecionamento do stderr para o stdout através do seguinte comando: <code>gcc cadeiaProcessoStderr.c -o compilado.bin && ./compilado.bin 20 >> logs 2>&1</code>

<img src="https://github.com/Hatz-D/ProjetoSOs/blob/main/src/2a-logs.png" alt="Processo de geração do log">

<h2>Exercícios</h2>

<b>1:</b> Para valores de N grandes, as mensagens serão ordenadas pelo valor de i sim, considerando que o fluxo de execução do algoritmo é o seguinte:

<ol>
<li>O processo pai realiza primeiramente uma atribuição de <code>childpid = fork()</code>. O processo pai terá o childpid com valor do pid do processo filho, enquanto o processo filho terá o valor de childpid 0.</li>
<li>Tanto o processo pai quanto o processo filho irão realizar a seguinte comparação: <code>if(childpid)</code>. O processo pai terá o valor de childpid > 0, o que, efetivamente, entra na condição de if e força a saída do loop com o break. O processo filho terá o valor de childpid = 0, o que, efetivamente, aumentará o valor de i em 1, entrando em um efeito dominó</li>
</ol>

Diante o apresentado, é possível afirmar que sim, as mensagens serão ordenadas por i.

<b>2:</b> Caso o programa anterior escreva as mensagens para sys.stdout ao invés de sys.stderr a saída será redirecionada para a saída padrão ao invés de realizar a separação de saída de erro e saída padrão, o que, efetivamente, é o recomendado, considerando que a saída do programa pode ser filtrada para arquivos ou para o terminal. Vale ressaltar que a função <code>fprintf</code> deve ser ajustada para <code>printf</code> de acordo com a mudança realizada no canal de saída do programa: é necessário colocar o argumento stdout explicitamente na função <code>fprintf</code> ou, então, caso seja necessário utilizar a função <code>printf</code>, apagar o argumento de troca de saída, considerando que a saída padrão do <code>printf</code> já é a stdout. Em termos práticos, caso o código somente seja compilado e executado, não há diferença entre os dois cenários. No entanto, caso for desejável que a saída do programa seja armazenada em um arquivo de log, é necessário redirecionar a saída stderr para a stdout no cenário em que sys.stderr é utilizada, caso contrário os prints somente serão mostrados no terminal.
