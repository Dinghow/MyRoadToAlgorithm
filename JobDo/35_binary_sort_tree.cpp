#include<iostream>

using namespace std;

struct Node{
    int val;
    Node* l, *r;
    Node(int v){
        val = v;
        l = NULL;
        r = NULL;
    };
};

Node* root = NULL;

Node* insert(Node* node, int val){
    if(!node) {
        node = new Node(val);
    }
    else if(val > node->val) {
        node->r = insert(node->r, val);
    }
    else {
        node->l = insert(node->l, val);
    }
    return node;
}

int main(){
    int n;
    cin>>n;
    getchar();
    for(int i = 0; i < n; i++){
        int tmp;
        tmp=getchar();
        tmp -= '0';
        root = insert(root, tmp);
    }
    
    return 0;
}