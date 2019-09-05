#include<iostream>
#include<algorithm>
#define MAX 0x7fffffff

using namespace std;

struct Coin{
    int p, w;
};

Coin coins[501];

int dp[10000];

int main(){
    int T, E, F, N, P, W;
    cin>>T;
    while(T>0){
        cin>>E>>F;
        cin>>N;
        for(int i = 1; i <= N; i++){
            cin>>coins[i].p>>coins[i].w;
        }
        for(int i = 0; i <= F-E; i++){
            dp[i] = MAX;
        }
        dp[0] = 0;
        for(int i = 1; i <= N; i++){
            for(int j=coins[i].w; j <= F-E; j++){
                if(dp[j-coins[i].w] != MAX)
                    dp[j] = min(dp[j-coins[i].w]+coins[i].p,dp[j]);
            }
        }
        if(dp[F-E] == MAX) cout<<"This is impossible."<<endl;
        else cout<<"The minimum amount of money in the piggy-bank is "<<dp[F-E]<<"."<<endl;

        T--;
    }

}