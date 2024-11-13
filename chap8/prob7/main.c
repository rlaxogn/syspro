#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[], char **environ) {
    if (argc < 2) {
        return 1;
	}

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0) {
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                char *env_value = getenv(argv[i + 1]);
                if (env_value) {
                    printf("%s=%s\n", argv[i + 1], env_value);
                }
                i++;
            } else {
                for (int j = 0; environ[j] != NULL; j++) {
                    printf("%s\n", environ[j]);
                }
            }
        } else if (strcmp(argv[i], "-u") == 0) {
            printf("My Realistic User ID: %d\n", getuid());
            printf("My Valid User ID: %d\n", geteuid());
        } else if (strcmp(argv[i], "-g") == 0) {
            printf("My Realistic Group ID: %d\n", getgid());
            printf("My Valid Group ID: %d\n", getegid());
        } else if (strcmp(argv[i], "-i") == 0) {
            printf("My process number: %d\n", getpid());
        } else if (strcmp(argv[i], "-p") == 0) {
            printf("My parent's process number: %d\n", getppid());
        }
    }

    return 0;
}

