#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100;

int main(){
    int N, next[MAX];
    long long B[MAX];
    bool outdegree[MAX] = {false,};
    scanf("%d", &N);
    fill(next, next + N, -1);
    for(int i = 0; i < N; ++i)
        scanf("%lld", B+i);
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(i == j) continue;
            if(B[i] == B[j]*3 || B[i]*2 == B[j]){
                outdegree[j] = true;
                next[i] = j;
            }
        }
    }
    for(int i = 0; i < N; ++i){
        if(!outdegree[i]){
            printf("%lld", B[i]);
            while(next[i] >= 0)
                printf(" %lld", B[i = next[i]]);
            break;
        }
    }
}