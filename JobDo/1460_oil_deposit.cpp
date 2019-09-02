#include<iostream>

using namespace std;

char grd[100][100];
bool mark[100][100];

int m, n;

int dir[][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

bool DFS(int x, int y){
    if(mark[x][y]) return false;
    mark[x][y] = true;
    if(grd[x][y] == '@') {
        for (int i = 0; i < 8; i++) {
            int n_x, n_y;
            n_x = x + dir[i][0], n_y = y + dir[i][1];
            if (n_x >= 0 && n_x < m && n_y >= 0 && n_y < n) {
                DFS(n_x, n_y);
            }
        }
        return true;
    }
    return false;
}

int main(){
    while(cin>>m>>n){
        if(!m && !n) break;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++){
              cin>>grd[i][j];
              mark[i][j] = false;
        }
        int counter = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grd[i][j] == '@' && !mark[i][j]) {
                    if (DFS(i, j))
                        counter++;
                }
            }
        }
        cout<<counter<<endl;
    }
    return 0;
}