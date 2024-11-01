#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024


int print_file(FILE *file){
	// print file contents, line by line
	char line[MAX_LEN];
	int line_no = 0;
	// printf("Contents of %s:\n", argv[1]);
	while(fgets(line, sizeof(line), file) != NULL){
		printf("%d %s", ++line_no, line);
	}
	return 0;

}

void print_help(void){
	printf("\nCommands:\n\th: print help\n\tp: print file\n\t...\n\n");
}

int main(int argc, char **argv){
	// (void) argc;
	// (void) argv;
	FILE *file;
	char input[MAX_LEN];

	if(argc < 2){
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return 1;
	}

	file = fopen(argv[1], "r");
	if(file==NULL){
		perror("Error opening file");
		return 1;
	}

	printf("\nEnter commands (type `q` to quit):\n");
	while(1){
		printf("> ");
		if(fgets(input, sizeof(input), stdin) == NULL){
			break; //Exit on EOF (CTRL+D)
		}

		// Remove the newline character from the input
                input[strcspn(input, "\n")] = '\0';

		// Check for exit command
		if (strcmp(input, "q") == 0) {
			break;
		}

		switch(input[0]){
			case 'p':
				print_file(file);
				break;
			case 'h':
				print_help();
				break;
			case 'a':
				// append(line);
			default:
				break;
		}
	}

	fclose(file);
	return 0;
}
