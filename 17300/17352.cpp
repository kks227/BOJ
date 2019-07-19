#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 300000;

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
    int N;
    scanf("%d", &N);
    UnionFind UF;
    for(int i = 0; i < N-2; ++i){
        int u, v;
        scanf("%d %d", &u, &v);
        UF.u(u-1, v-1);
    }
    for(int i = 0; i < N; ++i)
        if(UF.p[i] < 0) printf("%d ", i+1);
}