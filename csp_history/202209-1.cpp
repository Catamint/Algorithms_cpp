#include<cstdio>
#include<cmath>
int n, m;
int a;
int c[21]={1};
int b_pre[21]={0};

int main(){
    int c_sum=1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<n+1;i++){
        scanf("%d", &a);
        c_sum*=a;
        c[i]=c_sum;
        b_pre[i]=(m % c[i] - b_pre[i-1]);
    }
    for(int i=1;i<n+1;i++){
        printf("%d ",b_pre[i]/c[i-1]);
    }
    return 0;
}