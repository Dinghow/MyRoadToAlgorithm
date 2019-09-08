#include<iostream>
#include<string>
#include<map>

using namespace std;

struct Node{
	string s, d;
	int next, pre;
	int v;
}nodes[10001];

map<string, int> pos;

int main(){
	string s1, s2;
	int N;
	cin>>s1>>s2>>N;

	for(int i = 0; i < N; i++){
		cin>>nodes[i].s>>nodes[i].v>>nodes[i].d;
		pos[nodes[i].s] = i;
		nodes[i].next = -1, nodes[i].pre = -1;
	}

	int p = pos[s1];
	int end1;
	int l1 = 0, l2 = 0;
	for(int i = 0; i < N; i++){
		string next = nodes[p].d;
		if(next == "-1"){
			end1 = p;
			break;
		}
		else{
		    int q = pos[next];
			nodes[p].next = q;
			nodes[q].pre = p;
			p = q;
			l1++;
		}
	}
	l1++;
	p = pos[s2];
	for(int i = 0; i < N; i++){
		string next = nodes[p].d;
		if(next == "-1"){
			break;
		}
		else{
		    int q = pos[next];
			nodes[p].next = q;
			nodes[q].pre = p;
			p = q;
			l2++;
		}
	}
	l2++;
	p = pos[s2];
	int counter = 0;
	int j = end1;
	bool flag = false;
	for(int i = 0; i < N; i++){
		if(l1 == 0) break;
		if(counter == 2 && l1 > 0){
			if(!flag){
				nodes[j].next = p;
				nodes[j].d = nodes[p].s;
				p = nodes[p].pre;
				nodes[p].next = j;
				nodes[p].d = nodes[j].s;
				p = nodes[j].next;
				j = nodes[j].pre;
			}
			else{
				nodes[j].next = -1;
				nodes[j].d = "-1";
				nodes[p].next = j;
				nodes[p].d = nodes[j].s;
				break;
			}
			counter = 0;
			l1--;
		}
		else{
			if(nodes[p].next!=-1)
				p = nodes[p].next;
			else{
				flag = true;
			}
			counter++;
		}
	}

	p = pos[s2];
	for(int i = 0; i < N; i++){
		cout<<nodes[p].s<<" "<<nodes[p].v<<" "<<nodes[p].d<<endl;
		p = nodes[p].next;
	}

	return 0;
}

