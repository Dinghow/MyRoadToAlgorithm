#include<iostream>
#include<vector>
#include<stdio.h>
#include<cmath>

using namespace std;

int getVal(vector<char>& set, int r){
    int val = 0;
    for(int i = 0; i < set.size(); i++){
        val = val*r + set[i] - '0';
    }
    return val;
}

bool isPrime(int val){
    if(val < 2) return false;
    for(int i = 2; i < sqrt(val); i++){
        int tmp = val%i;
        if(tmp == 0) return false;
    }
    return true;
}

void getNum(vector<char>& set, int x, int r){
    while(x>0){
        char tmp = x%r+'0';
        x /= r;
        set.push_back(tmp);
    }
}

int main(){
    int a,b;
    while(scanf("%d %d", &a, &b)){
        if(a < 0) break;
        vector<char> set;
        getNum(set, a, b);
        if(isPrime(a) && isPrime(getVal(set, b))) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    
    return 0;
}