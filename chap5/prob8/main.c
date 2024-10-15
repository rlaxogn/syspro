#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINES 10
#define MAX_LINE_LENGTH 100

char savedText[MAX_LINES][MAX_LINE_LENGTH];
int Lines = 0;

void readFile(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        exit(1);
    }

    char buf;
    int i = 0, j = 0;
    while (read(fd, &buf, 1) > 0) {
        if (buf == '\n' || j == MAX_LINE_LENGTH - 1) {
            savedText[i][j] = '\0';
            i++;
            j = 0;
            if (i >= MAX_LINES) break;
        } else {
            savedText[i][j++] = buf;
        }
    }
    Lines = i;
    close(fd);
    printf("Total Line : %d\n", Lines);
    printf("You can choose 1 ~ %d Line\n", Lines);
}

void printLine(int lineNumber) {
    if (lineNumber >= 1 && lineNumber <= Lines) {
        printf("%s\n", savedText[lineNumber - 1]);
    }
}
    return 0;
}
