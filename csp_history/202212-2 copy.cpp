#include<cstdio>
#include<vector>
using namespace std;

int main(){
    int n, m, temp;
    int lst[101][101];
    int *pin_lst[101];
    int days[101];
    int fst_days[101];
    int lst_days[101];
    int timeout=0;
    for(int i=1;i<101;i++){
        pin_lst[i]=lst[i];
        lst[i][0]=0;
    }
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d", &temp);
        if(temp==0) *(++(pin_lst[i]))=i;
        else{
            for(int j=1;j<101;j++){
                if(*pin_lst[j]==temp){
                    *(++(pin_lst[j]))=i;
                }
            }
        }
    }

    for(int i=1;i<=m;i++){
        scanf("%d", &days[i]);
    }

    for(int i=1;i<101;i++){
        int *left=lst[i]+1;
        int *right=pin_lst[i]+1;
        if(left==right) continue;
        int day_sum=1;
        for(; left!=right; left++){
            fst_days[*left]=day_sum;
            day_sum+=days[*left];
        }
        if(day_sum>n+1) 
            timeout=1;
    }
    for(int i=1;i<m+1;i++){
        printf("%d ", fst_days[i]);
    }

    if(timeout==0){
        printf("\n");
        for(int i=1;i<101;i++){
            int *left=lst[i];
            int *right=pin_lst[i];
            if(left==right) continue;
            int day_sum=n+1;
            for(; left!=right; right--){
                day_sum-=days[*right];
                lst_days[*right]=day_sum;
            }
        }
        for(int i=1;i<m+1;i++){
            printf("%d ", lst_days[i]);
        } 
    }
}