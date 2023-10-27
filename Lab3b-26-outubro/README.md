<h1>Laboratório 3b</h1>

<h3>Laboratório realizado no dia 26 de outubro</h3>

<ins>Conteúdo:</ins> Neste laboratório, implementamos a série de Taylor para a aproximação do valor de pi utilizando pthreads e comparamos os resultados obtidos com e sem a utilização de Mutex.

<ins>Integrantes:</ins>

- Diogo Lourenzon Hatz
- Leila Akina Ino
- Livia Alabarse dos Santos

<h2>Índice</h2>

<ul>
<li><code>pi-wo-mutex.c</code>: Código-fonte do exercício proposto sem utilizar mutex.</li> 
<li><code>pi-w-mutex.c</code>: Código-fonte do exercício proposto utilizando mutex.</li>
<li><code>log_sem_mutex</code>: Log das saída relativa à execução do programa acima sem mutex.</li>
<li><code>log_com_mutex</code>: Log das saída relativa à execução do programa acima com mutex.</li>
</ul>

<hr>
<h2>Exercício</h2>
A função calculaPi é responsável por calcular valores parciais da série de Taylor, valores os quais, ao serem somados, representam uma aproximação do valor de pi. Ao passo em que as somas parciais realizadas por cada thread são exclusivas de cada thread, a variável relativa à soma total das inúmeras parcelas é compartilhada entre todas as threads As threads criadas posteriormente executarão a função supracitada para efetuar os cálculos de valores parciais da série delimitados por intervalos fornecidos pelo usuário ao executar o programa.


<ol>
<li><code>Arg1</code>: Quantidade de threads a serem executadas pelo programa.</li>
<li><code>Arg2</code>: Número de iterações da série de Taylor por cada thread</li>
</ol>

É importante ressaltar que o vetor de argumentos das threads é alocado dinamicamente para cada thread para garantir que o argumento <code>i</code> seja passado para a função calculaPi de forma exclusiva, isto é, cada thread irá calcular uma soma parcial de um intervalo baseado na identificação numérica da thread. Caso o vetor de argumentos não fosse criado dinamicamente para cada iteração dos laços alinhados, uma condição de corrida existiria para os valores presentes no endereço de memória compartilhado entre as threads. Alocando-se esse vetor dinamicamente a cada  iteração garante que cada array de argumentos possua um endereço exclusivo, o que soluciona a condição de corrida encontrada. Ao fim de cada execução da função calculaPi, esse vetor de argumentos é desalocado.

<h3>Item a)</h3>
Ao implementar o código de aproximação do valor de pi concorrentemente utilizando Mutex, a principal diferença é que o valor relativo à soma total das somas parciais de cada thread será acessado por somente uma thread por vez, o que garante que não haja inconsistências em relação à condição de corrida no programa, uma vez que cada soma parcial da série será somada à essa variável de forma atômica. 


<h3>Item b)</h3>
Além das divergências nos resultados observados provenientes da condição de corrida existente no acesso à variável que armazena o valor de pi, também existe uma divergência ainda mais alarmante no que diz respeito à ordem imprevisível em que as threads serão executadas pelo scheduler, o que, por mais que não deveria surtir nenhum impacto no resultado do valor de pi calculado, uma vez que operações de soma e subtração são comutativas e associativas, acaba por afetar o resultado, considerando que existem notórios erros de arredondamento em operações com ponto flutuante, os quais se agravam quando acumulam. Devido a esse fenômeno e somado à condição de corrida existente na leitura e modificação do valor de pi caso o mutex não seja utilizado, é difícil de visualizar qual dos dois atores está influenciando os resultados obtidos, se é que não ambos.

Para mitigar o problema de arredondamento com ponto flutuante supracitado, isto é, fazer com que os resultados obtidos sejam constantes, é possível criar um vetor que armazenará as somas parciais de cada thread e, ao fim da execução de todas as threads, iterar por esse vetor para recuperar a soma total da aproximação de pi. No entanto, essa abordagem dispensa completamente a utilização de mutex por não existir uma região crítica de acesso na memória, o que foge do escopo deste laboratório.

<h2>Compilação</h2>

Para realizar a compilação dos códigos-fonte aqui disponibilizados, faz-se necessária a utilização do compilador GCC. Caso não o tenha instalado, basta digitar o seguinte comando em um terminal linux: <code>sudo yum install gcc</code>. A compilação dos arquivos .c deste repositório podem ser compilados da seguinte forma: <code>gcc exemplo.c -lpthread</code>, em que o campo exemplo é substituído pelo nome do arquivo .c. Após isso, um arquivo <code>a.out</code> será gerado. Vale ressaltar que como o código-fonte deste laboratório utiliza pthreads, é necessário adicionar o argumento <code>-lpthread</code> durante a compilação do programa.

<img src="https://github.com/Hatz-D/ProjetoSOs/blob/main/src/compila%C3%A7%C3%A3o-3b.png" alt="Processo de compilação">

<hr>
<h2>Execução</h2>
Para executá-lo, basta digitar o seguinte comando: <code>./a.out</code>. Caso o arquivo gerado possua um nome diferente, basta substituir o arquivo <code> a.out</code> pelo nome do arquivo gerado no comando anterior.
<img src="https://github.com/Hatz-D/ProjetoSOs/blob/main/src/execu%C3%A7%C3%A3o-3b.png" alt="Processo de execução">

<hr>
<h2>Geração do log de execução</h2>

Para realizar a geração do log de execução dos programas aqui disponibilizados, o método de redirecionamento de saída padrão do Linux foi utilizado por meio do operador de append: <code>>></code>. O código-fonte foi compilado e executado, suas saídas foram adicionadas ao arquivo "log" aqui disponível através do seguinte comando: <code>./sem_mutex.bin >> log_sem_mutex</code> e <code>./com_mutex.bin >> log_com_mutex</code>.

<img src="https://github.com/Hatz-D/ProjetoSOs/blob/main/src/gera%C3%A7%C3%A3o-logs-3b.png" alt="Processo de geração do log">



