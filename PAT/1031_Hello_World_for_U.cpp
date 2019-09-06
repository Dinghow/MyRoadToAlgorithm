#include<iostream>
#include<string>

using namespace std;

char U[80][80];

int main(){
    string str;
    int N, n1, n2, n3;
    while(cin>>str){
        N = str.size();
        n1 = n3 = (N+2)/3;
        n2 = N - 2*n1 + 2;
        for(int i = 0; i < 80; i++)
            for(int j = 0; j < 80; j++)
                U[i][j] = ' ';
        int k = 0;
        for(int i = 0; i < n1; i++){
            U[i][0] = str[k];
            k++;
        }
        for(int i = 1; i < n2-1; i++){
            U[n1-1][i] = str[k];
            k++;
        }
        for(int i = n3-1; i >= 0; i--){
            U[i][n2-1] = str[k];
            k++;
        }
        for(int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                cout << U[i][j];
            }
            cout<<endl;
        }
    }

    return 0;
}