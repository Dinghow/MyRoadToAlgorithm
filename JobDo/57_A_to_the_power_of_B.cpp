#include<iostream>

using namespace std;

int main(){
    int a, b;
    while(cin>>a>>b){
        if(!a && !b) break;
        int ans = 1;
        while(b>0) {
            a %= 1000;
            if(b & 1){
                ans *= a;
                ans %= 1000;
            }
            a *= a;
            b = b >> 1;
        }
        cout<<ans%1000<<endl;
    }

    return 0;
}