#include<iostream>
#include<vector>
#define MAX 10000000

using namespace std;

struct Edge{
    int des;
    int dis;
    int cos;
    Edge(int a, int d, int c):des(a),dis(d),cos(c){}
};

bool vis[1001] = {0};
int dis[1001];
int cost[1001];

int main(){
    int n, m, s, t;
    while(cin>>n>>m){
        vector<Edge> adj[1001];
        fill(vis+1,vis+n+1,false);
        fill(dis+1, dis+n+1, MAX);
        fill(cost+1, cost+n+1, MAX);
        if(!n && !m) break;
        for(int i = 0; i < m; i++){
            int a, b, d, p;
            cin>>a>>b>>d>>p;
            adj[a].push_back(Edge(b,d,p));
            adj[b].push_back(Edge(a,d,p));
        }
        cin>>s>>t;
        dis[s] = 0;
        cost[s] = 0;
        while(1) {
            int u = -1;
            int min = MAX;
            for (int i = 1; i <= n; i++) {
                if (dis[i] <= min && !vis[i]) {
                    min = dis[i];
                    u = i;
                }
            }
            if(u == -1) break;
            vis[u] = true;
            int bound = adj[u].size();
            for(int i = 0; i < bound; i++){
                int des = adj[u][i].des;
                if(!vis[des] && dis[u]+adj[u][i].dis < dis[des]){
                    dis[des] = dis[u]+adj[u][i].dis;
                    cost[des] = cost[u]+adj[u][i].cos;
                }
                else if(dis[u]+adj[u][i].dis == dis[des] && cost[u]+adj[u][i].cos < cost[des]){
                    cost[des] = cost[u]+adj[u][i].cos;
                }
            }
        }
        cout<<dis[t]<<" "<<cost[t]<<endl;
    }

    return 0;
}