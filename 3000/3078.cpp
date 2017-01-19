#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int main(){
	int N, K;
	long long result = 0;
	scanf("%d %d", &N, &K);
	queue<int> Q[21];
	for(int i=0; i<N; i++){
		char name[21];
		scanf("%s", name);
		int L = strlen(name);
		while(!Q[L].empty() && Q[L].front() < i-K) Q[L].pop();
		result += Q[L].size();
		Q[L].push(i);
	}
	printf("%lld\n", result);
}