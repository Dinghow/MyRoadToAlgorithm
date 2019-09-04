#include<iostream>
#define offset 2000
#define MAX 0x7fffffff

using namespace std;

int orgs[101];
int dp[101][4001];
bool has_zero;

int main(){
    int t, n;
    cin>>t;
    int k = t;
    while(k>0){
        cin>>n;
        has_zero = false;
        for(int i = 1; i <= n; i++){
            cin>>orgs[i];
            if(!orgs[i]) has_zero = true;
        }
        for(int i = -2000; i <= 2000; i++) dp[0][i+offset] = -MAX;
        dp[0][0+offset] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = -2000; j <= 2000; j++){
                int tmp1 = -MAX, tmp2 = -MAX;
                if(j-orgs[i] >= -2000 && dp[i-1][j-orgs[i]+offset]!= -MAX){
                    tmp1 = dp[i-1][j-orgs[i]+offset]+orgs[i];
                }
                if(j+orgs[i] <= 2000 && dp[i-1][j+orgs[i]+offset] != -MAX){
                    tmp2 = dp[i-1][j+orgs[i]+offset]+orgs[i];
                }
                if(tmp1 < tmp2){
                    tmp1 = tmp2;
                }
                if(tmp1 < dp[i-1][j+offset]) tmp1 = dp[i-1][j+offset];
                dp[i][j+offset] = tmp1;
            }
        }
        cout<<"Case "<<t-k+1<<": ";
        if(dp[n][0+offset] == 0) cout<<(has_zero?0:-1)<<endl;
        else cout<<dp[n][0+offset]/2<<endl;
        k--;
    }
}