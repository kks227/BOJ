#include <cstdio>
#include <cmath>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
const int MAX = 1<<21;
const double PI = acos(-1);
typedef complex<double> cpx;

void FFT(cpx f[], bool inv = false){
    int n = MAX;
    for(int i = 1, j = 0; i < n; ++i){
        int b = n/2;
        while(!((j ^= b) & b)) b /= 2;
        if(i < j) swap(f[i], f[j]);
    }
    for(int k = 1; k < n; k *= 2){
        double a = (inv ? PI/k : -PI/k);
        cpx w(cos(a), sin(a));
        for(int i = 0; i < n; i += k*2){
            cpx wp(1, 0);
            for(int j = 0; j < k; ++j){
                cpx x = f[i+j], y = f[i+j+k] * wp;
                f[i+j] = x + y;
                f[i+j+k] = x - y;
                wp *= w;
            }
        }
    }
    if(inv){
        for(int i = 0; i < n; ++i)
            f[i] /= n;
    }
}

void power(cpx a[], cpx b[]){
    FFT(a);
    for(int i = 0; i < MAX; ++i)
        b[i] = a[i]*a[i];
    FFT(b, true);
}



int main(){
    bool np[MAX/2] = {true, true,};
    cpx a[MAX], b[MAX];
    a[2] = cpx(1, 0);
    for(int i = 4; i < MAX/2; i += 2)
        np[i] = true;
    for(int i = 3; i < MAX/2; i += 2){
        if(np[i]) continue;
        a[i] = cpx(1, 0);
        for(long long j = 1LL*i*i; j < MAX/2; j += i*2)
            np[j] = true;
    }
    power(a, b);

    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t){
        int N;
        scanf("%d", &N);
        long long result = (long long)round(b[N].real());
        if(!np[N/2]) --result;
        printf("%lld\n", result/2 + !np[N/2]);
    }
}