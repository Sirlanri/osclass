#include<stdio.h>

int main(){
    char ch;
    FILE* pfr = fopen("/usr/bin/info","r");
    FILE* pfw = fopen("/home/rico/code/osclass/cprogram/ioPrac/myinfo","w");

    if (NULL!=pfw)
    {
        perror("Open file");
    }

    while ((ch=fgetc(pfr))!=EOF)
    {
        fputc(ch,pfw);
    }
    fclose(pfr);
    fclose(pfw);
    return 0;
    
}