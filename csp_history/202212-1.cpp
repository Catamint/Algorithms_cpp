#include<cstdio>
#include<cmath>

int main(){
    int k_max;
    double i;
    double x;
    double ans=0;
    scanf("%d%lf", &k_max, &i);
    for(int k=0;k<=k_max;k++){
        scanf("%lf",&x);
        ans+=x*pow(i+1, -k);
    }
    printf("%lf", ans);
    return 0;
}

