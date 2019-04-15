#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 50;
const int MAX = MAX_N*MAX_N;
const int roff[2] = {0, 1};
const int coff[2] = {1, 0};

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
    int N, L, R, map[MAX_N][MAX_N];
    scanf("%d %d %d", &N, &L, &R);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            scanf("%d", &map[i][j]);

    for(int result = 0; ; ++result){
        UnionFind UF;
        bool flag = false;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                for(int d = 0; d < 2; ++d){
                    int nr = i+roff[d], nc = j+coff[d];
                    if(nr >= N || nc >= N) continue;
                    int k = abs(map[i][j] - map[nr][nc]);
                    if(L <= k && k <= R){
                        flag = true;
                        UF.u(i*MAX_N+j, nr*MAX_N+nc);
                    }
                }
            }
        }
        if(!flag){
            printf("%d\n", result);
            break;
        }

        int sum[MAX] = {0,};
        vector<int> cell[MAX];
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                int k = i*MAX_N + j;
                sum[UF.f(k)] += map[i][j];
                cell[UF.f(k)].push_back(k);
            }
        }
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                int k = i*MAX_N + j, cnt = cell[k].size();
                if(cnt <= 1) continue;
                int val = sum[k] / cnt;
                for(int pos: cell[k])
                    map[pos/MAX_N][pos%MAX_N] = val;
            }
        }
    }
}