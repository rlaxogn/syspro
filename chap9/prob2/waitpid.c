#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() 
{
	int pid1, pid2, child, status;
	
    printf("[%d] 부모 프로세스 시작 \n", getpd( ));
    pid1 = fork();
    
	if(pid1 == 0) 	 
		printf("[%d] 자식 프로세스[1] 시작 \n", getpid( ));
		sleep(1);
		printf("[%d] 자식 프로세스[1] 종료 \n", getpid( ));
 		exit(1);
}
	pid2 = fork();
	if(pid2 == 0) {
		printf("[%d] 자식 프로세스 #2 시작 \n", getpid( ));
	    sleep(2);
	    printf("[%d] 자식 프로세스 #2 종료 \n", getpid( ));
	    exit(2);
	}
	child = waitpid(pid1, &status, 0); 
	printf("[%d] 자식 프로세스 #1 %d 종료 \n", getpid( ), child);
	printf("\t종료 코드 %d\n", status>>8);
	
	child = waitpid(pid2, &status, 0); 
	printf("[%d] 자식 프로세스 #2 %d 종료 \n", getpid(), child);
	printf("\t종료 코드 %d\n", WEXITSTATUS(status)
}
