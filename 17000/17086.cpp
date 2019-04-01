#include <cstdio>
#include <queue>
using namespace std;
const int roff[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int coff[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int MAX = 50;

int main(){
    int R, C;
    scanf("%d %d", &R, &C);
    queue<int> Q;
    bool visited[MAX][MAX] = {false,};
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            int val;
            scanf("%d", &val);
            if(val == 1){
                visited[i][j] = true;
                Q.push(i*MAX + j);
            }
        }
    }
    int result = -1;
    for(; !Q.empty(); ++result){
        int qSize = Q.size();
        for(int i = 0; i < qSize; ++i){
            int r = Q.front()/MAX, c = Q.front()%MAX;
            Q.pop();
            for(int d = 0; d < 8; ++d){
                int nr = r+roff[d], nc = c+coff[d];
                if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                if(!visited[nr][nc]){
                    visited[nr][nc] = true;
                    Q.push(nr*MAX + nc);
                }
            }
        }
    }
    printf("%d\n", result);
}