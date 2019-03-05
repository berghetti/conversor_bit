#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>		// for getopt()
#include "conv.h"


bool verbose = false;

int main (int argc, char *argv[]){

	int in_arg;

	int pos = 1;
	if(argc < 2){
		usage();
	}

	// verifica argumentos passados
	while ((in_arg = getopt(argc, argv, "hv")) != -1){
		switch (in_arg){
			case 'h':
				usage();
				break;
			case 'v':
				verbose = true;
				pos++;
				break;
		}
	}


	char *unidade;
	// separa o valor da unidade informada, ex: 10MB, valor = 10, unidade = MB
	float valor = strtof(argv[pos], &unidade);


	if (*unidade == '\0'){
		usage();
	}
	else{
		float bits = convertForBit(valor, unidade);
		if (bits)
			imprimir(bits);
		else
			usage();
	}

	return 0;
}

