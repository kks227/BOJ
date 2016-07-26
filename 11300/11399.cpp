#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, P[1000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", P+i);
	sort(P, P+N);
	int result = 0;
	for(int i=0; i<N; i++)
		result += (N-i)*P[i];
	printf("%d\n", result);
}