#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 50;

int main(){
    int R, C;
    char map[MAX+1][MAX];
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; ++i){
        getchar();
        for(int j = 0; j < C; ++j)
            map[i][j] = getchar();
    }
    fill(map[R], map[R]+C, '#');
    for(int i = R-1; i >= 0; --i){
        for(int j = 0; j < C; ++j){
            if(map[i][j] != 'o') continue;
            for(int k = i; map[k+1][j] == '.'; ++k)
                swap(map[k][j], map[k+1][j]);
        }
    }
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j)
            putchar(map[i][j]);
        puts("");
    }
}