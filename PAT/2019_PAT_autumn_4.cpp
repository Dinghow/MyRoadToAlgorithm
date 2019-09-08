#include<iostream>
#include<vector>
#define MAX 0x7fffffff

using namespace std;

struct Edge{
	int d;
	int v;
	Edge(int des, int val):d(des),v(val){}
};

vector<Edge> adj[1001];
bool vis[1001];
int d[1001];
int n, m;

bool Dijkstra(vector<int> &seq){
	fill(vis+1,vis+1+n,false);
	fill(d+1,d+n+1,MAX);
	int index = 0;
	d[seq[0]] = 0;

	while(1){
		int u = -1; 
		if(index > n-1) break;
		int seq_v = seq[index];
		index++;
		int min = MAX;
		for(int i = 1; i <= n; i++){
			if(!vis[i] && d[i] < min){
				min = d[i];
				u = i;
			}
		}
		if(u != seq_v){
			if(d[u] == d[seq_v]){
				u = seq_v;
			}
			else{
				return false;
			}
		}
		if(u == -1) break;
		vis[u] = true;
		int bound = adj[u].size();
		for(int i = 0; i < bound; i++){
			int des = adj[u][i].d;
			if(!vis[des] && d[des] > d[u]+adj[u][i].v){
				d[des] = d[u]+adj[u][i].v;
			}
		}
	}
	return true;
}

int main(){
	cin>>n>>m;
	int a, b, v;
	for(int i = 0; i < m; i++){
		cin>>a>>b>>v;
		adj[a].push_back(Edge(b,v));
		adj[b].push_back(Edge(a,v));
	}
	int K;
	cin>>K;
	vector<int> k[1001];
	int tmp;
	for(int i = 0; i < K; i++){
		for(int j = 0; j < n; j++){
			cin>>tmp;
			k[i].push_back(tmp);
		}
	}

	for(int i = 0; i < K; i++){
		bool flag = Dijkstra(k[i]);
		cout<<(flag?"Yes":"No")<<endl;
	}

	return 0;
}