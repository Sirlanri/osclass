#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>

const char *sem_name="/mysem2";
const char *title="                ProcB";
sem_t *sem;

int main() {
    sleep(1);
    sem = sem_open(sem_name,O_CREAT,0644,2);
	printf("\n%s %p\n",title,sem);
    for (int i=0; i<10; i++) {
	    printf("%s %d\n",title,i);
	    printf("%s prepare.\n",title);
		sem_wait(sem);
	    printf("%s enter.\n",title);
		sleep(1);
	    printf("%s leave.\n",title);
		sem_post(sem);
		sleep(1);
	}
	sem_close(sem);
	sem_unlink(sem_name);
	return 0;
}
