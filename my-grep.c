// Daniel Linna
// 0509355
// Käyttöjärjestelmät ja systeemiohjelmointi 2018
// Harjoitustyö 1: unix utilities - my-grep.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define length 64

// Function which prints line if the key word is in it
void compareLine (char *line, char *word){
// Got help from https://stackoverflow.com/questions/17422217/strstr-to-find-a-word-in-a-string-using-c-returning-true-all-the-time to use strstr()
	if (strstr(line, word) != NULL){
		printf("%s", line);
	}
}

// Function to read stdin if no file as parameter
void readInput (char *word){
	char inputLine[128];
	while(fgets(inputLine, sizeof(inputLine), stdin) != NULL){
		compareLine(inputLine, word);
	}
}

//Function for reading lines from files
void readFile (char file[length], char *word){
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	FILE *fp = fopen(file, "r");

// Exit with code 1 if cannot open file
	if (fp == NULL){
		printf("my-grep: cannot open file\n");
		exit(1);
	}

// Read lines and send them to compare function
	while((nread = getline(&line, &len, fp)) != -1){
		compareLine(line, word);
	}

// Free allocated memory and close filestream
	free(line);
	fclose(fp);
}


// MAIN 
int main (int argc,const char * argv[]){
	char file[length], word[length];
	int i;

// Print instructions if no parameters
	if (argc == 1){
		printf("my-grep: searchterm [file ...]\n");
		exit(1);
	}

// Read stdin if no file as parameter
	if (argc == 2){
		strcpy(word, argv[1]);
		readInput(word);
		exit(0);
	}

// Go through command line parameters	
	if (argc > 2){
		strcpy(word, argv[1]);
		for (i=2; i<argc; i++){
			strcpy(file, argv[i]);
			readFile(file, word);
		}

	}	
// Exit with code 0 if successful run
	exit(0);
}

/**************************************** EOF ******************************************/
