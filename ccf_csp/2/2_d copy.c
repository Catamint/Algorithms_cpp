#include <stdio.h>
int tail[2000];

int find(int m){
    if(tail[m]==m) return m;
    tail[m]=find(tail[m]);
    return tail[m];
}
void combine(int a,int b){
    a=find(a);
    b=find(b);
    if (a<b) tail[a]=b;
    else tail[b]=a;
    return;
}

int main(){
    int t, n, m, total;
    int a,b;
    scanf("%d",&t);
    while (t--) {
        for(int i=1;i<2000;i++){
            tail[i]=i;
        }        
        scanf("%d%d",&n,&m);
        total=n;
        while (m--) {
            scanf("%d%d",&a,&b);
            combine(a,b);
            total--;
        }
        printf("%d\n", total);
    }
    getchar();getchar();
}