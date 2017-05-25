#include <cstdio>
using namespace std;

int main(){
	int N, use[4] = {0}, plan[100];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", plan+i);
		plan[i]++;
	}

	int result = 0;
	for(int i=0; i<N; i++){
		bool inUse = false;
		for(int j=0; j<4; j++){
			if(plan[i] == use[j]){
				inUse = true;
				break;
			}
		}
		if(inUse) continue;
		for(int j=0; j<4; j++){
			if(use[j] == 0){
				use[j] = plan[i];
				inUse = true;
				break;
			}
		}
		if(inUse){
			result++;
			continue;
		}

		int swap, val = -1;
		for(int j=0; j<4; j++){
			int term = 0;
			for(int k=i+1; k<N && use[j]!=plan[k]; k++) term++;
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