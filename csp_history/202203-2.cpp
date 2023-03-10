#include <cstdio>
int n,m,k;
int plan[200500];
int ti,ci,tpk;
int cur=1,sum=0;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++){
        scanf("%d%d",&ti,&ci);
        plan[ti+1]--;
        if(ti-ci+1>0) plan[ti-ci+1]++;
        else plan[1]++;
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&tpk);
        tpk+=k;
        for(;cur<=tpk;cur++){
            sum+=plan[cur];  
        }
        printf("%d\n",sum);
    }
}