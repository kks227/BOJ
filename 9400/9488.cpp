#include <cstdio>
using namespace std;

int main(){
    while(1){
        int N;
        scanf("%d", &N);
        if(N == 0) break;
        printf("%llu\n", 1LLU*N*(N+1)*(N+2)/6);
    }
}