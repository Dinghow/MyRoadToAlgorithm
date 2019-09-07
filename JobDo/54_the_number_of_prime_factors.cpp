#include<iostream>
#include<cmath>

using namespace std;

int primes[100000];
int mark[100000] = {false};

int main(){
    int counter = 0;
    for(int i = 2; i <= 100000; i++) {
        if (mark[i]) continue;
        mark[i] = true;
        primes[counter] = i;
        counter++;
        if(i >= 1000) continue;
        for (int k = i * i; k <= 100000; k += i) {
            mark[k] = true;
        }
    }
    int N;
    while(cin>>N){
        int nums = 0;
        for(int i = 0; i < counter; i++){
            while(N%primes[i] == 0){
                nums++;
                N/=primes[i];
            }
            if(N == 1) break;
        }
        if(N != 1) nums++;
        cout<<nums<<endl;
    }

    return 0;
}