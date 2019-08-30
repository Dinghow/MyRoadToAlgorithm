#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n;
    priority_queue<int, vector<int>, greater<int> > min_h;
    while(cin>>n){
        for(int i = 0; i < n; i++){
            int tmp;
            cin>>tmp;
            min_h.push(tmp);
        }
        int sum = 0;
        while(min_h.size()>1){
            int a, b;
            a = min_h.top();
            min_h.pop();
            b = min_h.top();
            min_h.pop();
            sum += a+b;
            min_h.push(a+b);
        }
        cout<<sum<<endl;
    }
    return 0;
}