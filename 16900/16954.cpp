#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 8;
const int roff[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
const int coff[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int main(){
    char map[N][N];
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j)
            map[i][j] = getchar();
        getchar();
    }

    queue<int> Q;
    Q.push((N-1)*N);
    bool visited[N][N] = {false,};
    visited[N-1][0] = true;
    while(!Q.empty()){
        int r = Q.front()/N, c = Q.front()%N; Q.pop();
        for(int d = 0; d < 9; ++d){
            int nr = r+roff[d], nc = c+coff[d], tr = nr - 1;
            if(nr >= N || nc < 0 || nc >= N || map[nr][nc] == '#') continue;
            if(tr >= 0 && map[tr][nc] == '#') continue;
            if(nr <= 0){
                puts("1");
                return 0;
            }
            if(!visited[tr][nc]){
                visited[tr][nc] = true;
                Q.push(tr*N + nc);
            }
        }
    }
    puts("0");
}