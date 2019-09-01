#include<iostream>

using namespace std;

int ans[101][101];

void init(){
    for(int i = 0; i < 101; i++)
        for(int j = 0; j < 101; j++){
            ans[i][j] = -1;
    }
}

int main(){
    int n, m;
    while(cin>>n>>m){
        if(!n && !m) break;
        init();
        for(int i = 0; i < m; i++){
            int a, b, c;
            cin>>a>>b>>c;
            ans[a][b] = c;
            ans[b][a] = c;
        }
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(ans[i][k] != -1 && ans[k][j] != -1) {
                        int tmp = ans[i][k] + ans[k][j];
                        if(ans[i][j] == -1) ans[i][j] = tmp;
                        else
                            ans[i][j] = (tmp < ans[i][j]) ? tmp : ans[i][j];
                    }
                }
            }
        }
        cout<<ans[1][n]<<endl;
    }

    return 0;
}