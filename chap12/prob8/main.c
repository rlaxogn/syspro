#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 100

int main() {
    int pipefd[2];
    char buffer[BUFFER_SIZE];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    if (fork() == 0) {
        close(pipefd[0]);
        printf("input a string: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        write(pipefd[1], buffer, strlen(buffer) + 1);
        close(pipefd[1]);
        return 0;
    }

    if (fork() == 0) { 
        close(pipefd[1]);
        read(pipefd[0], buffer, BUFFER_SIZE);

        for (int i = 0; buffer[i]; i++) {
            buffer[i] = toupper(buffer[i]);
        }
        close(pipefd[0]);
        return 0;
    }

    close(pipefd[0]);
    close(pipefd[1]);
    wait(NULL);
    wait(NULL);
    return 0;
}

