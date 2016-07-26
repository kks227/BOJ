#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		char A[81];
		scanf("%s", A);
		int len = strlen(A);
		if(!next_permutation(A, A+len)) puts("BIGGEST");
		else puts(A);
	}
}