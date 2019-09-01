#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Tree[101];

struct Edge{
    int a;
    int b;
    int d;
    Edge(int x, int y, int dis):a(x),b(y),d(dis){}
};

bool cmp(Edge x, Edge y){
    return x.d < y.d;
}

int findRoot(int x){
    if(Tree[x] == -1) return x;
    else{
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

int main(){
    int n;
    while(cin>>n){
        int a,b,d,len=0;
        fill(Tree, Tree+n, -1);
        vector<Edge> edg;
        int bound = n*(n-1)/2;
        for(int i = 0; i < bound; i++){
            cin>>a>>b>>d;
            Edge* tmp = new Edge(a,b,d);
            edg.push_back(*tmp);
        }
        sort(edg.begin(),edg.end(),cmp);
        for(int i = 0; i < bound; i++){
            Edge it = edg[i];
            a = findRoot(it.a);
            b = findRoot(it.b);
            if(a != b){
                Tree[a] = b;
                len += it.d;
            }
        }
        cout<<len<<endl;
    }
    return 0;
}