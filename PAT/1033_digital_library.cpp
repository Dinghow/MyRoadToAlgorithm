#include<iostream>
#include<map>
#include<set>
#include<string>

using namespace std;

map<string, set<int>> libr[5];

int main(){
    int N,M;
    cin>>N;

    for(int i = 0; i < N; i++){
        int id;
        string tmp;
        cin>>id;
        getchar();
        for(int j = 0; j < 5; j++){
            if(j!= 2) {
                getline(cin, tmp);
                libr[j][tmp].insert(id);
//                cout<<"k: "<<j<<" tmp: "<<tmp;
//                cout<<" size: "<<libr[j][tmp].size()<<endl;
            }
            else{
                while(cin>>tmp){
                    libr[j][tmp].insert(id);
                    char c = getchar();
                    if(c == '\n') break;
                }
            }
        }
    }
    cin>>M;
    for(int i = 0; i < M; i++){
        int k;
        string s_key;
        scanf("%d: ",&k);
        getline(cin, s_key);
        cout<<k<<": "<<s_key<<endl;
        set<int> res = libr[k-1][s_key];
        //cout<<"lib: "<<libr[k-1][s_key].size()<<" res:"<<res.size();
        if(!res.size()) cout<<"Not Found"<<endl;
        else{
            for(set<int>::iterator it = res.begin(); it != res.end();it++){
                printf("%07d\n",*it);
            }
        }
    }

    return 0;
}