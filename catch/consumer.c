#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t mutex;

int number = 0;

void consumer(){
    if (number<=0)
    {
        pthread_mutex_lock(&mutex);
        number--;
        usleep(100);
        pthread_mutex_unlock(&mutex);
        printf("consumer Do %d\n",number);
    }else
    {
        number--;
        usleep(100);
        //pthread_mutex_unlock(&mutex);
        printf("consumer Do %d\n",number);
    }
    
    
    
    
 
}

void producter(){
    pthread_mutex_unlock(&mutex);
    pthread_mutex_lock(&mutex);
    number++;
    usleep(100);
    pthread_mutex_unlock(&mutex);
    printf("producter Do %d\n",number);
}

void *rangeCon(void *arg){
    for (int i = 0; i < 40; i++)
    {
        consumer();
    }

}

void *rangePro(void *arg){
    for (int i = 0; i < 40; i++)
    {
        pthread_mutex_lock(&mutex);
        producter();
    }
    
}


int main(int argc,char **argv){
    pthread_t con1;
    pthread_t pro1;

    pthread_mutex_init(&mutex,NULL);

    pthread_create(&pro1,NULL,rangePro,NULL);
    pthread_create(&con1,NULL,rangeCon,NULL);

    pthread_join(con1,NULL);
    pthread_join(pro1,NULL);

    pthread_mutex_destroy(&mutex);
    return 0;
}