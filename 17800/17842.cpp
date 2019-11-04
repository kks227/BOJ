#include <cstdio>
using namespace std;
const int MAX = 200000;

int main(){
	int N, deg[MAX] = {0,};
	scanf("%d", &N);
	for(int i = 0; i < N-1; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		++deg[u]; ++deg[v];
	}
	int result = 1;
	for(int i = 0; i < N; ++i)
		if(deg[i] == 1) ++result;
	printf("%d\n", result/2);
}