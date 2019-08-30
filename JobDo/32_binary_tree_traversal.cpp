#include<iostream>
#include<map>
#include<stdio.h>
#include<cstring>

using namespace std;

struct Node{
    char val;
    Node* l, *r;
    Node(char v){
        val = v;
        l = NULL;
        r = NULL;
    }
};

void postOrd(Node* node){
    if(!node) return;
    if(node->l) postOrd(node->l);
    if(node->r) postOrd(node->r);
    cout<<node->val;
}

Node* constrTree(char *p, char* i, int l){
    if(!l) return NULL;
    Node *node = new Node(p[0]);
    int l_len;

    for(int j = 0; j < l; j++){
        if(i[j] == p[0]){
            l_len = j;
            break;
        }
    }
    node->l = constrTree(p+1, i, l_len);
    node->r = constrTree(p+l_len+1, i+l_len+1, l-l_len-1);
    return node;
}

int main(){
    char p_ord[27], m_ord[27];
    while(gets(p_ord)){
        gets(m_ord);
        int len = strlen(p_ord);
        Node* root = constrTree(p_ord, m_ord, len);
        postOrd(root);
        cout<<endl;
    }

    return 0;
}