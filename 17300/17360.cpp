#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 2000;
const int MOD = 1000000007;

struct UnionFind{
    int p[MAX];
    UnionFind(){ fill(p, p+MAX, -1); }
    int f(int a){
        if(p[a] < 0) return a;
        return p[a] = f(p[a]);
    }
    bool u(int a, int b){
        a = f(a);
        b = f(b);
        if(a == b) return false;
        if(p[a] < p[b]){
            p[a] += p[b];
            p[b] = a;
        }
        else{
            p[b] += p[a];
            p[a] = b;
        }
        return true;
    }
};

int main(){
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    UnionFind UF;
    for(int i = 0; i+K <= N; ++i)
        for(int j = 0; j < K/2; ++j)
            UF.u(i+j, i+K-1-j);
    int result = 1;
    for(int i = 0; i < N; ++i)
        if(UF.p[i] < 0) result = 1LL * result * M % MOD;
    printf("%d\n", result);
}