// Daniel Linna
// 0509355
// Käyttöjärjestelmät ja systeemiohjelmointi syksy 2018
// Harjoitustyö 1: unix utilities - my-cat.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define length 64


//Function for handling files and printing it's content
void readFile (char file[length]){
	char buffer;
	FILE *fp = fopen(file, "r");
// Exit with code 1 if cannot open file
	if (fp == NULL){
		printf("my-cat: cannot open file\n");
		exit(1);
	}
// Print the file character by character
	while((buffer = fgetc(fp)) != EOF){
		printf("%c", buffer);
	}
	fclose(fp);
}


int main (int argc,const char * argv[]){
	char file[length];
	int i;
// Exit if no files as argument
	if (argc == 1){
		exit(0);
	}
	
// Go through command line parameters	
	if (argc > 1){
		for (i=1; i<argc; i++){
			strcpy(file, argv[i]);
			readFile(file);
		}

	}	
// Exit with code 0 if succesful run
	exit(0);
}

/**************************************** EOF ******************************************/
