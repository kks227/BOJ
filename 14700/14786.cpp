#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    double lo = 0, hi = 1.0*A*C+A;
    while(hi-lo >= 1e-9){
        double x = (lo+hi)/2;
        (A*x + B*sin(x) < C ? lo : hi) = x;
    }
    printf("%.15lf\n", hi);
}