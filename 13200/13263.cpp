#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100000;

struct LinearFunc{ // f(x) = ax + b, x >= s
    long long a, b;
    double s;
    LinearFunc(): LinearFunc(1, 0){}
    LinearFunc(long long a1, long long b1): a(a1), b(b1), s(0){}
};

inline double cross(LinearFunc &f, LinearFunc &g){
    return (g.b-f.b)/(f.a-g.a);
}



int main(){
    int N, A[MAX], B[MAX];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", A+i);
    for(int i = 0; i < N; ++i)
        scanf("%d", B+i);

    long long dp[MAX] = {0};
    LinearFunc f[MAX];
    int top = 0;
    for(int i = 1; i < N; ++i){
        LinearFunc g(B[i-1], dp[i-1]);
        while(top > 0){
            g.s = cross(f[top-1], g);
            if(f[top-1].s < g.s) break;
            --top;
        }
        f[top++] = g;

        long long x = A[i];
        int fpos = top-1;
        if(x < f[top-1].s){
            int lo = 0, hi = top-1;
            while(lo+1 < hi){
                int mid = (lo+hi)/2;
                (x < f[mid].s ? hi : lo) = mid;
            }
            fpos = lo;
        }
        dp[i] = f[fpos].a * x + f[fpos].b;
    }
    printf("%lld\n", dp[N-1]);
}