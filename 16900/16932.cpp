#include <cstdio>
#include <unordered_set>
#include <algorithm>
using namespace std;
const int MAX_N = 1000;
const int MAX = MAX_N*MAX_N;
const int roff[4] = {1, 0, -1, 0};
const int coff[4] = {0, 1, 0, -1};

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
    int size(int a){ return -p[f(a)]; }
};

int main(){
    int R, C, map[MAX_N][MAX_N];
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j)
            scanf("%d", &map[i][j]);

    UnionFind UF;
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            if(!map[i][j]) continue;
            for(int d = 0; d < 2; ++d){
                int nr = i+roff[d], nc = j+coff[d];
                if(nr >= R || nc >= C) continue;
                if(map[nr][nc]) UF.u(i*MAX_N+j, nr*MAX_N+nc);
            }
        }
    }

    int result = 1;
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            if(map[i][j]) continue;

            unordered_set<int> S;
            for(int d = 0; d < 4; ++d){
                int nr = i+roff[d], nc = j+coff[d];
                if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                if(map[nr][nc]) S.insert(UF.f(nr*MAX_N+nc));
            }
            int temp = 1;
            for(int k: S)
                temp += UF.size(k);
            result = max(temp, result);
        }
    }
    printf("%d\n", result);
}