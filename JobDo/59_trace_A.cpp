#include<iostream>

using namespace std;

int mat[10][10];
int tmp[10][10];
int ans[10][10];

void initTmp(){
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            tmp[i][j] = 0;
}

int main(){
    int T;
    while(cin>>T) {
        for (int a = 0; a < T; a++) {
            int n, k;
            cin >> n >> k;
            for (int p = 0; p < n; p++) {
                for (int q = 0; q < n; q++) {
                    cin >> mat[p][q];
                    if (p == q) ans[p][q] = 1;
                    else ans[p][q] = 0;
                }
            }
            while (k > 0) {
                if (k%2==1) {
                    initTmp();
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            for (int l = 0; l < n; l++) {
                                tmp[i][j] += ans[i][l] * mat[l][j];
                            }
                        }
                    }
                    for (int i = 0; i < n; i++)
                        for (int j = 0; j < n; j++)
                            ans[i][j] = tmp[i][j] % 9973;
                }
                initTmp();
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        for (int l = 0; l < n; l++) {
                            tmp[i][j] += mat[i][l] * mat[l][j];
                        }
                    }
                }
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        mat[i][j] = tmp[i][j] % 9973;
                k = k >> 1;
            }
            int trace = 0;
            for (int i = 0; i < n; i++)
                trace += ans[i][i];
            cout << trace%9973 << endl;
        }
    }

    return 0;
}