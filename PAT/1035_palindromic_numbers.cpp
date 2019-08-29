#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

vector<char> addRev(vector<char> n){
    vector<char> b, s;
    stack<char> sum;
    for(int i = 0; i < n.size(); i++) b.push_back(n[n.size()-1-i]);
    bool car = false;
    for(int i = n.size()-1; i >= 0; i--){
        int tmp = n[i]-'0'+b[i]-'0';
        if(car){
            tmp++;
            car = false;
        }
        if(tmp>=10){
            car = true;
            tmp = tmp%10;
        }
        sum.push(tmp+'0');
    }
    if(car) sum.push('1');
    while(!sum.empty()){
        s.push_back(sum.top());
        sum.pop();
    }
    return s;
}

bool isPalin(vector<char> n){
    bool flag = true;
    for(int i = 0; i < n.size()/2; i++){
        if(n[i] != n[n.size()-1-i]){
            flag = false;
            break;
        }
    }
    return flag;
}

int main(){
    vector<char> num;
    bool ispal;
    string n;
    int K, j = 0;
    cin>>n>>K;

    for(int i = 0; i < n.size(); i++) num.push_back(n[i]);
    for(j; j < K; j++){
        ispal = isPalin(num);
        if(ispal) break;
        else num = addRev(num);
    }

    for(auto i: num) cout<<i;
    cout<<endl<<j;

    return 0;
}