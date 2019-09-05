#include<iostream>
#include<map>
#include<string>

using namespace std;

int in_d[1000] = {0};
map<string, int> num;

int main(){
    string a, b;
    int n, counter;
    int c, d;
    while(cin>>n){
        if(!n) break;
        fill(in_d,in_d+1000,0);
        num.clear();
        counter = 0;
        for(int i = 0; i < n; i++){
            cin>>a>>b;
            if(num.find(a) == num.end()){
                num[a] = counter;
                counter++;
            }
            c = num.find(a)->second;
            if(num.find(b) == num.end()){
                num[b] = counter;
                counter++;
            }
            d = num.find(b)->second;
            in_d[d]++;
        }
        int zero = 0;
        for(int i = 0; i < counter; i++){
            if(in_d[i] == 0) zero++;
        }
        cout<<(zero==1?"Yes":"No")<<endl;
    }
    return 0;
}