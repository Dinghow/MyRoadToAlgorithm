#include<iostream>
#include<algorithm>

using namespace std;

int mis[25];
int F[25];

int main(){
    int k;
    while(cin>>k){
        for(int i = 0; i < k; i++){
            cin>>mis[i];
        }
        F[0] = 1;
        for(int i = 1; i < k; i++){
            int m_len = 1;
            for(int j = i-1; j >= 0; j--){
                if(mis[i] <= mis[j] && F[j]+1 >= m_len){
                    m_len = F[j]+1;
                }
            }
            F[i] = m_len;
        }
        cout<<*max_element(F,F+k)<<endl;
    }
    return 0;
}