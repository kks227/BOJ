#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    int N, M;
    double A[4][4] = {0}, B[4][4], C[4][4];
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; ++i){
        char x, y;
        double p;
        scanf(" %c %c %lf", &x, &y, &p);
        A[x-'A'][y-'A'] = p;
    }
    memcpy(B, A, sizeof(A));
    for(int i = 1; i < N; ++i){
        memset(C, 0, sizeof(A));
        for(int k = 0; k < 4; ++k)
            for(int r = 0; r < 4; ++r)
                for(int c = 0; c < 4; ++c)
                    C[r][c] += A[r][k]*B[k][c];
        memcpy(A, C, sizeof(A));
    }
    for(int i = 0; i < 4; ++i){
        double result = 0;
        for(int j = 0; j < 4; ++j)
            result += 25 * A[j][i];
        printf("%.2lf\n", result);
    }
}