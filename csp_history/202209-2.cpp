#include <cstdio>
int n,x;
int a[31];
int m[31][1000001];

int main()
{
    int ans,temp;
    scanf("%d%d",&n,&x);

    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if((ans=m[i-1][j]) < j) ans=__INT_MAX__;
            if((temp=m[i-1][x-a[i]]+a[i]) < j) temp=__INT_MAX__;
            ans = ans<temp ? ans:temp;
            m[i][j]=ans;
        }
    }

    printf("%d",ans);

    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }

    return 0;
}