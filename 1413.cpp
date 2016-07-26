#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long cache[21][21];

long long cnt(int box, int bomb){
	if(box == 0) return 1;
	if(bomb == 0) return 0;
	long long &ret = cache[box][bomb];
	if(ret != -1) return ret;
	return ret = cnt(box-1, bomb-1) + (box-1)*cnt(box-1, bomb);
}

void divide(long long &P, long long &Q){
	long long A=P, B=Q, C;
	while(B){
		C = A%B;
		A = B;
		B = C;
	}
	P /= A;
	Q /= A;
}

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	memset(cache, -1, sizeof(cache));
	long long A = cnt(N, M), B = 1;
	for(int i=2; i<=N; i++)
		B *= i;
	divide(A, B);
	printf("%lld/%lld\n", A, B);
}