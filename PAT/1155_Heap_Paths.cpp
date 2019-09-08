#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int is_max=1;
int is_min=1;

struct Node{
    int val;
    Node* l, *r;
    Node(int v){
        val = v;
        l = NULL;
        r = NULL;
    }    
};  

void pathJudge(stack<int> s){
    vector<int> p;
    while(!s.empty()){
        p.push_back(s.top());
        s.pop();
    }
    for(int i = p.size()-1; i >= 0; i--){
        cout<<p[i];
        if(i>=1){
            is_max*=(p[i]>=p[i-1]);
            is_min*=(p[i]<=p[i-1]);
        }    
        if(i!=0) cout<<" ";
    }
    cout<<endl;        
}    

void DFS(Node* n, stack<int> &s){
    s.push(n->val);
    if(!n->l && !n->r) pathJudge(s);
    if(n->r) DFS(n->r, s);
    if(n->l) DFS(n->l, s);
    s.pop();
}   

int arr[1000];
Node* tree[1000];

int main(){
    int N;
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>arr[i];
        tree[i] = new Node(arr[i]);
    }
    
    for(int i = 0; i < N; i++){
        if(2*i+1<N) tree[i]->l = tree[2*i+1];
        if(2*i+2<N) tree[i]->r = tree[2*i+2];
    }    
    
    stack<int> s;
    DFS(tree[0], s);
    if(is_max) cout<<"Max Heap";
    else if(is_min) cout<<"Min Heap";
    else cout<<"Not Heap";
    
    return 0;    
}
    