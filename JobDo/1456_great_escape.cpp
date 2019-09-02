#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct Node{
    int x,y,z;
    int t;
    Node(int m_x, int m_y, int m_z, int m_t):x(m_x),y(m_y),z(m_z),t(m_t){}
};

int nex[][4]={{1,0,0,1},{-1,0,0,1},{0,1,0,1},{0,-1,0,1},{0,0,1,1},{0,0,-1,1}};

int maze[50][50][50];
bool mark[50][50][50];
int n, a, b, c, T;
queue<Node> que;

bool checkCoord(int x, int y, int z){
    if (x < 0 || x > a - 1 || y < 0 || y > b - 1 || z < 0 || z > c - 1 || mark[x][y][z] || maze[x][y][z]) return false;
    else return true;
}

int BFS(Node n) {
    int x = n.x, y = n.y, z = n.z, t = n.t;
    for(int i = 0; i < 6; i++){
        int n_x = x+nex[i][0], n_y = y+nex[i][1], n_z = z+nex[i][2], n_t = t+nex[i][3];
        if(checkCoord(n_x, n_y, n_z)){
            que.push(Node(n_x,n_y,n_z,n_t));
            mark[n_x][n_y][n_z] = true;
            if(n_x == a-1 && n_y == b-1 && n_z == c-1){
                que.pop();
                return n_t;
            }
        }
    }
    que.pop();
    return -1;
}

int main(){
    scanf("%d",&n);
    while(n > 0){
        bool flag = true;
        scanf("%d %d %d %d", &a, &b, &c,&T);
        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++){
                for(int k = 0; k < c; k++){
                    scanf("%d",&maze[i][j][k]);
                    mark[i][j][k] = false;
                }
            }
        }
        while(!que.empty()) que.pop();
        Node root(0,0,0,0);
        mark[0][0][0] = true;
        que.push(root);
        int min_t;
        while(!que.empty()) {
            Node tmp = que.front();
            min_t = BFS(tmp);
            if(min_t != -1 && min_t <= T){
                cout<<min_t<<endl;
                flag = false;
                break;
            }
        }
        if(flag) cout<<-1<<endl;

        n--;
    }

    return 0;
}