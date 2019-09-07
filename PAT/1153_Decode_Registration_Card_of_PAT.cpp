#include<iostream>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

struct Stu{
    string car;
    char lev;
    char site[4];
    char date[7];
    char num[4];
    int gra;
}stu[10000];

struct Query{
    int type;
    string q;
}query[100];

struct Site{
    string site;
    int Nt;
}sites[10000];

bool cmp1(Stu &a, Stu& b){
    if(a.gra!=b.gra) return a.gra > b.gra;
    else return a.car < b.car;
}

bool cmp2(Site &a, Site &b){
    if(a.Nt != b.Nt) return a.Nt > b.Nt;
    else return a.site < b.site;
}

int main(){
    int N, M, score;
    string tmp;
    cin>>N>>M;
    for(int i = 0; i < N; i++) {
        cin >> tmp >> score;
        stu[i].car = tmp;
        stu[i].lev = tmp[0];
        for(int j = 0; j < 3; j++) stu[i].site[j] = tmp[1+j];
        stu[i].site[3] = '\0';
        for(int j = 0; j < 6; j++) stu[i].date[j] = tmp[4+j];
        stu[i].date[6] = '\0';
        for(int j = 0; j < 3; j++) stu[i].num[j] = tmp[10+j];
        stu[i].num[3] = '\0';
        stu[i].gra = score;
    }

    for(int i = 0; i < M; i++){
        cin>>query[i].type>>query[i].q;
    }

    for(int i = 0; i < M; i++){
        cout<<"Case "<<i+1<<": "<<query[i].type<<" "<<query[i].q<<endl;
        if(query[i].type == 1){
            sort(stu,stu+N,cmp1);
            bool flag = true;
            for(int j = 0; j < N; j++){
                if(stu[j].lev == query[i].q[0]){
                    cout<<stu[j].car<<" "<<stu[j].gra<<endl;
                    flag = false;
                }
            }
            if(flag) cout<<"NA"<<endl;
        }
        else if(query[i].type == 2){
            int nt = 0, ns = 0;
            for(int j = 0; j < N; j++){
                if(stu[j].site == query[i].q){
                    nt++;
                    ns += stu[j].gra;
                }
            }
            if(nt){
                cout<<nt<<" "<<ns<<endl;
            }
            else cout<<"NA"<<endl;
        }
        else if(query[i].type == 3){
            map<string, int> sit_sum;
            int k = 0;
            bool flag = false;
            for(int j = 0; j < N; j++) {
                string c_site = stu[j].site;
                if (stu[j].date == query[i].q) {
                    flag = true;
                    if (sit_sum.find(c_site) == sit_sum.end()) {
                        sit_sum[c_site] = k;
                        sites[k].site = c_site;
                        sites[k].Nt = 0;
                        k++;
                    }
                    int a = sit_sum.find(c_site)->second;
                    sites[a].Nt++;
                }
            }
            if(!flag) cout<<"NA"<<endl;
            else {
                sort(sites,sites+k,cmp2);
                for (int l = 0; l < k; l++) {
                    cout<<sites[l].site<<" "<<sites[l].Nt<<endl;
                }
            }
        }
    }

    return 0;
}