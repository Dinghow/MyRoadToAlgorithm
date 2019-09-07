#include<iostream>
#include<cmath>

using namespace std;

char str[1001];

int strToNum(char *s, int l){
    int num = 0;
    for(int i = 0; i < l; i++){
        num = num*10 + s[i]-'0';
    }
    return num;
}

bool isPrime(int n){
    int bound = sqrt(n);
    for(int i = 2; i < bound; i++){
        if(n%i == 0) return false;
    }
    return true;
}

int main(){
    int L, K;
    while(cin>>L>>K){
        cin>>str;
        char tmp[11];
        bool flag = true;
        for(int i = 0; i <= L-K; i++){
            for(int j = 0; j < K; j++){
                tmp[j] = str[i+j];
            }
            tmp[K] = '\0';
            bool is_p = isPrime(strToNum(tmp, K));
            if(is_p){
                cout<<tmp<<endl;
                flag = false;
                break;
            }
        }
        if(flag) cout<<404<<endl;
    }
    return 0;
}