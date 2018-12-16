// Daniel Linna
// 0509355
// Käyttöjärjestelmät ja systeemiohjelmointi 2018
// Harjoitustyö 1: unix utilities - my-unzip.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define length 64

// Function for reading file and compressing it to stdout
void deCompress(char file[length]){
	int i, n;
	char c;
	FILE *fp = fopen(file, "r");

// Exit with code 1 if cannot open file	
	if (fp == NULL){
		printf("my-unzip: cannot open file\n");
		exit(1);
	}

// Actual deCompressing part

// Read quantity while the input is correct (fread reads 1 value)
	while(fread(&n, 4, 1, fp) == 1){
// Read the character in file
		fread(&c, 1, 1, fp);
// Print the character n times
		for (i = 0; i < n; i++){
			printf("%c", c);
		}
	}
// Close filestream
	fclose(fp);

}


int main (int argc,const char * argv[]){
	char file[length];
	int i;

// Print instructions if no parameters
	if (argc == 1){
		printf("my-unzip: file1 [file2 ...]\n");
		exit(1);
	}

	if (argc > 1){
//Send files to decompress funtion one at a time
		for (i=1; i<argc; i++){
			strcpy(file, argv[i]);
			deCompress(file);
			printf("\n");
		}
	}
}







/**************************************** EOF ******************************************/
