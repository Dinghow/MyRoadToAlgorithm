#include<iostream>
#include<vector>

struct Pol{
    int exp;
    float val;
};

using namespace std;

float pol1[1000]={0};
float pol2[1000]={0};

int main(){
    int K1,K2;
    int exp;
    vector<Pol> ans;
    cin>>K1;
    for(int i = 0; i < K1; i++) cin>>exp>>pol1[exp];
    cin>>K2;
    for(int i = 0; i < K2; i++) cin>>exp>>pol2[exp];

    for(int i = 0; i < 1000; i++){
        Pol temp;
        temp.exp = i;
        temp.val = pol1[i]+pol2[i];
        if(temp.val) ans.push_back(temp);
    }

    cout<<ans.size()<<" ";
    for(int i = ans.size()-1; i >= 0; i--){
        printf("%d %.1f",ans[i].exp,ans[i].val);
        if(i != 0) printf(" ");
    }

    return 0;
}