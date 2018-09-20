#include <cstdio>
#include <queue>
using namespace std;

int main(){
	int N, K;
	bool map[2][100000], visited[2][100000] = {true,};
	scanf("%d %d", &N, &K);
	for(int i=0; i<2; i++)
		for(int j=0; j<N; j++)
			scanf("%1d", &map[i][j]);

	queue<int> Q;
	Q.push(0);
	bool result = false;
	for(int i=0; !Q.empty() && !result; i++){
		int qSize = Q.size();
		for(int j=0; j<qSize; j++){
			bool side = Q.front()/100000;
			int node = Q.front()%100000;
			Q.pop();
			if(node+K >= N){
				result = true;
				break;
			}
			else if(map[!side][node+K] && !visited[!side][node+K]){
				visited[!side][node+K] = true;
				Q.push(100000*!side + node+K);
			}
			if(map[side][node+1] && !visited[side][node+1]){
				visited[side][node+1] = true;
				Q.push(100000*side + node+1);
			}
			if(map[side][node-1] && node-1 > i && !visited[side][node-1]){
				visited[side][node-1] = true;
				Q.push(100000*side + node-1);
			}
		}
	}
	printf("%d\n", result);
}