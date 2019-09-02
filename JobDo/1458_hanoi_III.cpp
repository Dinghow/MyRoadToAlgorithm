#include<iostream>
typedef  long long LL;

using namespace std;

LL times[35];

int main(){
    int n;
    while(cin>>n){
        times[1] = 2;
        for(int i = 2; i <= n; i++){
            times[i] = 3*times[i-1]+2;
        }
        cout<<times[n]<<endl;
    }

    return 0;
}