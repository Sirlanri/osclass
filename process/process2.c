#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
    int i;
    int pid= fork();
    if (pid==0)
    {
        for ( i = 0; i < 10; i++)
        {
            sleep(1);
            printf("Son! %d\n",i);
        }
        
    }else if (pid>0)
    {
        for ( i = 0; i < 10; i++)
        {
            sleep(2);
            printf("Main! %d\n",i);
        }
        
    }else
    {
        printf("Error!!!");
    }
    return 0;
    
    
    
}
