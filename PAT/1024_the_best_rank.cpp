#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

struct Stu{
    string id;
    int A,C,M,E;
}stu[2000];

int TA[2000],TC[2000],TM[2000],TE[2000];
string que[2000];

bool descend(int a, int b){
    return a > b;
}

int findStu(string s, int N){
    for(int i = 0; i < N; i++){
        if(stu[i].id == s) return i;
    }
    return -1;
}

int findRank(int v, int *T,int N){
    for(int i = 0; i < N; i++){
        if(T[i] == v) return i;
    }
    return -1;
}

int main(){
    int N,M;
    int r_A, r_C, r_M, r_E;
    cin>>N>>M;
    for(int i = 0; i < N; i++){
        cin>>stu[i].id>>stu[i].C>>stu[i].M>>stu[i].E;
        stu[i].A = (stu[i].C+stu[i].M+stu[i].E)/3;
        TA[i] = stu[i].A, TC[i] = stu[i].C, TM[i] = stu[i].M, TE[i] = stu[i].E;
    }
    for(int i = 0; i < M; i++){
        cin>>que[i];
    }

    sort(TA,TA+N,descend);
    sort(TC,TC+N,descend);
    sort(TM,TM+N,descend);
    sort(TE,TE+N,descend);
    for(int i = 0; i < M; i++){
        int index = findStu(que[i],N);
        if(index < 0) cout<<"N/A"<<endl;
        else{
            r_A = findRank(stu[index].A, TA, N);
            r_C = findRank(stu[index].C, TC, N);
            r_M = findRank(stu[index].M, TM, N);
            r_E = findRank(stu[index].E, TE, N);
            if(r_A <= r_C && r_A <= r_M && r_A <= r_E) cout<<r_A+1<<" "<<"A"<<endl;
            else if(r_C <= r_A && r_C <= r_M && r_C <= r_E) cout<<r_C+1<<" "<<"C"<<endl;
            else if(r_M <= r_A && r_M <= r_C && r_M <= r_E) cout<<r_M+1<<" "<<"M"<<endl;
            else cout<<r_E+1<<" "<<"E"<<endl;
        }
    }

    return 0;
}