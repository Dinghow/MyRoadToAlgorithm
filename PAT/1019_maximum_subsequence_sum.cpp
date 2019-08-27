#include<iostream>

using namespace std;
struct Node{
    int sta;
    int val;
}result[10000];

int seq[10000];

int main(){
    int K, max, index = 0;
    cin>>K;
    cin>>seq[0];
    result[0].val = seq[0];
    result[0].sta = 0;
    max = result[0].val;
    for(int i = 1; i < K; i++){
        cin>>seq[i];
        result[i].val = result[i-1].val>=0?result[i-1].val+seq[i]:seq[i];
        result[i].sta = result[i-1].val>=0?result[i-1].sta:i;
        if(result[i].val>max){
            max = result[i].val;
            index = i;
        }
    }
    if(max >= 0) cout<<max<<" "<<seq[result[index].sta]<<" "<<seq[index];
    else{
        cout<<0<<" "<<seq[0]<<" "<<seq[K-1];
    }
    
    return 0;
}