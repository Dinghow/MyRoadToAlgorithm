#include<iostream>
#include<algorithm>

using namespace std;

int GCD(int a, int b){
    return (b == 0)?a:GCD(b, a%b);
}

int main(){
    int a,b;
    while(cin>>a>>b){
        if(b>a){
            int tmp = a;
            a = b;
            b = tmp;
        };
        int gcd = GCD(a, b);
        cout<<a*b/gcd<<endl;
    }
    return 0;
}