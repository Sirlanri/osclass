#include<stdio.h>
#include<iostream>
using namespace std;

struct Neicun
{
    int ram[3]={100,100,100};
    int currentid=0;

}neicun;

bool appendram(struct Neicun *neicun,int id){
    bool flag=false;
    for (int i = 0; i < 3; i++)
    {
        if (neicun->ram[i]==id)
        {
            flag=true;
        }
        
    }
    if (!flag)
    {
        neicun->ram[neicun->currentid]=id;
        if (neicun->currentid<2)
        {
            neicun->currentid++;
        }else
        {
            neicun->currentid=0;
        }
        return true;
    }
    return false;
    
}

void printram(struct Neicun *neicun,int id,bool result){
    cout<<"After insert:"<<id<<endl;
    if (result)
    {
        cout<<" changed!"<<endl;
    }
    
    for (int i = 0; i < 3; i++)
    {
        cout<<neicun->ram[i]<<endl;
    }
    
}

int main(){
    Neicun neicun1;
    int optionNums[17]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1};

    for (int i = 0; i < 17; i++)
    {
        bool res=appendram(&neicun1,optionNums[i]);
        printram(&neicun1,optionNums[i],res);
    }
    
    return 0;
}