#include<iostream>

using namespace std;

int N[91];

int main(){
    int n;
    N[0] = 1, N[1] = 1;
    for(int i = 2; i < 91; i++){
        N[i] = N[i-1]+N[i-2];
    }
    while(cin>>n){
        cout<<N[n]<<endl;
    }
    return 0;
}