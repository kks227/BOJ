#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000000;

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
    int N, Q, cnt = 0;
    scanf("%d %d", &N, &Q);
    UnionFind UF;
    bool dirty[MAX] = {false,};
    for(int i = 0; i < N; ++i){
        int val;
        scanf("%d", &val);
        dirty[i] = val;
        if(dirty[i]){
            ++cnt;
            if(i > 0 && dirty[i-1]) cnt -= UF.u(i, i-1);
        }
    }

    for(int q = 0; q < Q; ++q){
        int a, b;
        scanf("%d", &a);
        if(a == 0) printf("%d\n", cnt);
        else{
            scanf("%d", &b);
            --b;
            if(!dirty[b]){
                dirty[b] = true;
                if(b > 0 && dirty[b-1]) cnt -= UF.u(b, b-1);
                if(b < N-1 && dirty[b+1]) cnt -= UF.u(b, b+1);
                ++cnt;
            }
        }
    }
}