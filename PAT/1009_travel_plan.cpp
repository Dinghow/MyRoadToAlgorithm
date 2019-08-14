#include<iostream>
#include<map>
#include<stack>
#include<vector>
#define MAX 1000000000

using namespace std;

map<int, int> pre;
stack<int> route;

struct Edge{
    int des;
    int dis;
    int cos;
};

void Dijkstra(int N, int S, vector<vector<Edge> >& adj, bool vis[], int d[], int c[]){
    fill(d,d+500,MAX);
    fill(c,c+500,MAX);
    d[S] = 0;
    c[S] = 0;
    for(int i = 0; i < N; i++){
        int u = -1;
        int min = MAX;
        for(int j = 0; j < N; j++){
            if(vis[j] == false && d[j]<=min){
                u = j;
                min = d[j];
            }
        }
        if(u == -1) return;
        //else if(min_counter) return Dijkstra_Cos(N, M, S, D, adj, vis, d, c);
        vis[u] = true;
        for(int j = 0; j < adj[u].size(); j++){
            int des = adj[u][j].des;
            if(!vis[des] && d[des] > d[u]+adj[u][j].dis){
                d[des] = d[u] + adj[u][j].dis;
                c[des] = c[u] + adj[u][j].cos;
                pre[des] = u;
            }
            else if(d[des] == d[u]+adj[u][j].dis && c[des] > c[u]+adj[u][j].cos){
                c[des] = c[u] + adj[u][j].cos;
                pre[des] = u;
            }
        }
    }
}


int main(){
    int N, M, S, D;
    bool vis[500]={false};
    int d[500];
    int c[500];
    vector<vector<Edge> > adj(500);
    cin>>N>>M>>S>>D;

    for(int i = 0; i < M; i++){
        Edge temp;
        int sta, des;
        cin>>sta>>des>>temp.dis>>temp.cos;
        temp.des = des;
        adj[sta].push_back(temp);
        temp.des = sta;
        adj[des].push_back(temp);
    }

    Dijkstra(N, S, adj, vis, d, c);

    int i = D;
    route.push(D);
    while(pre[i]!=S){
        route.push(pre[i]);
        i = pre[i];
    }
    route.push(S);

    while(!route.empty()){
        cout<<route.top()<<" ";
        route.pop();
    }
    cout<<d[D]<<" "<<c[D];

    return 0;
}