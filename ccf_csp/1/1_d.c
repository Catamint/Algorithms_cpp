#include <math.h>
#include <stdio.h>

double y;

double f(double x){
    return 8 * pow(x, 4) + 7 * pow(x, 3) + 2 * pow(x, 2) + 3 * x + 6 ;
}
double search(double x1, double x2){
    double mid=(x2+x1)/2;
    if(x2-x1<0.000001) return x1;
    if(f(mid)>y) return search(x1,mid);
    else return search(mid,x2);
}
int main() {
    double ans;
    int times;
    double f0=f(0),f100=f(100);
    scanf("%d", &times);
    for (int i = 0; i < times; i++) {
        scanf("%lf", &y);
        if(y<f0 || y>f100) printf("No solution!\n");
        else{
            ans=search(1,100);
            printf("%.4lf\n", ans);
        }
    }
    getchar();
    getchar();
}
