#include<iostream>
#include<algorithm>
#define SIZE 10000000

using namespace std;

int Tree[SIZE];
int g_size[SIZE];

int findRoot(int a){
    if(Tree[a] == -1) return a;
    else{
        int tmp = findRoot(Tree[a]);
        Tree[a] = tmp;
        return tmp;
    }
}

int main(){
    int n;
    while(cin>>n){
        fill(Tree, Tree+n, -1);
        fill(g_size, g_size+n, 1);
        for(int i = 0; i < n; i++){
            int a, b;
            cin>>a>>b;
            a = findRoot(a);
            b = findRoot(b);
            if(a != b){
                Tree[b] = a;
                g_size[a] += g_size[b];
            }
        }
        cout<<*max_element(g_size, g_size+n)<<endl;
    }

    return 0;
}