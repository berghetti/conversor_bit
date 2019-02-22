#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "config.h"


void usage(void){
	printf("%s\nprograma para converter unidades de medidas computacionais b, B, Mb, MB...\n", PACKAGE_NAME);
	printf("use: %s <valor> <opção>\n", PACKAGE);
	puts("<valor>\n"
		 "  Ex: 64b\n"
		 "  Ex: 10Mb\n"
		 "  Ex: 10.2MB\n");

	puts("<opção>\n"
		 "  -v    [não utiliza notação cientifica]\n"
		 "  -h    [exibe essa mensagem]\n");

	puts("<exemplo>\n"
		 "./conv 100.2Kb -v");
		
	puts("");
	
	exit(EXIT_FAILURE);
}


float convertForBit(float valor, int unidade){
	float bits;
	switch(unidade){
		case 1: bits = valor; break; //bit
		case 2: bits = valor * 8; break; //byte
		case 3: bits = valor * pow(BASE, 3); break; //kilobit
		case 4: bits = valor * pow(BASE, 3) * 8; break;  //kilobyte
		case 5: bits = valor * pow(BASE, 6); break; //megabit
		case 6: bits = valor * pow(BASE, 6) * 8; break; //megabyte
		case 7: bits = valor * pow(BASE, 9) ; break; //gigabit
		case 8: bits = valor * pow(BASE, 9) * 8; break; //gigabyte
		case 9: bits = valor * pow(BASE, 12) ; break; //terabit
		case 10: bits = valor * pow(BASE, 12) * 8; break; //terabyte		
	}
	return bits;
}


void imprimir(float bit){

	float byte = bit / 8;
	float Kb = bit / pow(BASE, 3);
	float KB = bit / pow(BASE, 3) / 8;
	float Mb = bit / pow(BASE, 6);
	float MB = bit / pow(BASE, 6) / 8;
	float Gb = bit / pow(BASE, 9);
	float GB = bit / pow(BASE, 9) / 8;
	float Tb = bit / pow(BASE, 12);
	float TB = bit / pow(BASE, 12) / 8;


	if(verbose){

		bit == (int) bit ? printf("%-10s %db\n", "bit:", (int) bit) : printf("%-10s %.2fb\n", "bit:", bit);
		byte == (int) byte ? printf("%-10s %dB\n", "byte:", (int) byte) : printf("%-10s %.2fB\n", "byte:", byte);
		Kb == (int) Kb ? printf("%-10s %dKb\n", "kilobit:", (int) Kb) : printf("%-10s %.2fKb\n", "kilobit:", Kb);
		KB == (int) KB ? printf("%-10s %dKB\n", "kilobyte:", (int) KB) : printf("%-10s %.2fKB\n", "KB:", KB);
		Mb == (int) Mb ? printf("%-10s %dMb\n", "megabit:", (int) Mb) : printf("%-10s %.2fMb\n", "megabit:", Mb);
		MB == (int) MB ? printf("%-10s %dMB\n", "megabyte:", (int) MB) : printf("%-10s %.2fMB\n", "megabyte:", MB);
		Gb == (int) Gb ? printf("%-10s %dGb\n", "gigabit:", (int) Gb) : printf("%-10s %.2fGb\n", "gigabit:", Gb);
		GB == (int) GB ? printf("%-10s %dGB\n", "gigabyte:", (int) GB) : printf("%-10s %.2fGB\n", "gigabyte:", GB);
		Tb == (int) Tb ? printf("%-10s %dTb\n", "terabit:", (int) Tb) : printf("%-10s %.2fTb\n", "terabit:", Tb);
		TB == (int) TB ? printf("%-10s %dTB\n", "terabyte:", (int) TB) : printf("%-10s %.2fTB\n", "terabyte:", TB);

	}else{

		printf("%-10s %Gb\n", "bit:", bit);
		printf("%-10s %GB\n", "byte:", byte);
		printf("%-10s %GKb\n", "kilobit:", Kb);
		printf("%-10s %GKB\n", "kilobyte:", KB);
		printf("%-10s %GMb\n", "megabit:", Mb);	
		printf("%-10s %GMB\n", "megabyte", MB);
		printf("%-10s %GGb\n", "gigabit:", Gb);	
		printf("%-10s %GGB\n", "gigabyte", GB);
		printf("%-10s %GTb\n", "terabit:", Tb);
		printf("%-10s %GTB\n", "terabyte:", TB);

	}
	
}