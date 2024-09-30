#include <stdio.h>
#include <string.h>
#include "copy.h"

#define MAXLINE 100
#define MAXLINES 5

int main() {
	char lines[MAXLINES][MAXLINE];
	int count = 0;

	while (count < MAXLINE && fgets(lines[count], MAXLINE, stdin) != NULL) {
		if(lines[count][strlen(lines[count]) - 1] == '\n') {
				lines[count][strlen(lines[count]) - 1] = '\0';
		}
				count++;
	}

	for(int i = 0; i < count - 1; i++) {
		for(int j = i + 1; j < count; j++) {
			if(strlen(lines[i]) < strlen(lines[j])) {
				char temp[MAXLINE];
				strcpy(temp, lines[i]);
				strcpy(lines[i], lines[j]);
				strcpy(lines[j], temp);
			}
		}
	}
	for(int i = 0; i < count; i++) {
		printf("%s\n", lines[i]);
	}

	return 0;
}
