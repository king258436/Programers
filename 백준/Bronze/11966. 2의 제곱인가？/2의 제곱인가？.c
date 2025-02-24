#include<stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    int b = a-1;
    a&b?printf("0"):printf("1");
}