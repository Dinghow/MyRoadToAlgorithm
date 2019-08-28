#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<algorithm>

using namespace std;

struct Customer{
    int id;
    int time;
    int win;
    int sta_time;
    int flag;
}cus[1000];

struct Window{
    int id;
    int time;
    int pop_time;
    queue<int> que;
};

int q[1000];

bool cmp_total(Window x, Window y){
    if(x.que.size()!=y.que.size()) return x.que.size()<y.que.size();
    else return x.id<y.id;
}

bool cmp_top(Window x, Window y){
    int time1 = x.pop_time;
    int time2 = y.pop_time;
    if(time1 != time2) return time1<time2;
    else return x.que.front()<y.que.front();
}

int main(){
    int N, M, K, Q;
    vector<Window> T;
    cin>>N>>M>>K>>Q;

    for(int i = 0; i < K; i++){
        cus[i].id = i;
        cus[i].flag = 0;
        cin>>cus[i].time;
    }

    for(int i = 0; i < Q; i++) cin>>q[i];
    for(int i = 0; i < N; i++){
        Window temp;
        temp.id = i;
        temp.time = 0;
        temp.pop_time = 0;
        T.push_back(temp);
    }
    for(int i = 0; i < M*N; i++){
        vector<Window>::iterator it = min_element(T.begin(),T.end(),cmp_total);
        cus[i].win = it->id;
        cus[i].sta_time = it->time;
        it->time += cus[i].time;
        it->que.push(i);
        if(it->que.size()==1) it->pop_time = it->time;
    }
    for(int i = N*M; i < K; i++){
        vector<Window>::iterator it = min_element(T.begin(),T.end(),cmp_top);
        it->que.pop();
        it->pop_time = cus[it->que.front()].sta_time+cus[it->que.front()].time;
        cus[i].win = it->id;
        cus[i].sta_time = it->time;
        if(cus[i].sta_time >= 540)  cus[i].flag = 1;
        it->time += cus[i].time;
        it->que.push(i);
    }

    for(int i = 0; i < Q; i++){
        int id = q[i];
        int itv = cus[id-1].time+cus[id-1].sta_time;
        if(cus[id-1].flag) cout<<"Sorry";
        else{
            int h = 8 + itv/60;
            int m = itv%60;
            printf("%02d:%02d",h,m);
        }
        if(i!=Q-1) cout<<endl;
    }

    return 0;
}