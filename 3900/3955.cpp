#include <cstdio>
#include <cmath>
#include <algorithm>
const int MAX = 1e9;
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    for(int tt=0; tt<T; tt++){
        int a, b, d, s, t;
        scanf("%d %d", &a, &b);
        if(b == 1){
            if(a == MAX) puts("IMPOSSIBLE");
            else printf("%d\n", a+1);
            continue;
        }

        b *= -1;
        int r1 = a, r2 = b, s1 = 1, s2 = 0, t1 = 0, t2 = 1;
        while(r2){
            int q = r1 / r2;
            if(r1 < 0 && r1%r2) q--;
            int r = r1 - q*r2; r1 = r2; r2 = r;
            int s = s1 - q*s2; s1 = s2; s2 = s;
            int t = t1 - q*t2; t1 = t2; t2 = t;
        }
        d = r1; s = s1; t = t1;

        if(abs(d) > 1) puts("IMPOSSIBLE");
        else{
            int k1 = s/b - 1; if(s < 0 && s%b) k1++;
            int k2 = -t/a; if(t >= 0 && t%a) k2--;
            int k = min(k1, k2);
            if(-t-1LL*k*a <= MAX) printf("%lld\n", -t-1LL*k*a);
            else puts("IMPOSSIBLE");
        }
    }
}