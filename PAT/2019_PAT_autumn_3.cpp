#include<iostream>
#include<map>
#include<string>

using namespace std;

struct Node{
	string v;
	int l, r;
	Node *left, *right;
}nodes[21];

void postOrder(Node *n){
	if(n == NULL) return;
	cout<<"(";
	if(n->v != "-"){
		if(n->left != NULL) postOrder(n->left);
		if(n->right != NULL) postOrder(n->right);
		cout<<n->v;
		cout<<")";
	}
	else{
		cout<<n->v;
		if(n->left != NULL) postOrder(n->left);
		if(n->right != NULL) postOrder(n->right);
		cout<<")";
	}
}

bool mark[21] = {false};

int main(){
	int N;
	cin>>N;
	for(int i = 1; i <= N; i++){
		cin>>nodes[i].v>>nodes[i].l>>nodes[i].r;
		nodes[i].left = NULL;
		nodes[i].right = NULL;
	}

	for(int i = 0; i <= N; i++){
		if(nodes[i].l != -1){
			mark[nodes[i].l] = true;
			nodes[i].left = &nodes[nodes[i].l];
		}
		else nodes[i].left = NULL;
		if(nodes[i].r != -1){
			mark[nodes[i].r] = true;
			nodes[i].right = &nodes[nodes[i].r];
		}
		else nodes[i].right = NULL;
	}

	int root;
	for(int i = 1; i <= N; i++){
		if(mark[i] == false){
			root = i;
			break;
		}
	}

	postOrder(&nodes[root]);

	return 0;
}