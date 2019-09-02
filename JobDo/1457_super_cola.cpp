#include<iostream>
#include<queue>

using namespace std;

struct Node{
    int x, y, z, c;
    Node(int s, int n, int m, int count):x(s),y(n),z(m),c(count){}
};

int s, n, m;
queue<Node> que;
bool mark[101][101][101];

void init(){
    for(int i = 0; i < 101; i++)
        for(int j = 0; j < 101; j++)
            for(int k = 0; k < 101; k++)
                mark[i][j][k] = false;
    if(!que.empty()) que.pop();
}

int BFS(Node p){
    //s to n
    if(p.x > 0 && p.y < n){
        int qua = n-p.y;
        if(qua > p.x) qua = p.x;
        int n_x = p.x-qua, n_y = p.y+qua, n_z = p.z, n_c = p.c+1;
        if(!mark[n_x][n_y][n_z]) {
            Node tmp(n_x, n_y, n_z, n_c);
            if((n_x == s/2 && n_y == s/2) || (n_x == s/2 && n_z == s/2) || (n_y == s/2 && n_z == s/2)) return n_c;
            que.push(tmp);
            mark[n_x][n_y][n_z] = true;
        }
    }
    // s to m
    if(p.x > 0 && p.z < m){
        int qua = m-p.z;
        if(qua > p.x) qua = p.x;
        int n_x = p.x-qua, n_y = p.y, n_z = p.z + qua, n_c = p.c+1;
        if(!mark[n_x][n_y][n_z]) {
            Node tmp(n_x, n_y, n_z, n_c);
            if((n_x == s/2 && n_y == s/2) || (n_x == s/2 && n_z == s/2) || (n_y == s/2 && n_z == s/2)) return n_c;
            que.push(tmp);
            mark[n_x][n_y][n_z] = true;
        }
    }
    // n to s
    if(p.x < s && p.y > 0){
        int qua = s-p.x;
        if(qua > p.y) qua = p.y;
        int n_x = p.x+qua, n_y = p.y-qua, n_z = p.z, n_c = p.c+1;
        if(!mark[n_x][n_y][n_z]) {
            Node tmp(n_x, n_y, n_z, n_c);
            if((n_x == s/2 && n_y == s/2) || (n_x == s/2 && n_z == s/2) || (n_y == s/2 && n_z == s/2)) return n_c;
            que.push(tmp);
            mark[n_x][n_y][n_z] = true;
        }
    }
    // m to s
    if(p.x < s && p.z > 0){
        int qua = s-p.x;
        if(qua > p.z) qua = p.z;
        int n_x = p.x+qua, n_y = p.y, n_z = p.z-qua, n_c = p.c+1;
        if(!mark[n_x][n_y][n_z]) {
            Node tmp(n_x, n_y, n_z, n_c);
            if((n_x == s/2 && n_y == s/2) || (n_x == s/2 && n_z == s/2) || (n_y == s/2 && n_z == s/2)) return n_c;
            que.push(tmp);
            mark[n_x][n_y][n_z] = true;
        }
    }
    // n to m
    if(p.y > 0 && p.z < m){
        int qua = m - p.z;
        if(qua > p.y) qua = p.y;
        int n_x = p.x, n_y = p.y-qua, n_z = p.z+qua, n_c = p.c+1;
        if(!mark[n_x][n_y][n_z]) {
            Node tmp(n_x, n_y, n_z, n_c);
            if((n_x == s/2 && n_y == s/2) || (n_x == s/2 && n_z == s/2) || (n_y == s/2 && n_z == s/2)) return n_c;
            que.push(tmp);
            mark[n_x][n_y][n_z] = true;
        }
    }
    // m to n
    if(p.z > 0 && p.y < n){
        int qua = n - p.y;
        if(qua > p.z) qua = p.z;
        int n_x = p.x, n_y = p.y+qua, n_z = p.z-qua, n_c = p.c+1;
        if(!mark[n_x][n_y][n_z]) {
            Node tmp(n_x, n_y, n_z, n_c);
            if((n_x == s/2 && n_y == s/2) || (n_x == s/2 && n_z == s/2) || (n_y == s/2 && n_z == s/2)) return n_c;
            que.push(tmp);
            mark[n_x][n_y][n_z] = true;
        }
    }
    return -1;
}

int main(){

    while(cin>>s>>n>>m){
        bool flag = true;
        if(!s && !n && !m) break;
        if(s%2 == 1){
            puts("NO");
        }
        else {
            init();
            Node root(s, 0, 0, 0);
            mark[s][0][0] = true;
            que.push(root);
            int min_c;
            while (!que.empty()) {
                min_c = BFS(que.front());
                que.pop();
                if (min_c != -1) {
                    cout << min_c << endl;
                    flag = false;
                    break;
                }
            }
            if(flag)
                puts("NO");
        }
    }

    return 0;
}