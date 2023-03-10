#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int mat[120][120];
int mat_min[120]={100000};
bool visited[120]={false};
int N;

int prim(){
    int j, ans=0;
    visited[0]=true;
    for(int i=0;i<N;i++){
        mat_min[i]=mat[0][i];
    }

    for(int total=N-1;total;total--){
        int min=100000, min_loc;
        for(int i=0;i<N;i++){
            if(visited[i]==false && mat_min[i]<min){
                min_loc=i;
                min=mat_min[i];
            }
        }
        visited[min_loc]=true;
        ans+=min;
        j=min_loc;
        for(int i=0;i<N;i++){
            if(visited[i]==false && mat[j][i]<mat_min[i]){
                mat_min[i]=mat[j][i];
            }
        }
    }
    return ans;
}

int main(){
    int q;
    int a,b;
    while(scanf("%d",&N)==1){
        for(int i=0;i<120;i++){
            mat_min[i]=100000;
            visited[i]=false;
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                scanf("%d", &mat[i][j]);
            }
        }
        scanf("%d",&q);
        while (q--) {
            scanf("%d%d",&a,&b);
            mat[a-1][b-1]=0;
            mat[b-1][a-1]=0;
        }
        printf("%d\n", prim());
    }
    getchar();getchar();
}
