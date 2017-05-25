#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int N, R1, C1, R2, C2;
	scanf("%d %d %d %d %d", &N, &R1, &C1, &R2, &C2);
	int K = N*2 - 1;
	for(int i=R1; i<=R2; i++){
		for(int j=C1; j<=C2; j++){
			int r = i/K*K + N-1, c = j/K*K + N-1;
			int k = abs(r-i) + abs(c-j);
			putchar(k<N ? k%26+'a' : '.');
		}
		puts("");
	}
}