#include<iostream>
#include<vector>

using namespace std;

int dp[101];

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

struct Rice{
    int v, w;
    Rice(int val, int wei):v(val),w(wei){}
};

int main(){
    int C, n, m, p, h, c;
    cin>>C;
    while(C>0){
        cin>>n>>m;
        vector<Rice> rice;
        for(int i = 1; i <= m; i++){
            cin>>p>>h>>c;
            int k = 1;
            bool flag = false;
            while(c>0){
                c -= k;
                if(c<0){
                    flag = true;
                    break;
                }
                rice.push_back(Rice(k*p,k*h));
                k *= 2;
            }
            if(flag) {
                int res = c + k;
                rice.push_back(Rice(res * p, res * h));
            }
        }
        for(int i = 1; i <= n; i++) dp[i] = 0;
        for(int i = 0; i < rice.size();i++){
            for(int j = n; j >= rice[i].v; j--){
                dp[j] = max(dp[j], dp[j-rice[i].v]+rice[i].w);
            }
        }
        cout<<dp[n]<<endl;
        C--;
    }

    return 0;
}