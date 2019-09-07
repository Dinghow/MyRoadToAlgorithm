#include<iostream>
#include<vector>
#include<map>

using namespace std;

int colors[10000];
map<int, int> col_map;

int main(){
    int N, M, K, a, b;
    vector<int> adj[10000];
    cin>>N>>M;
    for(int i = 0; i < M; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin>>K;
    for(int i = 0; i < K; i++){
        int tmp;
        int k = 0;
        col_map.clear();
        for(int j = 0; j < N; j++){
            cin>>tmp;
            colors[j] = tmp;
            if(col_map.find(tmp) == col_map.end()){
                col_map[tmp] = k;
                k++;
            }
        }
        bool flag = false;
        for(int j = 0; j < N; j++){
            for(int l = 0; l < adj[j].size(); l++){
                if(colors[j] == colors[adj[j][l]]){
                    flag = true;
                    break;
                }
            }
        }
        if(flag) cout<<"No"<<endl;
        else cout<<k<<"-coloring"<<endl;
    }

    return 0;
}