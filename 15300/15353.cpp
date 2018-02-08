#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 10003;

int main(){
	char A0[MAX], B0[MAX], A[MAX] = {0}, B[MAX] = {0}, C[MAX] = {0};
	scanf("%s %s", A0, B0);
	int Alen = strlen(A0), Blen = strlen(B0);
	copy(A0, A0+Alen, A+MAX-Alen);
	copy(B0, B0+Blen, B+MAX-Blen);
	reverse(A, A+MAX);
	reverse(B, B+MAX);
	bool carry = false;
	for(int i=0; i<MAX; i++){
		int val = carry;
		if(A[i] >= '0') val += A[i] - '0';
		if(B[i] >= '0') val += B[i] - '0';
		carry = (val >= 10);
		C[i] = val % 10 + '0';
	}
	int i;
	for(i=MAX-1; C[i]=='0'; i--);
	for(; i>=0; i--)
		putchar(C[i]);
}