#include<iostream>
#include<algorithm>

using namespace std;

struct Prog{
    int sta;
    int end;
}prog[100];

bool cmp(Prog x, Prog y){
    return x.end < y.end;
}

int main(){
    int n;
    while(cin>>n){
        if(!n) break;
        int counter = 0, index = 0, end;
        for(int i = 0; i < n; i++){
            cin>>prog[i].sta>>prog[i].end;
        }
        sort(prog,prog+n,cmp);
        end = prog[0].end;
        counter++;
        for(int i = 0; i < n; i++){
            if(prog[i].sta>=end){
                end = prog[i].end;
                counter++;
            }
        }
        cout<<counter<<endl;
    }

    return 0;
}