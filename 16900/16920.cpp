#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 1000;
const int N = 10;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
    int R, C, P, S[N], map[MAX][MAX] = {0,}, cnt[N] = {0,};
    queue<int> Q[N];
    scanf("%d %d %d", &R, &C, &P);
    for(int i = 1; i <= P; ++i)
        scanf("%d", S+i);
    for(int i = 0; i < R; ++i){
        getchar();
        for(int j = 0; j < C; ++j){
            char c = getchar();
            if(c == '#') map[i][j] = -1;
            else if(c != '.'){
                int k = c - '0';
                map[i][j] = k;
                ++cnt[k];
                Q[k].push(i*MAX + j);
            }
        }
    }

    while(1){
        bool flag = false;

        for(int i = 1; i <= P; ++i){
            if(!Q[i].empty()) flag = true;
            for(int j = 0; j < S[i] && !Q[i].empty(); ++j){
                int qSize = Q[i].size();
                for(int k = 0; k < qSize; ++k){
                    int r = Q[i].front()/MAX, c = Q[i].front()%MAX;
                    Q[i].pop();
                    for(int d = 0; d < 4; ++d){
                        int nr = r+roff[d], nc = c+coff[d];
                        if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] != 0) continue;
                        map[nr][nc] = i;
                        ++cnt[i];
                        Q[i].push(nr*MAX + nc);
                    }
                }
            }
        }

        if(!flag) break;
    }
    for(int i = 1; i <= P; ++i)
        printf("%d ", cnt[i]);
}