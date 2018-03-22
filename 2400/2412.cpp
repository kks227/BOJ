#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int INF = 1e9;

int main(){
	int N, T;
	P pos[50001];
	pos[0] = P(0, 0);
	scanf("%d %d", &N, &T);
	for(int i=1; i<=N; i++)
		scanf("%d %d", &pos[i].first, &pos[i].second);
	N++;
	sort(pos, pos+N);
	vector<int> adj[50000];
	for(int i=0; i<N; i++){
		for(int j=0; j<=2; j++){
			int lo = lower_bound(pos, pos+N, P(pos[i].first+j, pos[i].second-2)) - pos;
			int hi = upper_bound(pos, pos+N, P(pos[i].first+j, pos[i].second+2)) - pos;
			for(int k=lo; k<hi; k++){
				adj[i].push_back(k);
				adj[k].push_back(i);
			}
		}
	}

	queue<int> Q;
	bool visited[50001] = {true,};
	Q.push(0);
	for(int result=0; !Q.empty(); result++){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int curr = Q.front(); Q.pop();
			if(pos[curr].second >= T){
				printf("%d\n", result);
				return 0;
			}
			for(int next: adj[curr]){
				if(!visited[next]){
					visited[next] = true;
					Q.push(next);
				}
			}
		}
	}
	puts("-1");
}