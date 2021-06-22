#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>   // for getopt()
#include "conv.h"

bool verbose = false;

void usage( int ext ){
	printf(
    "%s\nprograma para converter unidades de medidas computacionais b, B, Mb, MiB...\n"
	  "usege: %s <valor> <opção>\n"
	   "<valor>\n"
		 "  Ex: 64b\n"
		 "  Ex: 10Mib\n"
		 "  Ex: 10.2MB\n"
     "\n"
	    "<opção>\n"
		 "  -v    [não utiliza notação cientifica]\n"
		 "  -h    [exibe essa mensagem]\n"
     "\n"
	   "<exemplo>\n"
		 "./conv 100Kb -v\n"
		 "./conv 50MiB\n"
	   "\n",
     PACKAGE_NAME, PACKAGE_NAME );

	exit( ext );
}

int main ( int argc, char *argv[] )
{

  int in_arg;
  int pos = 1;

  if ( argc < 2 )
    usage( EXIT_FAILURE );

  // verifica argumentos passados
  while ( ( in_arg = getopt ( argc, argv, "hv" ) ) != -1 )
  {
    switch ( in_arg )
    {
      case 'h':
        usage( EXIT_SUCCESS );
        break;

      case 'v':
        verbose = true;
        pos++;
        break;
    }
  }


  char *unidade;
  // separa o valor da unidade informada, ex: 10MB, valor = 10, unidade = MB
  float valor = strtof ( argv[pos], &unidade );



  if ( *unidade == '\0' )
    usage( EXIT_FAILURE );
  else
  {
    float bits = to_bit ( valor, unidade );

    if ( bits )
      imprimir ( bits );
    else
      usage( EXIT_FAILURE );
  }

  return EXIT_SUCCESS;
}
