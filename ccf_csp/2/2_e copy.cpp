#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
char map[2][20][20];
bool visited[2][20][20];

struct node
{
    int z;
    int x;
    int y;
    int t;
};


int bfs() {
    queue<node> que;
    node first={0,0,0,0};
    que.push(first);
    while (!que.empty())
    {
        node cur=que.front();
        que.pop();
        for(int i=-1;i<2;i++){
            for(int j=-1;j<2;j++){
                if(i!=j){
                    
                }
            }
        }
    }
    


}

int main() {
    int c;
    int n, m, t;
    while (c--) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 20; j++) {
                for (int k = 0; i < 20; k++) {
                    visited[i][j][k] = false;
                }
            }
        }
        scanf("%d%d%d", &n, &m, &t);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &map[0][n][m]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &map[1][n][m]);
            }
        }
        if (bfs()) printf("YES\n");
        else printf("NO\n");
    }
}
