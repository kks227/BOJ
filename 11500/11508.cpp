#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, C[100000], result = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", C+i);
	sort(C, C+N);
	for(int i=0; i<N; i++)
		if(i%3 < 2) result += C[N-i-1];
	printf("%d\n", result);
}