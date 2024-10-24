#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "db.dat.h"

int main(int argc, char *argv[])
{
	int fd, id;
	char c;
	struct db record;
	if (argc < 2) {
		fprintf(stderr, "How to use : %s file\n", argv[0]);
		exit(1);
	}
	if ((fd = open(argv[1], O_RDWR)) == -1) {
		perror(argv[1]);
		exit(2);
	}
	do {
		printf("Enter id to be modified: ");
	if (scanf("%d", &id) == 1) {
		lseek(fd, (long) (id-START_ID)*sizeof(record), SEEK_SET);
	if ((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0)) {
		printf("id:%8d\t name:%4s\t category:%4d\n expired date:%4d\n stock:%4d\n", record.id, record.name, record.category, record.expired date, record.stock);
		printf("Enter New Score: ");
		scanf("%d", &record.score);
		lseek(fd, (long) -sizeof(record), SEEK_CUR);
		write(fd, (char *) &record, sizeof(record));
	} 
	else printf("Record %d Null\n", id);
	} 
	} 
	close(fd);
	exit(0);
}
