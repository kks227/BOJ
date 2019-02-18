#include <cstdio>
using namespace std;
const int MAX = 100000;

int main(){
    int N, K, M, dummy;
    scanf("%d %d %d", &N, &K, &M);
    for(int i = 0; i < N; ++i)
        scanf("%d", &dummy);

    int result = K-1;
    for(int i = 0; i < M; ++i){
        int O;
        scanf("%d", &O);
        if(O > 0){
            if(result < O) result = O-1-result;
        }
        else{
            O *= -1;
            if(result >= N-O) result = 2*N-1-result-O;
        }
    }
    printf("%d\n", result+1);
}