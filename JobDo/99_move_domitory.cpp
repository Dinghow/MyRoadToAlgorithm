#include<iostream>
#include<algorithm>
#define MAX 100000

using namespace std;

int wei[2001];
int dp[1001][2001];

int main(){
    int n, k;
    while(cin>>n>>k){
        for(int i = 1; i <= n; i++){
            cin>>wei[i];
        }
        sort(wei+1,wei+n+1);
        for(int i = 0; i <=n; i++) dp[0][i] = 0;
        for(int i = 1; i <= k; i++){
            for(int j = 2*i; j<= n; j++){
                if(j == 2*i)
                    dp[i][j] = dp[i-1][j-2]+(wei[j]-wei[j-1])*(wei[j]-wei[j-1]);
                else
                    dp[i][j] = min(dp[i][j-1],(int)(dp[i-1][j-2]+(wei[j]-wei[j-1])*(wei[j]-wei[j-1])));
            }
        }
        cout<<dp[k][n]<<endl;
    }

    return 0;
}