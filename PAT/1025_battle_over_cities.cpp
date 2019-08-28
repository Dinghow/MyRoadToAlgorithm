#include<iostream>

using namespace std;

int Tree[1000];
int key[1000];

struct Edge{
    int x, y;
}edges[1000000];

int findRoot(int x){
    if(Tree[x] == -1) return x;
    else{
        int temp = findRoot(Tree[x]);
        Tree[x] = temp;
        return temp;
    }
}

void combine(int a, int b){
    int r_a = findRoot(a);
    int r_b = findRoot(b);
    if(r_a != r_b) Tree[r_a] = r_b;
}

int main(){
    int N,M,K;
    cin>>N>>M>>K;
    for(int i = 0; i < M; i++){
        int a, b;
        cin>>a>>b;
        edges[i].x = a;
        edges[i].y = b;
    }
    for(int i = 0; i < K; i++){
        cin>>key[i];
    }
    for(int i = 0; i < K; i++){
        int k = key[i],counter=0;
        fill(Tree,Tree+N+1,-1);
        for(int j = 0; j < M; j++){
            if(edges[j].x != k && edges[j].y !=k){
                combine(edges[j].x, edges[j].y);
            }
        }
        for(int j = 1; j < N+1; j++)
            if(Tree[j]==-1) counter++;
        cout<<((counter-2)>0?counter-2:0)<<endl;
    }

    return 0;
}