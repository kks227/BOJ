#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	char A[51], B[51];
	scanf("%s %s", A, B);
	int Alen = strlen(A);
	int Blen = strlen(B);
	int result = Blen;
	for(int i=0; Alen+i<=Blen; i++){
		int cnt = 0;
		for(int j=0; j<Alen; j++)
			if(A[j] != B[i+j]) cnt++;
		result = min(result, cnt);
	}
	printf("%d\n", result);
}