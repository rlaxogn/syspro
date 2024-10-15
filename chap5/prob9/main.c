#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        return 1;
    }

    char *lines[MAX_LINES];
    int count = 0;

    char buf[MAX_LINE_LENGTH];
    while (fgets(buf, sizeof(buf), file) != NULL && count < MAX_LINES) {
        lines[count] = malloc(strlen(buf) + 1);
        if (lines[count] == NULL) {
            return 1;
        }
        strcpy(lines[count], buf);
        count++;
    }

    fclose(file);


    for (int i = count - 1; i >= 0; i--) {
        printf("%s", lines[i]);
        free(lines[i]);
    }

    return 0;
}
