#include <cstdio>
using namespace std;
const int MAX = 30;
const int roff[4] = {0, 1, 1, 1};
const int coff[4] = {1, 0, 1, -1};

int main(){
    int N;
    char map[MAX][MAX];
    scanf("%d\n", &N);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j)
            map[i][j] = getchar();
        getchar();
    }

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(map[i][j] == '.') continue;
            for(int d = 0; d < 4; ++d){
                bool flag = true;
                for(int k = 1; k <= 2; ++k){
                    int r = i+roff[d]*k, c = j+coff[d]*k;
                    if(r < 0 || r >= N || c < 0 || c >= N || map[r][c] != map[i][j]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    putchar(map[i][j]);
                    return 0;
                }
            }
        }
    }
    puts("ongoing");
}