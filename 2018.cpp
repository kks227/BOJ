#include <cstdio>
using namespace std;

bool b(int N, int M){
	int temp, n=N, m=M;
	while(m){
		temp = n%m;
		n = m;
		m = temp;
	}
	m = M/n;
	n = N/n;
	return (n-1)%m==0 && (n+1)%m==0;
}

int main(){

	int N, M = 1, result = 0;
	scanf("%d", &N);
	while(1){
		if(M%2 && N%M == 0){
			if(N/M - M/2 <= 0) break;
			result++;
		}
		else if(M%2 == 0 && N%M && b(N, M)){
			if(N/M - M/2 < 0) break;
			result++;
		}
		M++;
	}
	printf("%d\n", result);

	return 0;
}