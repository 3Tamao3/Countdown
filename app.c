#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>

void handle_signal(int sig) {
    if (sig == SIGINT) {
        printf("\nCountdown stopped by user.\n");
        exit(0);
    }
}



int main(void)
{
	int secs = 0;

	printf("Seconds: ");
	scanf("%d", &secs);

	printf("\nPress CTRL+C to terminate the process\n");

	while (secs > 0)
	{
		signal(SIGINT, handle_signal);

		int h = secs / 3600;
		int m = (secs % 3600) / 60;
		int s = secs % 60;

		printf("\r%02d:%02d:%02d", h, m, s);

		fflush(stdout);

		clock_t stop = clock() + CLOCKS_PER_SEC;
		while(clock() < stop){}

		secs--;
	}

	printf("\nTime is up!!!\n");

	return (0);
}
