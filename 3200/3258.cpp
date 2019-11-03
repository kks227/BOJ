#include <cstdio>
using namespace std;
const int MAX = 1000;

int main(){
	int N, Z, M;
	bool trap[MAX] = {false,};
	scanf("%d %d %d", &N, &Z, &M);
	--Z;
	for(int i = 0; i < M; ++i){
		int k;
		scanf("%d", &k);
		trap[k-1] = true;
	}
	for(int k = 1; ; ++k){
		bool flag = true, visited[MAX] = {true,};
		for(int i = 0; ; ){
			i = (i+k)%N;
			if(i == Z) break;
			if(trap[i] || visited[i]){
				flag = false;
				break;
			}
			visited[i] = true;
		}
		if(flag){
			printf("%d\n", k);
			break;
		}
	}
}