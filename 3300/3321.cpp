#include <cstdio>
#include <numeric>
#include <algorithm>
using namespace std;
const int MAX_R = 15000;
const int MAX_C = 1500;

int main(){
    int R, C;
    char map[MAX_R][MAX_C+1];
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; ++i)
        scanf("%s", map[i]);

    int result = 0, pos[2][MAX_C] = {0,}, height[2][MAX_C] = {0,};
    iota(pos[0], pos[0] + C, 0);
    for(int i = 0, t = 0; i < R; ++i, t = !t){
        int k = 0;
        for(int j = 0; j < C; ++j){
            if(map[i][ pos[t][j] ] == '1'){
                height[!t][k] = height[t][j] + 1;
                pos[!t][k++] = pos[t][j];
            }
        }
        for(int j = 0, l = 0; j < C; ++j){
            if(map[i][ pos[t][j] ] == '0'){
                height[!t][k + l] = 0;
                pos[!t][k + (l++)] = pos[t][j];
            }
        }
        for(int j = 0; j < C; ++j)
            result = max((j+1)*height[!t][j], result);
    }
    printf("%d\n", result);
}