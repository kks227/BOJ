#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int XN = 50000;

inline double f(double a, double b, double x){ return a*exp(-x*x) + b*sqrt(x); }

int main(){
    double V0, r2 = -1;
    int N, r1 = -1;
    scanf("%lf %d", &V0, &N);
    for(int i = 0; i < N; ++i){
        double a, b, h;
        scanf("%lf %lf %lf", &a, &b, &h);
        double dx = h / XN, V = 0, temp;
        for(int j = 0; j < XN; ++j){
            temp = f(a, b, dx*j+dx/2);
            V += temp * temp * acos(-1.0) * dx;
        }
        temp = abs(V - V0);
        if(r2 < 0 || r2 > temp){
            r1 = i;
            r2 = temp;
        }
    }
    printf("%d\n", r1);
}