#include<iostream>

using namespace std;

int t[101], w[101];
int dp[101][1001];

int main(){
    int T, M;
    while(cin>>T>>M){
        for(int i = 1; i <= M; i++){
            cin>>t[i]>>w[i];
        }

        for(int i = 1; i <= M; i++){
            for(int j = 0; j <= T; j++){
                if(t[i]+j > T) dp[i][j] = dp[i-1][j];
                if(j-t[i]>=0)
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-t[i]]+w[i]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        cout<<dp[M][T]<<endl;
    }
}