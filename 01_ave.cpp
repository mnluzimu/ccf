#include <cstdio>
#include <cmath>
double a[1000000];

int main(){
    int n;
    double ave = 0;
    double var = 0;
    scanf("%d", & n);
    for(int i = 0; i < n; i++){
        scanf("%lf", & a[i]);
        ave += a[i];
    }
    ave /= n;
    for(int i = 0; i < n; i++){
        var += (a[i] - ave) * (a[i] - ave);
    }
    var /= n;
    for(int i = 0; i < n; i++){
        printf("%lf\n", (a[i] - ave) / sqrt(var));
    }
    return  0;
}