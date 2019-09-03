#include<iostream>

using namespace std;

long long F[21];

int main(){
    int N;
    F[0] = 0, F[1] = 0, F[2] = 1;
    for(int i = 3; i < 21; i++){
        F[i] = (i-1)*(F[i-1]+F[i-2]);
    }
    while(cin>>N){
        cout<<F[N]<<endl;
    }

    return 0;
}