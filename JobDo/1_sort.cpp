#include<iostream>
#include<stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int buf[100];

    while(scanf("%d",&n) != EOF){
        for(int i = 0; i < n; i++){
            cin>>buf[i];
        }
        sort(buf,buf+n);
        for(int i = 0; i < n; i++){
            cout<<buf[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}