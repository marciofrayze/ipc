/*
Interpretador IPC+- versão 0.144
Insane Software - divisão Useless
Este código se encontra disponével sob a licença GNU GENERAL PUBLIC LICENSE 2 e
foi baseado nos programas PTM e Cinple, ambos feitos por Daniel Scapin.

Copyright (C) 2004  Marcio Frayze David

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Formas de contato :
Email  : mfdavid@gmail.com
Cartas : Rua Jubiaba, 110, Vila Madalena. CEP 05444-039, São Paulo, SP - Brasil.

Comandos diponíveis:
Ix => Verifica se o elemento na cabeça eh igual ao elemento x (x pode ser um
caracter qualquer). Se for continua executando a linha, caso contrário passa
para a próxima linha
P  => Imprime no console o caracter da fita que esta na posição da cabeça
Cx => Coloca x no local onde está a cabeça (x pode ser um caracter qualquer)
+  => Move a cabeça para direita
-  => Move a cabeça para esquerda
/  => Indica que todo o resto da linha é comentario

Para mais informações, consulte o arquivo Manual-IPC.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constantes */
const int ESPACO = 32;

/* Vars globais do interpretador */
char fita[999]; // Vetor representando a fita
int posicaoCabeca = 499; // Posiciona a cabeça no meio da fita

/* Escopo das funções */
void interpretador( FILE * file );
void proximaLinha( FILE * file );

/* Função principal */
int main( int argc, char *argv[] ) {

  // Caso usuário não tenha passado o arquivo a ser interpretado, sair com erro
  if (argc != 2) {
    printf("\nModo de uso :\n%s script.ic\n\n", argv[0]);
    exit(1);
  }

  // Inicializando fita com espaços
  int i=0;
  for ( i=0; i<1000; i++ ) fita[i]=ESPACO;

  FILE * file = fopen(argv[1], "r"); // Abrindo arquivo de entrada para leitura
  // Verificando se o arquivo foi aberto corretamente
  if ( file == 0 ) {
    printf("\nERRO: Nao foi possivel abrir o arquivo '%s'!\n\n", argv[1]);
    exit(1);
  }

  interpretador( file ); // Interpretando arquivo de entrada ! :-)

  printf("\n\n");
  return(0);
}


void interpretador( FILE * file ) {

  char c; // Toda vez que lermos um caracter ele será colocado aqui
  fscanf( file, "%c", &c ); // Le o proximo caracter */

  // Lendo entrada caracter por caracter, até chegar ao fim
  while( !feof(file) ) {

    switch ( c ) {
    case '+' :
      // Move a cabeça para a direita
      if ( posicaoCabeca < 999 ) posicaoCabeca++;
      break;

    case '-' :
      // Move a cabeça para a esquerda
      if ( posicaoCabeca > 0 ) posicaoCabeca--;
      break;

    case 'P' :
      // Imprime o caracter que estiver na cabeça
      printf("%c", fita[posicaoCabeca] );
      break;

    case 'C' :
      // Altera o caracter que estiver na cabeça pelo próximo caracter que estiver no código
      fscanf( file, "%c", &c );
      fita[posicaoCabeca]=c;
      break;

    case 'I' :
      // Pegando próximo caracter e guardando em c
      fscanf( file, "%c", &c );
      // Caso c seja diferente do caracter da cabeça, pule para próxima linha do código
      if ( fita[posicaoCabeca] != c ) {
	proximaLinha( file );
      }
      break;

    case '/' :
      // Todo o resto da linha são comentários, então vamos pular para próxima linha
      proximaLinha( file );
      break;

    case 10 :
      // Ignora o indicador de fim de linha (apenas para evitar cair no default por engano)
      break;

    default :
      // Se o codigo chegou aqui, é porque o interpretador achou um simbolo que não é válido!
      printf("\nERRO: '%c' nao é uma instrucao valida! Por favor verifique seu script.\n\n",c);
      exit(1);
      break;

    }

    fscanf( file, "%c", &c ); /*  próximo caracter */
  }
}

// Move o cursor para o início da próxima linha
void proximaLinha( FILE * file ) {
  char c;
  while ( c != '\n' && c != '\r') c = fgetc( file );
}
