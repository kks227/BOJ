#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 1000;
const int INF = 1e9;

int main(){
    int N, K, A[MAX];
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i)
        scanf("%d", A+i);

    int result = INF;
    for(int i = 1; i <= 1000; ++i){
        int temp = 0;
        for(int j = 0; j < N; ++j)
            if(i+j*K != A[j]) ++temp;
        result = min(temp, result);
    }
    printf("%d\n", result);
}