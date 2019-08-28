#include<iostream>
#include<map>
#include<queue>

using namespace std;

int p_ord[30];
int i_ord[30];

struct Node{
    int id;
    Node* left, * right;
    Node(int v){
        id = v;
        left = NULL;
        right = NULL;
    }
};

queue<Node*> que;

Node* constTree(int* p, int* i, int len){
    if(!len) return NULL;
    int id = p[len-1];
    Node* new_node = new Node(id);
    int pos;
    for(int j = 0; j < len; j++){
        if(i[j] == id){
            pos = j;
            break;
        }
    }
    int l_len = pos, r_len = len-1-l_len;

    new_node->left = constTree(p, i, l_len);
    new_node->right = constTree(p+l_len, i+l_len+1, r_len);

    return new_node;
}

int main(){
    int N;
    cin>>N;
    for(int i = 0; i < N; i++) cin>>p_ord[i];
    for(int i = 0; i < N; i++) cin>>i_ord[i];
    vector<int> lev;
    Node* root = constTree(p_ord, i_ord, N);

    int cur_num = 1, next_num = 0;
    que.push(root);

    while(cur_num) {
        if(que.front()->left){
            next_num++;
            que.push(que.front()->left);
        }
        if(que.front()->right){
            next_num++;
            que.push(que.front()->right);
        }
        lev.push_back(que.front()->id);
        que.pop();
        cur_num--;
        if(!cur_num){
            cur_num = next_num;
            next_num = 0;
        }
    }

    for(int i = 0; i < lev.size(); i++){
        cout<<lev[i];
        if(i != lev.size()-1) cout<<" ";
    }

    return 0;
}