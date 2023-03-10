#include <cstdio>
int n, x, temp;
int sum=0;
int a[31];
int ans[31][1000001];

int main(){
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=sum;j++){
            ans[i][j] = i==1? 0:ans[i-1][j];
            temp=ans[i-1][j-a[i]]+a[i];
            if(temp<j) ans[i][j] = temp>ans[i][j]? temp:ans[i][j];
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=sum;j++){
    //         printf("%d ",ans[i][j]);
    //     }
    //     printf("\n");
    // }

    int j=0;
    while(ans[n][++j]<x && j<=sum);
    printf("%d",ans[n][j]);
    return 0;
}