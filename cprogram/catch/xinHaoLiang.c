#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void *print_msg(void *arg);
pthread_mutex_t mutex;

int main(int argc,char **argv){
    pthread_t id1;
    pthread_t id2;
    pthread_t id3;
    pthread_t id4;
    pthread_mutex_init(&mutex,NULL);
    pthread_create(&id1,NULL,print_msg,NULL);
    pthread_create(&id2,NULL,print_msg,NULL);
    pthread_create(&id3,NULL,print_msg,NULL);
    pthread_create(&id4,NULL,print_msg,NULL);
    pthread_join(id1,NULL);
    pthread_join(id2,NULL);
    pthread_join(id3,NULL);
    pthread_join(id4,NULL);

    pthread_mutex_destroy(&mutex);
    return 0;
}

void *print_msg(void *arg){
    int i=0;
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < 5; i++)
    {
        printf("output: %d \n",i);
        usleep(100);
        
    }
    pthread_mutex_unlock(&mutex);
    
}