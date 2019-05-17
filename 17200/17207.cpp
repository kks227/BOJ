#include <cstdio>
using namespace std;
const int N = 5;
const char name[N][8] = {"Inseo", "Junsuk", "Jungwoo", "Jinwoo", "Youngki"};

int main(){
    int A[N][N], B[N][N];
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            scanf("%d", &A[i][j]);
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            scanf("%d", &B[i][j]);
    int load[N] = {0,};
    for(int x = 0; x < N; ++x)
        for(int y = 0; y < N; ++y)
            for(int i = 0; i < N; ++i)
                load[x] += A[x][i] * B[i][y];
    int r1 = load[0], r2 = 0;
    for(int i = 1; i < N; ++i){
        if(r1 >= load[i]){
            r1 = load[i];
            r2 = i;
        }
    }
    puts(name[r2]);
}