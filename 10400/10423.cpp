#include <cstdio>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 1000;
const int MAX_E = 100000;
typedef tuple<int, int, int> Edge;

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
    int N, M, K, root;
    UnionFind UF;
    scanf("%d %d %d %d", &N, &M, &K, &root);
    --root;
    for(int i = 1; i < K; ++i){
        int u;
        scanf("%d", &u);
        UF.u(root, u-1);
    }
    Edge e[MAX_E];
    for(int i = 0; i < M; ++i){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        e[i] = Edge(w, u-1, v-1);
    }
    sort(e, e+M);
    int result = 0, cnt = K;
    for(int i = 0; i < M; ++i){
        int u, v, w;
        tie(w, u, v) = e[i];
        if(UF.u(u, v)){
            result += w;
            if(++cnt == N) break;
        }
    }
    printf("%d\n", result);
}