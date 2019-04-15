#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 20;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
    int N, map[MAX][MAX], r, c, size = 2, cnt = 0, result = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 9){
                map[i][j] = 0;
                r = i;
                c = j;
            }
        }
    }

    do{
        queue<int> Q;
        bool visited[MAX][MAX] = {false,};
        visited[r][c] = true;
        Q.push(r*MAX + c);
        r = c = -1;
        for(int i = 1; !Q.empty(); ++i){
            int qSize = Q.size();
            for(int j = 0; j < qSize; ++j){
                int tr = Q.front()/MAX, tc = Q.front()%MAX; Q.pop();
                for(int d = 0; d < 4; ++d){
                    int nr = tr + roff[d], nc = tc + coff[d];
                    if(nr < 0 || nr >= N || nc < 0 || nc >= N || map[nr][nc] > size || visited[nr][nc]) continue;
                    if(map[nr][nc] > 0 && map[nr][nc] < size){
                        if(r == -1 || nr < r || nr == r && nc < c){
                            r = nr;
                            c = nc;
                        }
                    }
                    visited[nr][nc] = true;
                    Q.push(nr*MAX + nc);
                }
            }

            if(r >= 0){
                result += i;
                map[r][c] = 0;
                if(++cnt == size){
                    cnt = 0;
                    ++size;
                }
                break;
            }
        }
    }while(r >= 0);
    printf("%d\n", result);
}