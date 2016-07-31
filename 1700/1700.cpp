#include <cstdio>
using namespace std;

int main(){
	// use[i]: 현재 i번 구멍에 사용중인 기기 번호, plan[i]: 시간 i에 사용할 기기 번호
	int N, K, use[100] = {0}, plan[100];
	scanf("%d %d", &N, &K);
	for(int i=0; i<K; i++)
		scanf("%d", plan+i);

	int result = 0;
	for(int i=0; i<K; i++){
		// 비어 있는 구멍이 있는지 먼저 찾아봄
		bool inUse = false;
		for(int j=0; j<N; j++){
			if(plan[i] == use[j]){
				inUse = true;
				break;
			}
		}
		if(inUse) continue;

		// 이미 꽂아놓았는지 찾아봄
		inUse = false;
		for(int j=0; j<N; j++){
			if(use[j] == 0){
				use[j] = plan[i];
				inUse = true;
				break;
			}
		}
		if(inUse) continue;

		// 사용중인 기기 중 가장 나중에 다시 사용할 기기를 쫓아낸다.
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