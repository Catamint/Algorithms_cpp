#include <cstdio>

int n,l,s;
int trees[2000][2];
int bonus[100][100];
int ans=0;

int main(){
    scanf("%d%d%d",&n,&l,&s);
    for(int i=0;i<n;i++){
        scanf("%d%d",&trees[i][0],&trees[i][1]);
    }
    for(int i=0;i<=s;i++){
        for(int j=0;j<=s;j++){
            scanf("%d",&bonus[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        int *t=trees[i];
        int jump=0;
        if(t[0]+s>l || t[1]+s>l) continue;
        for(int x=s;x>-1;x--){
            for(int y=0;y<=s;y++){
                if(bonus[x][y]){
                    int flag=0;
                    for(int j=0;j<n;j++){
                        if(trees[j][0]==t[0]+(s-x) && trees[j][1]==t[1]+y){
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0){
                        jump=1;
                        break;
                    }
                } else {
                    for(int j=0;j<n;j++){
                        if(trees[j][0]==t[0]+(s-x) && trees[j][1]==t[1]+y){
                            jump=1;
                            break;
                        }
                    }
                }
            }
            if(jump) break;
        }
        if(jump == 0) ans++;
    }
    printf("%d",ans);
    return 0;
}