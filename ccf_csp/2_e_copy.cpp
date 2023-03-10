#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
const int N = 1000 + 5;
const int INF = 0x3f3f3f3f;
int mat[N][N],lowc[N];
bool visit[N];

int prim(int n){
    int i,k,cnt,ret=0;
    memset(lowc,INF,sizeof(lowc));
    memset(visit,0,sizeof(visit));
    for(lowc[1]=cnt=0;cnt < n;cnt++){
        for(k=-1,i=1;i<=n;i++)
            if(!visit[i]&&(k==-1||lowc[i] < lowc[k]))
                k = i;
        for(visit[k]=true,ret+=lowc[k],i=1;i<=n;i++)
            if(!visit[i]&&mat[k][i] < lowc[i])
                lowc[i] = mat[k][i];
    }
    return ret;
}
int main(){
    int n,m,u,v;
    while(scanf("%d",&n)==1){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) scanf("%d",&mat[i][j]);
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d %d",&u,&v);
            mat[u][v] = mat[v][u] = 0;
        }
        printf("%d\n",prim(n));
    }
    getchar();
}