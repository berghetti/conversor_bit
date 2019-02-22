#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "config.h"


bool verbose = false;

int main (int argc, char *argv[]){

	int in_arg;
	int pos = 1;
	if(argc < 2){
		usage();
	}


	while ((in_arg = getopt (argc, argv, "hv")) != -1){
		switch (in_arg){
			case 'h':
				usage(); break;
			case 'v':
				verbose = true;
				pos++;
				break;
		}
	}

	char *endptr;
	float valor = strtof(argv[pos], &endptr);

	if(*endptr == '\0'){
		usage();
	}

	if (*endptr != '\0'){
		float bit;
		if(strcmp(endptr, "b") == 0){
			bit = convertForBit(valor, 1);
			imprimir(bit);
		}
		else if(strcmp(endptr, "B") == 0){
			bit = convertForBit(valor, 2);
			imprimir(bit);
		}
		else if(strcmp(endptr, "Kb") == 0){
			bit = convertForBit(valor, 3);
			imprimir(bit);
		}
		else if(strcmp(endptr, "KB") == 0){
			bit = convertForBit(valor, 4);
			imprimir(bit);
		}
		else if(strcmp(endptr, "Mb") == 0){
			bit = convertForBit(valor, 5);
			imprimir(bit);
		}
		else if(strcmp(endptr, "MB") == 0){
			bit = convertForBit(valor, 6);
			imprimir(bit);
		}
		else if(strcmp(endptr, "Gb") == 0){
			bit = convertForBit(valor, 7);
			imprimir(bit);
		}
		else if(strcmp(endptr, "GB") == 0){
			bit = convertForBit(valor, 8);
			imprimir(bit);
		}
		else if(strcmp(endptr, "Tb") == 0){
			bit = convertForBit(valor, 9);
			imprimir(bit);
		}
		else if(strcmp(endptr, "TB") == 0){
			bit = convertForBit(valor, 10);
			imprimir(bit);
		}else{
			usage();
		}
	}

	return 0;
}

