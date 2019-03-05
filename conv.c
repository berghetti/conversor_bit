#include <stdio.h>
#include <stdlib.h>
#include <math.h> 		// for pow()
#include <stdbool.h>
#include <string.h> 	//for strcmp()
#include "conv.h"


void usage(void){
	printf("%s\nprograma para converter unidades de medidas computacionais b, B, Mb, MiB...\n", PACKAGE_NAME);
	printf("use: %s <valor> <opção>\n", PACKAGE);
	puts("<valor>\n"
		 "  Ex: 64b\n"
		 "  Ex: 10Mb\n"
		 "  Ex: 10.2MB\n");

	puts("<opção>\n"
		 "  -v    [não utiliza notação cientifica]\n"
		 "  -h    [exibe essa mensagem]\n");

	puts("<exemplo>\n"
		 "./conv 100Kb -v\n"
		 "./conv 50MiB");
		
	puts("");
	
	exit(EXIT_FAILURE);
}


float convertForBit(float valor, char *unidade){

		if(strcmp(unidade, "b") == 0)
			return valor; 						//bit

		else if(strcmp(unidade, "B") == 0)
			return valor * 8; 					//byte

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		else if(strcmp(unidade, "Kb") == 0)
			return valor * pow(BASE_10, 3); 	//kilobit

		else if(strcmp(unidade, "Mb") == 0)
			return valor * pow(BASE_10, 6); 	//megabit

		else if(strcmp(unidade, "Gb") == 0)
			return valor * pow(BASE_10, 9) ;	//gigabit

		else if(strcmp(unidade, "Tb") == 0)
			return valor * pow(BASE_10, 12) ; 	//terabit

		// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		
		else if(strcmp(unidade, "KB") == 0)
			return valor * pow(BASE_10, 3) * 8; //kilobyte
		
		else if(strcmp(unidade, "MB") == 0)
			return valor * pow(BASE_10, 6) * 8; //megabyte		

		else if(strcmp(unidade, "GB") == 0)
			return valor * pow(BASE_10, 9) * 8; //gigabyte

		else if(strcmp(unidade, "TB") == 0)
			return valor * pow(BASE_10, 12) * 8; //terabyte

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		
		else if(strcmp(unidade, "Kib") == 0)
			return valor * pow(BASE_2, 10); 	// kibibit

		else if(strcmp(unidade, "Mib") == 0)
			return valor * pow(BASE_2, 20); 	// Mebibit

		else if(strcmp(unidade, "Gib") == 0)
			return valor * pow(BASE_2, 30); 	// Gebibit

		else if(strcmp(unidade, "Tib") == 0)
			return valor * pow(BASE_2, 40); 	// Tebibit

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		
		else if(strcmp(unidade, "KiB") == 0)
			return valor * pow(BASE_2, 10) * 8;	// Kibibyte

		else if(strcmp(unidade, "MiB") == 0)
			return valor * pow(BASE_2, 20) * 8;	// Mebibyte

		else if(strcmp(unidade, "GiB") == 0)
			return valor * pow(BASE_2, 30) *8;  // Gebibyte

		else if(strcmp(unidade, "TiB") == 0)
			return valor * pow(BASE_2, 40) *8;  // Tebibyte

		else
			return false;
}


