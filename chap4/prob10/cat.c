#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int c;
    int line_number = 1;
    
    if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'n') {
        print_line_numbers = 1;
   	}
        while ((c = getc(fp)) != EOF) {
            putc(c, stdout);
            if (print_line_numbers && c == '\n') {
                printf("%6d  ", line_number++);
            }
        } 
	else {
    	    if ((fp = fopen(argv[i], "r")) == NULL) {
                perror(argv[i]);
                exit(1);
            }
            line_number = 1;
            if (print_line_numbers) {
                printf("%6d  ", line_number++);
            }
            while ((c = getc(fp)) != EOF) {
                putc(c, stdout);
                if (print_line_numbers && c == '\n') {
                    printf("%6d  ", line_number++);
                }
            }
            fclose(fp);
        }
	return 0;    
}
