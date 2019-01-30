#include <cstdio>
using namespace std;
const int MAX = 1000;

int main(){
    int N, M, A[MAX], B[MAX], cnt[MAX] = {0,};
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i)
        scanf("%d", A+i);
    for(int i = 0; i < M; ++i){
        scanf("%d", B+i);
        for(int j = 0; j < N; ++j){
            if(A[j] > B[i]) continue;
            ++cnt[j];
            break;
        }
    }

    int result = 0;
    for(int i = 1; i < N; ++i)
        if(cnt[result] < cnt[i]) result = i;
    printf("%d\n", result+1);
}