void imprimir(float bit){

	float byte = bit / 8;

	float Kb = bit / pow(BASE_10, 3);				// kilobit
	float Mb = bit / pow(BASE_10, 6);				// megabit
	float Gb = bit / pow(BASE_10, 9);				// gigabit
	float Tb = bit / pow(BASE_10, 12);				// terabit

	float KB = bit / pow(BASE_10, 3) / 8;			// kilobyte
	float MB = bit / pow(BASE_10, 6) / 8;			// megabyte
	float GB = bit / pow(BASE_10, 9) / 8;			// gigabyte
	float TB = bit / pow(BASE_10, 12) / 8;			// terabyte

	float Kib = bit / pow(BASE_2, 10);  			// kibibit
	float Mib = Kib / pow(BASE_2, 10); 				// mebibit
	float Gib = Kib / pow(BASE_2, 20); 				// gibibit
	float Tib = Kib / pow(BASE_2, 30); 				// tebibit

	float KiB = bit / pow(BASE_2, 10) / 8;		    // kibibyte
	float MiB = Kib / pow(BASE_2, 10) / 8;          // mebibyte
	float GiB = Kib / pow(BASE_2, 20) / 8;          // gibibyte
	float TiB = Kib / pow(BASE_2, 30) / 8;          // tebibyte


	if(verbose){

		bit == (int) bit ? printf("%-10s %db\n", "bit:", (int) bit) : printf("%-10s %.2fb\n", "bit:", bit);
		byte == (int) byte ? printf("%-10s %dB\n", "byte:", (int) byte) : printf("%-10s %.2fB\n", "byte:", byte);

		printf("\n");
		Kb == (int) Kb ? printf("%-10s %dKb\n", "kilobit:", (int) Kb) : printf("%-10s %.2fKb\n", "kilobit:", Kb);
		Mb == (int) Mb ? printf("%-10s %dMb\n", "megabit:", (int) Mb) : printf("%-10s %.2fMb\n", "megabit:", Mb);
		Gb == (int) Gb ? printf("%-10s %dGb\n", "gigabit:", (int) Gb) : printf("%-10s %.2fGb\n", "gigabit:", Gb);
		Tb == (int) Tb ? printf("%-10s %dTb\n", "terabit:", (int) Tb) : printf("%-10s %.2fTb\n", "terabit:", Tb);

		printf("\n");
		KB == (int) KB ? printf("%-10s %dKB\n", "kilobyte:", (int) KB) : printf("%-10s %.2fKB\n", "kilobyte:", KB);
		MB == (int) MB ? printf("%-10s %dMB\n", "megabyte:", (int) MB) : printf("%-10s %.2fMB\n", "megabyte:", MB);
		GB == (int) GB ? printf("%-10s %dGB\n", "gigabyte:", (int) GB) : printf("%-10s %.2fGB\n", "gigabyte:", GB);
		TB == (int) TB ? printf("%-10s %dTB\n", "terabyte:", (int) TB) : printf("%-10s %.2fTB\n", "terabyte:", TB);

		printf("\n");
		Kib == (int) Kib ? printf("%-10s %dKib\n", "Kibibit:", (int) Kib) : printf("%-10s %.2fKib\n", "Kibibit:", Kib);
		Mib == (int) Mib ? printf("%-10s %dMib\n", "Mebibit:", (int) Mib) : printf("%-10s %.2fMib\n", "Mebibit:", Mib);
		Gib == (int) Gib ? printf("%-10s %dGib\n", "Gibibit:", (int) Gib) : printf("%-10s %.2fGib\n", "Gibibit:", Gib);
		Tib == (int) Tib ? printf("%-10s %dTib\n", "Tebibit:", (int) Tib) : printf("%-10s %.2fTib\n", "Tebibit:", Tib);

		printf("\n");
		KiB == (int) KiB ? printf("%-10s %dKiB\n", "kibibyte:", (int) KiB) : printf("%-10s %.2fKiB\n", "kibibyte:", KiB);
		MiB == (int) MiB ? printf("%-10s %dMiB\n", "Mebibyte:", (int) MiB) : printf("%-10s %.2fMiB\n", "Mebibyte:", MiB);
		GiB == (int) GiB ? printf("%-10s %dGiB\n", "Gebibyte:", (int) GiB) : printf("%-10s %.2fGiB\n", "Gebibyte:", GiB);
		TiB == (int) TiB ? printf("%-10s %dTiB\n", "Tebibyte:", (int) TiB) : printf("%-10s %.2fTiB\n", "Tebibyte:", TiB);

	}else{

		printf("%-10s %Gb\n", "bit:", bit);
		printf("%-10s %GB\n", "byte:", byte);

		printf("\n");
		printf("%-10s %GKb\n", "kilobit:", Kb);
		printf("%-10s %GMb\n", "megabit:", Mb);
		printf("%-10s %GGb\n", "gigabit:", Gb);
		printf("%-10s %GTb\n", "terabit:", Tb);

		printf("\n");
		printf("%-10s %GKB\n", "kilobyte:", KB);
		printf("%-10s %GMB\n", "megabyte:", MB);
		printf("%-10s %GGB\n", "gigabyte:", GB);
		printf("%-10s %GTB\n", "terabyte:", TB);

		printf("\n");
		printf("%-10s %GKib\n", "Kibibit:", Kib);
		printf("%-10s %GMib\n", "Mebibit:", Mib);
		printf("%-10s %GGib\n", "Gibibit:", Gib);
		printf("%-10s %GTib\n", "Tebibit:", Tib);

		printf("\n");
		printf("%-10s %GKiB\n", "kibibyte:", KiB);
		printf("%-10s %GMiB\n", "Mebibyte:", MiB);
		printf("%-10s %GGiB\n", "Gebibyte:", GiB);
		printf("%-10s %GTiB\n", "Tebibyte:", TiB);

	}
}