#include <cstdio>
using namespace std;

inline int to5(int n){ return n==6 ? 5 : n; }
inline int to6(int n){ return n==5 ? 6 : n; }

int main(){
	int M, N;
	scanf("%d %d", &M, &N);
	int A[7] = {0}, B[7] = {0}, S[7] = {0}, T[7] = {0};
	int i = 6;
	while(M){
		A[i--] = M%10;
		M /= 10;
	}
	i = 6;
	while(N){
		B[i--] = N%10;
		N /= 10;
	}
	bool carry = false;
	for(i=6; i>=0; i--){
		S[i] = to5(A[i]) + to5(B[i]) + carry;
		carry = (S[i] >= 10);
		S[i] %= 10;
	}
	carry = false;
	for(i=6; i>=0; i--){
		T[i] = to6(A[i]) + to6(B[i]) + carry;
		carry = (T[i] >= 10);
		T[i] %= 10;
	}
	for(i=0; S[i]==0; i++);
	for(; i<7; i++)
		printf("%d", S[i]);
	putchar(' ');
	for(i=0; T[i]==0; i++);
	for(; i<7; i++)
		printf("%d", T[i]);
	puts("");
}