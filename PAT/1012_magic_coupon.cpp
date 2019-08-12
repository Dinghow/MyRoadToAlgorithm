#include<iostream>
#include<algorithm>

using namespace std;

bool descend(int x, int y){
    return x > y;
}

int main(){
    int C_P[100000], C_N[100000], P_P[100000], P_N[100000];
    int NC,NP,p = 0,q = 0, m = 0, n = 0, temp;

    cin>>NC;
    for(int i = 0; i < NC; i++){
        cin>>temp;
        if(temp >= 0){
            C_P[p] = temp;
            p++;
        }
        else{
            C_N[q] = temp;
            q++;
        }
    }
    cin>>NP;
    for(int i = 0; i < NP; i++){
        cin>>temp;
        if(temp >= 0){
            P_P[m] = temp;
            m++;
        }
        else{
            P_N[n] = temp;
            n++;
        }
    }

    sort(C_P,C_P+p,descend);
    sort(C_N,C_N+q);
    sort(P_P,P_P+m,descend);
    sort(P_N,P_N+n);

    int a = p < m ? p:m;
    int b = q < n? q:n;
    long int sum = 0;

    for(int i = 0; i < a; i++) sum+=C_P[i]*P_P[i];
    for(int i = 0; i < b; i++) sum+=C_N[i]*P_N[i];

    cout<<sum<<endl;
    return 0;
}