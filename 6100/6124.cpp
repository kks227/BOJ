#include <cstdio>
using namespace std;
const int MAX = 100;

int main(){
    int R, C, map[MAX][MAX], result = -1, r, c;
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j)
            scanf("%d", &map[i][j]);
    for(int i = 0; i < R-2; ++i){
        for(int j = 0; j < C-2; ++j){
            int temp = 0;
            for(int k = 0; k < 3; ++k)
                for(int l = 0; l < 3; ++l)
                    temp += map[i+k][j+l];
            if(temp > result){
                result = temp;
                r = i;
                c = j;
            }
        }
    }
    printf("%d\n%d %d\n", result, r+1, c+1);
}