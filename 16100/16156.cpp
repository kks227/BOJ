#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int MAX_N = 500;
const int MAX = MAX_N*MAX_N;
const unsigned int MAX_COST = 10000;
const unsigned int INF = MAX_COST*MAX;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
typedef pair<unsigned int, unsigned int> P;

int main(){
	int R, C;
	vector<P> adj[MAX];
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			int c;
			scanf("%d", &c);
			for(int d = 0; d < 4; ++d){
				int nr = i+roff[d], nc = j+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
				adj[i*MAX_N + j].push_back(P(nr*MAX_N + nc, c));
			}
		}
	}

	int prev[MAX];
	unsigned int dist[MAX];
	bool visited[MAX] = {false,};
	fill(prev, prev+MAX, -1);
	fill(dist, dist+MAX, INF);
	priority_queue<P, vector<P>, greater<P>> PQ;
	for(int i = 0; i < R; ++i){
		int u = i*MAX_N + C-1;
		dist[u] = 0;
		PQ.push(P(0, u));
	}

	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(visited[curr] && !PQ.empty());
		if(visited[curr]) break;
		visited[curr] = true;

		for(auto &p: adj[curr]){
			int next = p.first;
			unsigned int d = p.second;
			if(dist[next] > dist[curr] + d){
				prev[next] = curr;
				dist[next] = dist[curr] + d;
				PQ.push(P(dist[next], next));
			}
		}
	}

	int result[MAX_N] = {0,}, dest[MAX];
	fill(dest, dest+MAX, -1);
	for(int i = 0; i < R; ++i)
		dest[i*MAX_N + C-1] = i;
	for(int i = 0; i < R; ++i){
		stack<int> S;
		S.push(i*MAX_N);
		while(dest[S.top()] < 0)
			S.push(prev[S.top()]);
		int k = dest[S.top()];
		S.pop();
		++result[k];
		while(!S.empty()){
			dest[S.top()] = k;
			S.pop();
		}
	}
	for(int i = 0; i < R; ++i)
		printf("%d\n", result[i]);
}