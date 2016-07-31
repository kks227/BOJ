#include <cstdio>
using namespace std;

// n의 분해합을 구해주는 함수
int dsum(int n){
	if(n == 0) return 0;
	return n%10 + dsum(n/10);
}

int main(){
	int N;
	scanf("%d", &N);
	// 가능한 답은 N보다 작음. 작은 수부터 훑기
	for(int i=1; i<N; i++){
		// 답을 발견하는 즉시 출력하고 프로그램 종료
		if(i+dsum(i) == N){
			printf("%d\n", i);
			return 0;
		}
	}
	// 답이 존재하지 않음
	puts("0");
}