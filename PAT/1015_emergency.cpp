#include<iostream>
#include<vector>
#include<map>
#define MAX 100000000

using namespace std;

struct Edge{
    int des;
    int dis;
};

int N, M, C1, C2;
map<int, int> pre;
int teams[500];
bool vis[500];
int ways[500] = {0};
int d[500], t[500];
vector<vector<Edge> > adj(500);

int main(){
    Edge temp;
    int sta, des, team;

    cin>>N>>M>>C1>>C2;
    for(int i = 0; i < N; i++){
        cin>>team;
        teams[i] = team;
        t[i] = team;
    }
    for(int i = 0; i < M; i++){
        cin>>sta>>des>>temp.dis;
        temp.des = des;
        adj[sta].push_back(temp);
        temp.des = sta;
        adj[des].push_back(temp);
    }

    fill(vis,vis+N,false);
    fill(d,d+N,MAX);
    d[C1] = 0;

    for(int i = 0; i < N; i++){
        int u = -1;
        int min = MAX;
        for(int j = 0; j < N; j++){
            if(!vis[j] && d[j] < min){
                min = d[j];
                u = j;
            }
        }
        if(u == -1) break;
        vis[u] = true;
        for(int j = 0; j < adj[u].size(); j++){
            int de = adj[u][j].des;
            if(!vis[de] && d[de] > d[u]+adj[u][j].dis){
                d[de] = d[u]+adj[u][j].dis;
                ways[de] = 1;
                t[de] = t[u]+teams[de];
                pre[de] = u;
            }
            else if(d[de] == d[u]+adj[u][j].dis){
                ways[de]+= ways[u];
                if(t[de] < t[u]+teams[de]){
                    t[de] = t[u]+teams[de];
                    pre[de] = u;
                }
            }
        }
    }

    cout<<ways[C2]<<" "<<t[C2];
//
//    cout<<endl<<"dis: "<<d[C2];
//    cout<<endl<<C2<<" ";
//    int index = C2;
//    while(pre[index]!=C1){
//        cout<<pre[index]<<" ";
//        index = pre[index];
//    }
//    cout<<C1;

    return 0;
}