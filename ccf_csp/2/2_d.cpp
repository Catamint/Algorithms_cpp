#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int tail[1500];

int find(int m){
    if(tail[m]==m) return m;
    tail[m]=find(tail[m]);
    return tail[m];
}
int combine(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b) return 0;
    if (a<b) tail[b]=a;
    else tail[a]=b;
    return 1;
}

int main(){
    int t, n, m, total;
    int a,b;
    scanf("%d",&t);
    while (t--) {
        for(int i=1;i<1500;i++){
            tail[i]=i;
        }        
        scanf("%d%d",&n,&m);
        total=n;
        while (m--) {
            scanf("%d%d",&a,&b);
            if(combine(a,b))
                total--;
        }
        printf("%d\n", total);
    }
    getchar();getchar();
}