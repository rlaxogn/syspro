#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        printf("Send: [%d] Hello from PID %d\n", getppid(), getpid());
    } else { 
		printf("Send: [%d] Hello from PID %d\n", getpid(), pid);
    }
    
    return 0;
}
