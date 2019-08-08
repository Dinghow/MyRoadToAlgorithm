#include<iostream>
#include<stack>
#include<map>
#include<vector>

using namespace std;
map<int, int> m_pos;
map<int, int> val;

struct Node{
    int value;
    Node* left;
    Node* right;

    Node(int v){
        value = v;
        left = NULL;
        right = NULL;
    }
};

Node* consTree(int* pre, int offset, int n){
    if(n==0) return NULL;
    Node* node = new Node(pre[0]);
    int left_len = m_pos[pre[0]] - offset;

    node->left = consTree(pre+1, offset, left_len);
    node->right = consTree(pre+1+left_len, offset+left_len+1, n-left_len-1);

    return node;
}

void postOrder(Node* node, vector<int>& pos){
    if(!node) return;
    postOrder(node->left, pos);
    postOrder(node->right, pos);
    pos.push_back(node->value);
}

int main(){
    stack<int> s;
    int N;
    int p_ord[50], m_ord[50];
    vector<int> pos_ord;
    int p = 0, q = 0;
    int index = 1;

    cin>>N;
    for(int i = 0;i<2*N;i++){
        string op;
        int node;
        cin >> op;
        if(!op.compare("Push")){
            cin>>node;
            val[index] = node;
            s.push(index);
            p_ord[p++] = index;
            index++;
        }
        else{
            m_ord[q++] = s.top();
            s.pop();
        }
    }

    for(int i = 0; i < N; i++){
        m_pos[m_ord[i]] = i;
    }

    Node* root = consTree(p_ord, 0, N);
    postOrder(root, pos_ord);
    for(int i = 0; i<N;i++){
        cout<<val[pos_ord[i]];
        if(i!=N-1) cout<<" ";
    }

    return 0;
}