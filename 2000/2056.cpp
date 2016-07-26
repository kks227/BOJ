#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N, time[10000], result = 0;
	vector<int> successor[10000];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int K;
		scanf("%d %d", time+i, &K);
		for(int j=0; j<K; j++){
			int pre;
			scanf("%d", &pre);
			successor[pre-1].push_back(i);
		}
		result = max(result, time[i]);
	}

	int finish[10000] = {0};
	for(int i=0; i<N; i++)
		for(int next: successor[i]){
			finish[next] = max(finish[next], finish[i]+time[i]);
			result = max(result, finish[next]+time[next]);
		}
	printf("%d\n", result);
}