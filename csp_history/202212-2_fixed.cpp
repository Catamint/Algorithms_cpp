#include<cstdio>

int main(){
    int n, m, day_back;
    int box[101];
    int days[101];
    int d_first[101];
    int d_last[101];
    scanf("%d%d",&n,&m);
    for(int i=1; i<m+1; i++){
        scanf("%d", &box[i]);
    }
    for(int i=1; i<m+1;i++){
        scanf("%d", &days[i]);
    }
    for(int i=1; i<m+1; i++){
        day_back=box[i];
        if(day_back==0) d_first[i]=0;
        else d_first[i]=d_first[day_back]+days[day_back];
    }
    for(int i=1; i<m+1;i++){
        printf("%d ",d_first[i]+1); //+1
    }

    return 0;
}

/*

input:
    n,m
    box=[<i, i_l>] i:1->m
    days=[<i,days_i>] i:1->m

output:
    <i, df_i>
    if each df_i < n: <i, dl_i>

prg:
    for *i in box:
        if *i == 0: df(i)=0
        else             =days(*i)+df(*i)
    print d_f

    for: if df[i]+d[i]>n:
            flag=1; break;
    if flag==0:
        for(i=m;i>0;i--){
            dl[i]=
        }


*/