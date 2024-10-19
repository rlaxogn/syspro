#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <string.h>
#include <stdbool.h>

char type(mode_t);
char *perm(mode_t);

int main(int argc, char **argv) {
    DIR *dp;
    char *dir;
    struct stat st;
    struct dirent *d;
    char path[BUFSIZ+1];

    dir = ".";
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            for (int j = 1; argv[i][j] != '\0'; j++) {
                switch (argv[i][j]) {
                    case 'a': showAll = true; break;
                    case 'l': longFormat = true; break;
                    case 'h': humanReadable = true; break;
                    default:
                        fprintf(stderr, "Unknown option: -%c\n", argv[i][j]);
                        exit(1);
                }
            }
        } else {
            dir = argv[i];
        }
    }

    if ((dp = opendir(dir)) == NULL) {
        perror(dir);
        exit(1);
    }

    while ((d = readdir(dp)) != NULL) {
        if (!showAll && d->d_name[0] == '.')
            continue;

        sprintf(path, "%s/%s", dir, d->d_name);
        if (lstat(path, &st) < 0)
            perror(path);
        else {
            if (longFormat)
                printStat(path, d->d_name, &st, humanReadable);
            else
                printf("%s\n", d->d_name);
        }
    }

    closedir(dp);
    exit(0);
}

        while (sizeD >= 1024 && unitIdx < 4) {
            sizeD /= 1024;
            unitIdx++;
        }
        printf("%7.1f%c ", sizeD, units[unitIdx]);
    } else {
        printf("%9ld ", size);
    }
}

char type(mode_t mode) {
    if (S_ISREG(mode)) return('-');
    if (S_ISDIR(mode)) return('d');
    if (S_ISCHR(mode)) return('c');
    if (S_ISBLK(mode)) return('b');
    if (S_ISLNK(mode)) return('l');
    if (S_ISFIFO(mode)) return('p');
    if (S_ISSOCK(mode)) return('s');
    return('?');
}

char* perm(mode_t mode) {
    static char perms[10];
    strcpy(perms, "---------");

    for (int i = 0; i < 3; i++) {
        if (mode & (S_IRUSR >> i*3))
            perms[i*3] = 'r';
        if (mode & (S_IWUSR >> i*3))
            perms[i*3+1] = 'w';
        if (mode & (S_IXUSR >> i*3))
            perms[i*3+2] = 'x';
    }
    return(perms);
}

