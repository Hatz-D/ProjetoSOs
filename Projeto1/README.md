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
<li><code>logs</code>: Registro de execução criado no ambiente virtual da AWS.</li>
</ul>

<h2>Desnvolvimento</h2>
<h3>Problema</h3>
O código original enfrenta um problema relacionado à concorrência inadequada entre subprocessos. Nesse código, subprocessos são gerados usando a função <code>clone</code>, onde cada subprocesso representa uma cópia independente do processo pai e realiza operações de transferência. O problema central desse código reside na falta de mecanismos adequados para sincronizar as transações, o que pode resultar em resultados incorretos ou inesperados. Existe uma condição de corrida no código, onde vários subprocessos tentam executar a função <code>transferencia</code> simultaneamente. Essa questão surge devido ao compartilhamento dos saldos entre os subprocessos.

<hr>
<h3>Solução</h3>
O código desenvolvido para solucionar este problema é uma adaptação do código original. Iniciamos incluindo as bibliotecas necessárias, como <code>stdio</code> para entrada e saída padrão, <code>pthread</code> para manipulação de threads, <code>stdlib</code> para alocação de memória e <code>time</code> para geração de números aleatórios. O código simula transações bancárias concorrentes entre duas contas, chamadas <code>from</code>  e <code>to</code>. Ele utiliza threads para representar as diferentes transações que ocorrem simultaneamente. Os Mutexes (mutex de exclusão mútua) são utilizados para garantir que somente uma thread por vez possa acessar e modificar as contas, evitando conflitos e inconsistências nos saldos. Quando a thread sai da seção critica, o mutex é liberado, permitindo que outras threads acessem a seção crítica e executem suas operações em segurança.

O programa aceita dois argumentos da linha de comando: o primeiro argumento representa o número de transações a serem realizadas, enquanto o segundo argumento indica o valor de cada transação. Ele começa com saldos iniciais nas contas e, em seguida, cria threads para simular as transações. Durante a execução, as threads verificam se há saldo suficiente na conta de origem antes de efetuar a transferência. Ao término da execução, o programa exibe os saldos das contas <code>from</code> e <code>to</code>, juntamente com o número de transações bem-sucedidas e as que falharam devido à falta de saldo.

Além disso o código adaptado:
<ul>
<li>Introduz a escolha aleatória da conta de origem e destino para cada thread (0 para 'from' --> 'to' | 1 para 'to' --> 'from').</li>
<li>Após a conclusão de todas as threads e operações o código 'destrói' o mutex, liberando os recursos alocados.</li>
</ul>

<hr>
<h2>Compilação</h2>

Para realizar a compilação dos códigos-fonte aqui disponibilizados, faz-se necessária a utilização do compilador GCC. Caso não o tenha instalado, basta digitar o seguinte comando em um terminal Linux: <code>sudo yum install gcc</code>. A compilação do arquivo transferencia.c deste repositório pode ser realizada da seguinte forma: <code>gcc  transferencia.c -lpthread</code>. Após isso, um arquivo <code>a.out</code> será gerado.

<img src = "https://github.com/Hatz-D/ProjetoSOs/blob/main/src/projeto1-Gcc.png" alt="Compilação">

<hr>
<h2>Execução</h2>

Para executá-lo, basta digitar o seguinte comando: <code>./a.out [Argumento 1] [Argumento 2]</code>. Caso o arquivo gerado possua um nome diferente, basta substituir o arquivo <code> a.out</code> pelo nome do arquivo gerado no comando anterior.

<img src = "https://github.com/Hatz-D/ProjetoSOs/blob/main/src/projeto1-Stderr.png" alt = "Mensagem de erro ao informar parâmetros errôneos">

<ul>
<li><code>[Argumento 1]</code>: Quantidade de transações (inteiro).</li>
<li><code>[Argumento 2]</code>: Valor das transações (decimal).</li>
</ul>

<hr>
<h2>Resultados</h2>

A saída do código mostra a quantidade de transações ocorridas, saldo final das duas contas e caso não seja o suficiente, também mostra quantas transações falharam devido a falta de saldo.  

<img src = "https://github.com/Hatz-D/ProjetoSOs/blob/main/src/projeto1-Testes.png" alt="Bateria de testes">

<img src = "https://github.com/Hatz-D/ProjetoSOs/blob/main/src/projeto1-Gera%C3%A7%C3%A3o%20do%20Log.png" alt="Geração do log de execução">
