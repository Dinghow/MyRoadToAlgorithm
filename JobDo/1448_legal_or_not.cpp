#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 10000

using namespace std;

struct Edge{
    int d;
    Edge(int des):d(des){}
};

int in_d[101];
bool vis[101];

int main(){
    int n, m;
    while(cin>>n>>m){
        if(!n && !m) break;
        vector<Edge> adj[101];
        vector<int> out;
        fill(in_d, in_d+n, 0);
        fill(vis, vis+n, false);
        for(int i = 0; i < m; i++){
            int x, y;
            cin>>x>>y;
            adj[y].push_back(Edge(x));
            in_d[x]++;
        }
        while(1) {
            int index = -1;
            for (int i = 0; i < n; i++) {
                if (!vis[i] && in_d[i] == 0) {
                    index = i;
                    break;
                }
            }
            if (index == -1 && out.size() != n){
                cout << "NO" << endl;
                break;
            }
            else {
                out.push_back(index);
                if (out.size() == n){
                    cout << "YES" << endl;
                    break;
                }
                vis[index] = true;
                int bound = adj[index].size();
                for (int i = 0; i < bound; i++) {
                    in_d[adj[index][i].d]--;
                }
            }
        }
    }
    return 0;
}