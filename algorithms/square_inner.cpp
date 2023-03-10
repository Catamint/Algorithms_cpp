#include <cstdio>
#include<cmath>

int t[20][20];
int n;
int square[20][2]={{2,2},{4,3},{1,1}};
int longest[20];

void make(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            t[i][j]=0;
            if (square[i][0]-square[j][0]<0 && square[i][1]-square[j][1]<0)
            {
                t[i][j]=1;
            }
        }
    }
}
void print_t(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j<n;j++){
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    
}

int lon(int i){
    if (longest[i]) return longest[i];
    int *perm=&longest[i];
    int temp=0;
    *perm=0;
    for(int j=0;j<n;j++){
        temp=lon(j);
        if(temp > *perm) *perm=temp; 
    }
    return *perm;
}

int main(){
    // scanf("%d",&n);
    // for(int i=0;i<n;i++){
    //     scanf("%d%d",&square[i][0],&square[i][1]);
    // }

    n=3;

    make();
    print_t();
    for(int i=0;i<n;i++){
        lon(i);
    }
    return 0;
}