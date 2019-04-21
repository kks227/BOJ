#include <cstdio>
using namespace std;
const int MAX = 200000;

int main(){
    int N, Q, A[MAX], curr = 0;
    scanf("%d %d", &N, &Q);
    for(int i = 0; i < N; ++i)
        scanf("%d", A+i);
    for(int i = 0; i < N; ++i){
        int temp = 1;
        for(int j = 0; j < 4; ++j)
            temp *= A[(i+j)%N];
        curr += temp;
    }
    for(int q = 0; q < Q; ++q){
        int i, sum = 0;
        scanf("%d", &i);
        --i;
        for(int j = -3; j <= 0; ++j){
            int temp = 1;
            for(int k = 0; k < 4; ++k)
                temp *= A[(i+j+k+N)%N];
            sum += temp;
        }
        curr -= sum*2;
        A[i] *= -1;
        printf("%d\n", curr);
    }
}