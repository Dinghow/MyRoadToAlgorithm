#include<iostream>
#include<cstring>

using namespace std;
char s1[101], s2[101];
int dp[101][101];

int main(){
    while(cin>>s1>>s2){
        int n = strlen(s1), m = strlen(s2);
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(!i || !j) dp[i][j] = 0;
                else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}