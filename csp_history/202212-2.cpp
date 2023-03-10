#include<cstdio>
#include<vector>
using namespace std;


int main(){
    int n, m, temp;
    int lst[101][101];
    int *pin_lst[101];
    int days[101];
    int fst_days[101];
    for(int i=1;i<101;i++){
        pin_lst[i]=lst[i];
        lst[i][0]=i;
    }
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d", &temp);
        if(temp==0) temp=i;
        for(int j=1;j<101;j++){
            if(*pin_lst[j]==temp){
                *++pin_lst[j]=i;
            }
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%d", &days[i]);
    }

    for(int i=1;i<101;i++){
        int j=1;
        for(;&lst[i][j]!=pin_lst[i];j++){
            printf("%d ",lst[i][j]);
        }
        if(j!=0) printf("\n");
    }
}