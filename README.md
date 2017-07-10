
Manual IPC+- versão 0.144
-------------------------

1- Sobre o programa

2- Sobre o autor

3- Sintaxe do interpretador

4- Compilando e executando o interpretador

5- Códigos de exemplo

6- Termos de uso

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

1- Sobre o programa

	1.1- O que é o IPC+-

		IPC+- é um interpretador de comando extremamente simples. Sua forma de
		funcionamento foi inspirada na Maquina de Alan Turing, mas é mais simples,
		pois não temos a noção de estados, como existe na MT.

		A única forma de se armazenar informações ao se usar o IPC+- é colocando as
		informações em um fita (na verdade é um simples vetor). Depois é possível
		exibir o dado armazenado ou ainda fazer verificações com ele.

	1.2- Qual a utilidade?

	Basicamente nenhuma :-) Foi criado por diversão, mas pode ser usado para
		aprendizado na linguagem C. Ele é muito simples, mas contém toda a estrutura
		de um interpretador "de verdade" precisaria ter.

2- Sobre o autor

	2.1- Dados sobre o autor

		O IPC+- foi criado por Marcio Frayze David, um estudande de Ciência da Compuação
		da Pontifícia Universidade Católica de São Paulo. Alguns códigos criados por
		Daniel Scapin foram usados como base para criação deste programa.

	2.2- Formas para entrar em contato

		Para entrar em contato com o autor, envie um email para mfdavid@gmail.com ou
		mande uma carta para :
		Rua Jubiaba, 110, Vila Madalena. CEP 05444-039, São Paulo, SP - Brasil

3- Sintaxe do interpretador

	3.1- Usando os comandos + e -

		O IPC+- usa uma fita (vetor) para armazenas as informações, então precisamos
		andar por este vetor para realizarmos nossas tarefas. Para isso, usamos o comando
		+ para avançar pela fita, e o - para retroceder. Podemos usar estes comandos
		quantas vezes forem necessárias.
		Exemplo : +-++

	3.2- Usando o comando C

		O comando C é usado para alterar o valor armazenado na posição atual da fita.
		Ao usá-lo, sempre coloque um outro caracter qualquer após esse comando, e esse
		caracter será armazenado na fita.
		Exemplo : Ca

	3.3- Usando o comando P

		Usamos o comando P para imprimir o caracter corrente da fita no console. Use o
		comando C para armazenas algo na fita, depois o P para imprimi-lo na tela.
		Exemplo : CaP

	3.4- Usando o comando I

		Este comando é usado para fazer comparações simples. Ao usá-lo, coloque um
		caracter qualquer logo após ele. Caso o caracter seja igual ao caracter que se
		encontra na posição atual da fita, o interpretador continuará executando o seu
		código normalmente. Caso sejam diferentes, ele irá ignorar todo o resto
 		daquela linha e irá passar para a próxima linha do script.
		Exemplo : CxIxP

	3.5- Escrevendo comentários no código

		Para comentar seu código, basta colocar o caracter / e todo o resto da linha será
		ignorado pelo interpretador!

4- Compilando e executando o interpretador

	4.1- Compilando

		Provavelmente qualquer compilador de C irá compilar o IPC+- sem qualquer
		problema, mas recomendo usar o GCC e um ambiente *unix.
		Para compilar com o GCC use : gcc -o IPC IPC.c

		OBS: junto com o ZIP estão incluódos os binários para Linux e MS Windows.

	4.2- Executando o interpretador

		Caso use Linux, digite : ./IPC script.ipc
		Caso use Windows, no prompt do DOS execute :
		IPC.exe script.ipc
		Caso use outro Sistema Operacional, terá que compilar o código antes..

5- Códigos de exemplo

	Junto com o interpretador foram colocados alguns exemplos simples de scripts que o
	IPC+- É capaz de interpretar (arquivos .ipc). Veja seus códigos para entender melhor
	como o interpretador funciona. ;-)

6- Termos de uso

	O IPC+- utiliza a licen�a GNU GENERAL PUBLIC LICENSE 2, sendo assim você pode modifica-lo,
	redistribui-lo, etc. Para mais informações, leia o arquivo GNU.txt.



Copyleft 2004. Insane Software.
