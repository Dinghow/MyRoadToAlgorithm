#include<iostream>
#include<vector>
#include<stack>

using namespace std;

bool dig1[10] = {false};
bool dig2[10] = {false};
stack<char> a;
vector<char> b;
bool label = true;

void checkDig(){
    bool car = false;
    int len = a.size();
    for(int i = 0; i < len; i++) {
        int tmp = (a.top()-'0')*2;
        if(car){
            tmp++;
            car = false;
        }
        if(tmp >= 10){
            car = true;
            tmp = tmp%10;
        };
        dig2[tmp] = true;
        b.push_back(tmp+'0');
        a.pop();
    }
    if(car) b.push_back('1');
}

int main(){
    string s;
    cin>>s;
    for(int i = 0; i < s.size(); i++) {
        char tmp = s[i];
        dig1[tmp-'0'] = true;
        a.push(tmp);
    }
    checkDig();
    for(int i = 0; i < 10; i++){
        if(dig1[i] != dig2[i]){
            label = false;
            break;
        }
    }

    cout<<(label?"Yes":"No")<<endl;
    for(int i = b.size()-1; i >=0 ; i--){
        cout<<b[i];
    }

    return 0;
}