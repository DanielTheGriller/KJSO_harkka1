// Daniel Linna
// 0509355
// Käyttöjärjestelmät ja systeemiohjelmointi 2018
// Harjoitustyö 1: unix utilities - my-zip.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define length 64

// Function for reading file and compressing it to stdout
void compress(char file[length]){
	char buffer, prev;
	int n = 0;
	FILE *fp = fopen(file, "r");

// Exit with code 1 if cannot open file	
	if (fp == NULL){
		printf("my-zip: cannot open file\n");
		exit(1);
	}

// Actual compressing part

// Read file until end of file is reached
	while((buffer = fgetc(fp)) != EOF){

//If quantity = 0, set previous to character read
		if (n == 0){ 
			prev = buffer;
		}
// If previous equals character read, increase quantity
		if (prev == buffer){
			n++;
		}
// Otherwise, write quantity and character to stdout in binary
		else {
			fwrite(&n, 4, 1, stdout);
			fwrite(&prev, 1, 1, stdout);
// Prepare variables for next character
			n = 1;
			prev = buffer;	 
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
		printf("my-zip: file1 [file2 ...]\n");
		exit(1);
	}

	if (argc > 1){
//Send files to compress funtion one at a time
		for (i=1; i<argc; i++){
			strcpy(file, argv[i]);
			compress(file);
		}
	}
}







/**************************************** EOF ******************************************/
