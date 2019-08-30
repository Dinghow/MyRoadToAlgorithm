#include<iostream>
#include<map>

using namespace std;
map<int, int> gra;

int main(){
    int N,q;
    while(cin>>N){
        if(!N) break;
        for(int i = 0; i < N; i++){
            int temp;
            cin >> temp;
            gra[temp]++;
        }
        cin>>q;
        cout<<gra[q]<<endl;
    }
    return 0;
}