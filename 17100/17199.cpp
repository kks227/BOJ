#include <cstdio>
using namespace std;
const int MAX = 100;

int main(){
	int N, deg[MAX] = {0,};
	scanf("%d", &N);
	for(int i = 0; i < N-1; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		++deg[u-1];
	}
	int result = -1;
	for(int i = 0; i < N; ++i){
		if(deg[i] == 0){
			if(result == -1) result = i+1;
			else{
				puts("-1");
				return 0;
			}
		}
	}
	printf("%d\n", result);
}