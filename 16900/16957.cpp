#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int roff[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int coff[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int MAX_N = 500;
const int MAX = MAX_N*MAX_N;

int R, C, map[MAX_N][MAX_N], adj[MAX_N][MAX_N];

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
        if(adj[a] < 0){
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
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j)
            scanf("%d", &map[i][j]);

    UnionFind UF;
    memset(adj, -1, sizeof(adj));
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            int temp = map[i][j];
            for(int d = 0; d < 8; ++d){
                int nr = i+roff[d], nc = j+coff[d];
                if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                if(map[nr][nc] < temp){
                    temp = map[nr][nc];
                    adj[i][j] = d;
                }
            }
            if(adj[i][j] >= 0){
                int nr = i+roff[adj[i][j]], nc = j+coff[adj[i][j]];
                UF.u(i*MAX_N+j, nr*MAX_N+nc);
            }
        }
    }
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            int temp = UF.p[i*MAX_N+j];
            printf("%d ", temp < 0 ? -temp : 0);
        }
        puts("");
    }
}