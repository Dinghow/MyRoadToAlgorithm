#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

struct Pol{
    int exp;
    double coe;
};

double pol1[1001]={0};
double pol2[1001]={0};
double ans[2002]={0};

vector<Pol> res;

int main(){
    int N,M,index;
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>index>>pol1[index];
    }
    cin>>M;
    for(int i = 0; i < M; i++){
        cin>>index>>pol2[index];
    }

    for(int i = 0; i < 1001; i++){
        for(int j = 0; j < 1001; j++){
            if(pol1[i] && pol2[j]){
                index = i+j;
                ans[index]+= pol1[i]*pol2[j];
            }
        }
    }

    for(int i = 2002; i >= 0; i--){
        if(ans[i]!=0){
            Pol temp;
            temp.exp = i;
            temp.coe = ans[i];
            res.push_back(temp);
        }
    }
    cout<<res.size()<<" ";
    for(int i = 0; i < res.size(); i++){
        printf("%d %.1f",res[i].exp,res[i].coe);
        if(i!=res.size()-1) printf(" ");
    }

    return 0;
}