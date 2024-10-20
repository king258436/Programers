#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int cnt=0;
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        if(a%2==1){
            cnt++;
        }
    }
    printf("%d",cnt);
}