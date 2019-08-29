#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Node{
    int id;
    int max_d;
};
vector<int> adj[10001];
bool vis[10001]={0};
bool cyclic = false;

using namespace std;

bool descend(Node x, Node y){
    if(x.max_d!=y.max_d) return x.max_d>y.max_d;
    else return x.id < y.id;
}

void DFS_cyc(int node){
    vis[node] = true;
    for(int i = 0; i < adj[node].size(); i++){
        if(!vis[adj[node][i]])
            DFS_cyc(adj[node][i]);
    }
}

int DFS_tree(int node, int max_d, int d){
    vis[node] = true;
    if(d > max_d) max_d = d;
    if(!adj[node].size()) return max_d;
    else{
        d++;
        for(int i = 0; i < adj[node].size(); i++){
            if(!vis[adj[node][i]])
                max_d = DFS_tree(adj[node][i], max_d, d);
        }
    }
    return max_d;
}

int main(){
    int N;
    cin>>N;
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= N; i++){
        if(!adj[i].size()){
            cyclic = true;
            break;
        }
    }

    if(cyclic){
        int counter = 0;
        fill(vis,vis+N+1,0);
        for(int i = 1; i <= N; i++){
            if(!vis[i]) {
                DFS_cyc(i);
                counter++;
            }
        }

        cout<<"Error: "<<counter<<" components";
    }
    else{
        vector<Node> deepest;
        for(int i = 1; i <= N; i++){
            if(adj[i].size() == 1) {
                fill(vis,vis+N+1,0);
                int max_d = DFS_tree(i,0, 0);
                Node tmp;
                tmp.id = i, tmp.max_d = max_d;
                deepest.push_back(tmp);
            }
        }
        sort(deepest.begin(), deepest.end(), descend);
        int max_deep = deepest[0].max_d;
        for (int i = 0; i < deepest.size(); i++) {
            if (deepest[i].max_d < max_deep) break;
            cout << deepest[i].id << endl;
        }

    }

    return 0;
}