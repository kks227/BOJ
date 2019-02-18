#include <cstdio>
using namespace std;
const int MAX = 100;
const int roff[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int coff[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
    char W[MAX+1], map[MAX][MAX];
    int R, C;
    scanf("%s %d %d\n", W, &R, &C);
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j)
            map[i][j] = getchar();
        getchar();
    }

    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            for(int d = 0; d < 8; ++d){
                bool flag = true;
                int r = i, c = j;
                for(int k = 0; W[k]; ++k){
                    if(r < 0 || r >= R || c < 0 || c >= C || map[r][c] != W[k]){
                        flag = false;
                        break;
                    }
                    r += roff[d];
                    c += coff[d];
                }
                if(flag){
                    puts("1");
                    return 0;
                }
            }
        }
    }
    puts("0");
}