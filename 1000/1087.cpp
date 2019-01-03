#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 50;
const int LOOPS = 1e3;
const int INF = 1e9;

int N, x0[MAX], y0[MAX], dx[MAX], dy[MAX];

inline double f(double t){
    double xMax = -INF, xMin = INF, yMax = -INF, yMin = INF;
    for(int i = 0; i < N; ++i){
        double x = x0[i] + dx[i]*t, y = y0[i] + dy[i]*t;
        xMax = max(x, xMax); xMin = min(x, xMin);
        yMax = max(y, yMax); yMin = min(y, yMin);
    }
    return max(xMax - xMin, yMax - yMin);
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d %d %d %d", x0+i, y0+i, dx+i, dy+i);

    double lo = 0, hi = INF;
    for(int t = 0; t < LOOPS; ++t){
        double p = (2*lo+hi)/3, q = (lo+2*hi)/3;
        if(f(p) < f(q)) hi = q;
        else lo = p;
    }
    printf("%.10lf\n", f(lo));
}