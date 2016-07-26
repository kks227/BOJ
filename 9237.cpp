#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, T[100000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", T+i);
	sort(T, T+N);
	int result = 0, days = 2;
	for(int i=N-1; i>=0; i--){
		result = max(result, days+T[i]);
		days++;
	}
	printf("%d\n", result);
}