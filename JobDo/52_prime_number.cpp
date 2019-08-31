#include<iostream>
#include<cmath>
#include<vector>
#define MAX_B 1000000
typedef long long LL;

using namespace std;

bool primes[MAX_B];

bool isPrime(LL n){
    LL bound = sqrt(n);
    for(int i = 2; i <= bound; i++){
        if(n%i == 0) return false;
    }
    return true;
}

int main(){
    int n;
    vector<LL> pris;
    fill(primes, primes+MAX_B, true);
    for(LL i = 2; i < MAX_B; i++){
        if(!primes[i]) continue;
        bool is_pri = isPrime(i);
        if(is_pri) pris.push_back(i);
        else{
            primes[i] = false;
            for(LL j = i*i; j < MAX_B; j*=i){
                primes[j] = false;
            }
        }
    }

    while(cin>>n){
        cout<<pris[n-1]<<endl;
    }

    return 0;
}