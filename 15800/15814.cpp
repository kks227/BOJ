#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	char S[101];
	int T;
	scanf("%s %d", S, &T);
	for(int i=0; i<T; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		swap(S[A], S[B]);
	}
	puts(S);
}