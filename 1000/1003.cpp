// [DynamicProgramming]

#include <cstdio>
using namespace std;
 
#define MAX 42
 
int main(){
	// 이 문제 답은 피보나치 수열과 일치
	// 피보나치 수열 계산해 둠
    int fibo[MAX] = {1, 0};
    for(int i=2; i<MAX; i++)
        fibo[i] = fibo[i-1] + fibo[i-2];
 
    int T, N;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        scanf("%d", &N);
        printf("%d %d\n", fibo[N], fibo[N+1]);
    }
}