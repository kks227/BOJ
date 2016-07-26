#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
	int N, time[500], predecessor[500] = {0};
	vector<int> successor[500];
	queue<int> q;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", time+i);
		while(1){
			int pre;
			scanf("%d", &pre);
			if(pre == -1) break;
			predecessor[i]++;
			successor[pre-1].push_back(i);
		}
		if(!predecessor[i]) q.push(i);
	}

	int result[500] = {0};
	for(int i=0; i<N; i++){
		int u = q.front();
		q.pop();
		for(int next: successor[u]){
			result[next] = max(result[next], result[u]+time[u]);
			if(--predecessor[next] == 0) q.push(next);
		}
	}
	for(int i=0; i<N; i++)
		printf("%d\n", result[i]+time[i]);
}