#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> P;
const int INF = 2 * 1e9;

int main(){
	int N, M;
	vector<P> adj[4000];
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--; v--;
		adj[u].push_back(P(v, w*2));
		adj[v].push_back(P(u, w*2));
	}

	int d1[4000], d2[2][4000];
	fill(d1, d1+N, INF);
	fill(d2[0], d2[0]+N, INF);
	fill(d2[1], d2[1]+N, INF);
	d1[0] = d2[0][0] = 0;
	bool v1[4000] = {0}, v2[2][4000] = {0};
	priority_queue<P, vector<P>, greater<P>> PQ;

	PQ.push(P(0, 0));
	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(v1[curr] && !PQ.empty());
		if(v1[curr]) break;
		v1[curr] = true;

		for(auto &p: adj[curr]){
			int next = p.first, d = p.second;
			if(d1[curr] + d < d1[next]){
				d1[next] = d1[curr] + d;
				PQ.push(P(d1[next], next));
			}
		}
	}

	PQ.push(P(0, 0));
	while(!PQ.empty()){
		int curr;
		bool turn;
		do{
			curr = PQ.top().second % 4000;
			turn = PQ.top().second / 4000;
			PQ.pop();
		}while(v2[turn][curr] && !PQ.empty());
		if(v2[turn][curr]) break;
		v2[turn][curr] = true;

		for(auto &p: adj[curr]){
			int next = p.first, d = p.second;
			if(turn) d *= 2;
			else d /= 2;
			if(d2[turn][curr] + d < d2[!turn][next]){
				d2[!turn][next] = d2[turn][curr] + d;
				PQ.push(P(d2[!turn][next], (!turn)*4000 + next));
			}
		}
	}

	int result = 0;
	for(int i=1; i<N; i++)
		if(d1[i] < min(d2[0][i], d2[1][i])) result++;
	printf("%d\n", result);
}