#include<iostream>
#include<cmath>

using namespace std;
int n, m, T;
int s_x, s_y, d_x, d_y;
char maze[7][7];
bool is_find = false;

int dir[][2]={{1,0},{-1,0},{0,1},{0,-1}};

void DFS(int x, int y, int t){
    if(maze[x][y] == 'D'){
        if(t == T)
            is_find = true;
        return;
    }
    if(is_find) return;
    if(t >= T) return;
    maze[x][y] = 'X';
    for(int i = 0; i < 4; i++){
        int n_x = x+dir[i][0], n_y = y+dir[i][1];
        if(n_x>=0 && n_x<n && n_y >= 0 && n_y < m && maze[n_x][n_y] != 'X'){
            DFS(n_x,n_y,t+1);
        }
    }
    maze[x][y] = '.';
}

int main(){
    while(cin>>n>>m>>T){
        if(!n && !m && !T) break;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>maze[i][j];
                if(maze[i][j] == 'S'){
                    s_x = i;
                    s_y = j;
                }
                else if(maze[i][j] == 'D'){
                    d_x = i;
                    d_y = j;
                }
            }
        }
        is_find = false;
        int d = abs(d_y-s_y) + abs(d_x-s_x);
        if((d+T)%2 == 0){
            DFS(s_x, s_y, 0);
        }
        if(is_find){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}