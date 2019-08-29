#include<iostream>
#include<algorithm>

using namespace std;

struct Stu{
    string id;
    int gra;
    int loc;
    int l_rank;
    int t_rank;
}stu[30000];

bool cmp(Stu x, Stu y){
    if(x.gra!=y.gra) return x.gra>y.gra;
    else return x.id<y.id;
}

void setRank(Stu* sta, int len, bool loc){
    int cur_gra = sta[0].gra;
    int rank = 1, counter = 0;
    for(int i = 0; i < len; i++){
        if(sta[i].gra < cur_gra){
            cur_gra = sta[i].gra;
            rank+=counter;
            counter = 0;
        }
        if(loc){
            sta[i].l_rank = rank;
        }
        else{
            sta[i].t_rank = rank;
        }
        counter++;
    }
}

int main(){
    int N, sta=0;
    int M[100];
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>M[i];
        for(int j = 0; j < M[i]; j++){
            cin>>stu[sta+j].id>>stu[sta+j].gra;
            stu[sta+j].loc = i+1;
        }
        sta+=M[i];
    }

    sta = 0;
    for(int i = 0; i < N; i++){
        sort(stu+sta,stu+sta+M[i],cmp);
        setRank(stu+sta, M[i], true);
        sta += M[i];
    }

    sort(stu, stu+sta, cmp);
    setRank(stu, sta, false);

    cout<<sta<<endl;
    for(int i = 0; i < sta; i++){
        cout<<stu[i].id<<" "<<stu[i].t_rank<<" "<<stu[i].loc<<" "<<stu[i].l_rank<<endl;
    }

    return 0;
}