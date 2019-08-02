#include<iostream>

using namespace std;

int main(){
    int a,b,c,d,temp;
    char num[20];

    cin>>a>>b;
    c = a+b;
    if(c<0){
        cout<<'-';
        c = -c;
    }
    if(c>0){
        int counter = 0;
        d = c;
        while(c>0){
            temp = c%10;
            c/=10;
            num[counter] = temp+'0';
            counter++;
        }
        for(int i = counter;i>0;i--){
            if(i==6 && d/1000000>0){
                cout<<',';
            }
            if(i==3 && d/1000>0){
                cout<<',';
            }
            cout<<num[i-1];
        }
    }
    else{
        cout<<c;
    }

    return 0;
}