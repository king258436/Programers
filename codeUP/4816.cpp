#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    int a=0;
    int b=0;
    int c =0;
    bool flag=true;
    while(1){
        if(t>=300){
            t-=300;
            a++;
        }
        else if(t>=60){
            t-=60;
            b++;
        }
        else{
            t-=10;
            c++;
        }
        if(t==0){
            break;
        }
        else if(t<0){
            flag=false;
            break;
        }
    }
    if(flag){
        cout<<a<<' '<<b<<' '<<c;
    }
    else{
        cout<<-1;
    }
}
