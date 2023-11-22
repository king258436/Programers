#include <stdio.h>
#include <string.h>

int deq[10001]={0,};
int size =0;

void desetting(){
    for(int i=size;i>0;i--) deq[i]=deq[i-1];
}
void push_front(int X){
    deq[0]=X;
    size+=1;
}
void push_back(int X){
    deq[size]=X;
    size+=1;
}
int pop_front(){
    if(size==0) return -1;
    else{
        size-=1;
        return deq[0];
    }
}
int pop_back(){
    if(size==0) return -1;
    else {
        size-=1;
        return deq[size];
    }
}
int front(){
    if(size==0) return -1;
    else return deq[0];
}
int back(){
    if(size==0) return -1;
    else return deq[size-1];
}
void setting(){
    for(int i=0;i<size;i++){
        deq[i]=deq[i+1];
    }
}
int empty(){
    if(size==0) return 1;
    else return 0;
}
int main(void){
    int n;
    int x;
    char command[15];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",command);
        if(!strcmp(command,"push_front")){
            desetting();
            scanf("%d",&x);
            push_front(x);
        }
        else if(!strcmp(command,"push_back")){
            scanf("%d",&x);
            push_back(x);
        }
        else if(!strcmp(command,"pop_front")){
            printf("%d\n",pop_front());
            setting();
        }
        else if(!strcmp(command,"pop_back")){
            printf("%d\n",pop_back());
        }
        else if(!strcmp(command,"size")){
            printf("%d\n",size);
        }
        else if(!strcmp(command,"front")) printf("%d\n",front());
        else if(!strcmp(command,"back")) printf("%d\n",back());
        else if(!strcmp(command,"empty")) printf("%d\n",empty());
        else;
    }
    return 0;
}