#include <cstdio>
#include <queue>
using namespace std;
const int roff[6] = {-2, -2, 0, 0, 2, 2};
const int coff[6] = {-1, 1, -2, 2, -1, 1};
const int MAX = 200;

int main(){
    int N, sr, sc, er, ec;
    scanf("%d %d %d %d %d", &N, &sr, &sc, &er, &ec);
    queue<int> Q;
    Q.push(sr*MAX + sc);
    bool visited[MAX][MAX] = {false,};
    visited[sr][sc] = true;
    for(int result = 0; !Q.empty(); ++result){
        int qSize = Q.size();
        for(int i = 0; i < qSize; ++i){
            int r = Q.front()/MAX, c = Q.front()%MAX;
            Q.pop();
            if(r == er && c == ec){
                printf("%d\n", result);
                return 0;
            }
            for(int d = 0; d < 6; ++d){
                int nr = r+roff[d], nc = c+coff[d];
                if(nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc]) continue;
                visited[nr][nc] = true;
                Q.push(nr*MAX + nc);
            }
        }
    }
    puts("-1");
}