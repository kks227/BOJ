#include <cstdio>
using namespace std;

int main(){
	int N, K, use[100] = {0}, plan[100];
	scanf("%d %d", &N, &K);
	for(int i=0; i<K; i++)
		scanf("%d", plan+i);
	int result = 0;
	for(int i=0; i<K; i++){
		bool inUse = false;
		for(int j=0; j<N; j++)
			if(plan[i] == use[j]){
				inUse = true;
				break;
			}
		if(inUse) continue;
		inUse = false;
		for(int j=0; j<N; j++)
			if(use[j] == 0){
				use[j] = plan[i];
				inUse = true;
				break;
			}
		if(inUse) continue;

		int swap, val = -1;
		for(int j=0; j<N; j++){
			int term = 0;
			for(int k=i+1; k<K && use[j]!=plan[k]; k++) term++;
			if(term > val){
				swap = j;
				val = term;
			}
		}
		result++;
		use[swap] = plan[i];
	}
	printf("%d\n", result);
}