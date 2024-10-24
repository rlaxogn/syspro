#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "db.dat.h"

int main(int argc, char *argv[])
{
	int fd, id;
	char c; 
	struct db.dat record;
	if (argc < 2) {
		fprintf(stderr, "How to use : %s file\n", argv[0]);
		exit(1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1) {
		perror(argv[1]);
		exit(2);
	}
	do {
		printf("\Enter id to search:");
	if (scanf("%d", &id) == 1) {
		lseek(fd, (id-START_ID)*sizeof(record), SEEK_SET);
	if(read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0)
		printf("id:%s\t name:%d\t category:%d\t expired date:%d\t stock:%d\n ", record.id, record.name, record.category, record.expire date, record.stock);
	else printf("Record %d Null\n", id);
	}
	scanf(" %c", &c);
	}
	close(fd);
	exit(0);
}
