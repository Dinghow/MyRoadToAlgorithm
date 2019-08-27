#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

struct Node{
    int name;
    vector<int> chi;
}nodes[100];

queue<int> que;
queue<int> no_child;
map<int, int> pos;

int main(){
    int N, M, K, index=1;;
    cin>>N>>M;

    pos[1] = 0;
    nodes[0].name = 1;

    for(int i = 0; i < M; i++){
        int temp_name;
        cin>>temp_name>>K;
        int p = pos[temp_name];
        for(int j = 0; j < K; j++){
            cin>>temp_name;
            pos[temp_name] = index;
            nodes[index].name = temp_name;
            nodes[p].chi.push_back(temp_name);
            index++;
        }
    }

    que.push(1);
    int cur_num = 1, next_num = 0, counter = 0;
    while(!que.empty()){
        for(int k = 0; k < cur_num; k++){
            int name = que.front();
            que.pop();
            int p = pos[name];
            if(nodes[p].chi.size()!=0){
                for(int i = 0; i < nodes[p].chi.size(); i++){
                    que.push(nodes[p].chi[i]);
                    next_num++;
                }
            }
            else counter++;
        }
        no_child.push(counter);
        cur_num = next_num;
        next_num = 0;
        counter = 0;
    }

    while(!no_child.empty()){
        cout<<no_child.front();
        no_child.pop();
        if(no_child.size()!=0)
            cout<<" ";
    }

    return 0;
}