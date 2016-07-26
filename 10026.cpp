#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int N;

bool invalid(int r, int c){
    return r<0 || c<0 || r>=N || c>=N;
}

int main(){
    scanf("%d", &N);
    char map[100][100];
    for(int i=0; i<N; i++){
        getchar();
        for(int j=0; j<N; j++)
            map[i][j] = getchar();
    }
    int offset[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    for(int t=0; t<2; t++){
        queue<int> BFSQ;
        bool visited[100][100] = {0};
        int result = 0, cnt = N*N;
        while(cnt > 0){
            result++;
            for(int i=0; i<N*N; i++)
                if(!visited[i/N][i%N]){
                    BFSQ.push(i/N*100+i%N);
                    break;
                }
            while(!BFSQ.empty()){
                int r = BFSQ.front();
                int c = r%100;
                r /= 100;
                BFSQ.pop();
                if(visited[r][c]) continue;
                visited[r][c] = true;
                cnt--;
                for(int k=0; k<4; k++){
                    int nextR = r + offset[k][0];
                    int nextC = c + offset[k][1];
                    if(invalid(nextR, nextC)) continue;
                    if(map[r][c] == map[nextR][nextC]) BFSQ.push(nextR*100+nextC);
                }
            }
        }
        printf("%d ", result);
        if(t==0){
            for(int i=0; i<N; i++)
                for(int j=0; j<N; j++)
                    if(map[i][j]=='G') map[i][j] = 'R';
        }
    }
}