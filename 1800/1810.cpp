#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;
const int INF = 1e9;
typedef pair<int, int> PI;
typedef pair<double, int> PD;

inline double distance(PI &p, PI &q){
	return sqrt(pow(p.first-q.first, 2.0) + pow(p.second-q.second, 2.0));
}

int main(){
	int N, F;
	PI pos[50001];
	scanf("%d %d", &N, &F);
	for(int i=0; i<N; i++)
		scanf("%d %d", &pos[i].first, &pos[i].second);
	pos[N++] = PI(0, 0);
	sort(pos, pos+N);

	vector<PD> adj[50001];
	for(int i=0; i<N; i++){
		for(int j=-2; j<=2; j++){
			auto rs = lower_bound(pos, pos+N, PI(pos[i].first+j, -INF));
			auto re = upper_bound(pos, pos+N, PI(pos[i].first+j, INF));
			auto cs = lower_bound(rs, re, PI(pos[i].first+j, pos[i].second-2));
			auto ce = upper_bound(rs, re, PI(pos[i].first+j, pos[i].second+2));
			for(auto k=cs; k<ce; k++)
				adj[i].push_back(PD(distance(pos[i], *k), k-pos));
		}
	}

	bool visited[50001] = {0};
	double dist[50001];
	fill(dist, dist+N, INF);
	dist[0] = 0;
	priority_queue<PD, vector<PD>, greater<PD>> PQ;
	PQ.push(PD(0, 0));
	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(!PQ.empty() && visited[curr]);
		if(visited[curr]) break;
		visited[curr] = true;

		for(auto &p: adj[curr]){
			int next = p.second;
			double d = p.first;
			if(dist[next] > dist[curr] + d){
				dist[next] = dist[curr] + d;
				PQ.push(PD(dist[next], next));
			}
		}
	}

	double result = INF;
	for(int i=0; i<N; i++)
		if(pos[i].second == F) result = min(result, dist[i]);
	if(result < INF) printf("%.0lf\n", result);
	else puts("-1");
}