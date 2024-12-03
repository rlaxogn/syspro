#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void a_signal(int signo, void (*handler)(int)) {
	struct sigaction act;
	act.sa_handler = handler;
	sigaction(signo, &act, NULL);
}

void alarmHandler(int signo) {
	printf("Wake up\n");
	exit(0);
}

int main() {
	signal(SIGALRM, alarmHandler);
	alarm(5);

	for(int i = 1; ; i++) {
		sleep(1);
		printf("%d second\n", i);
	}
	return 0;
}
