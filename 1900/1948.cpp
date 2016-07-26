#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge{
	int start, dest, dist, ee, le;
	Edge(): start(0), dest(0), dist(0), ee(0), le(0){}
	Edge(int start1, int dest1, int dist1, int ee1, int le1):
		start(start1), dest(dest1), dist(dist1), ee(ee1), le(le1){}
};

int N, M, S, D;
vector<int> ts;
vector<Edge> e;
vector<vector<Edge*>> pre;
vector<vector<Edge*>> suc;
vector<bool> visited;

void DFS(int current){
	if(visited[current]) return;
	visited[current] = true;
	for(Edge* edge: suc[current])
		DFS(edge->dest);
	ts.push_back(current);
}

int main(){
	scanf("%d %d", &N, &M);
	e.resize(M);
	pre.resize(N);
	suc.resize(N);
	for(int i=0; i<M; i++){
		int U, V, W;
		scanf("%d %d %d", &U, &V, &W);
		U--; V--;
		e[i] = Edge(U, V, W, -1, -1);
		suc[U].push_back(&e[i]);
		pre[V].push_back(&e[i]);
	}
	scanf("%d %d", &S, &D);
	S--; D--;
	vector<int> ee(N, 0), le(N, 0x7FFFFFFF);
	visited.resize(N);
	DFS(S);
	for(int i=ts.size()-1; i>=0; i--)
		for(Edge* edge: suc[ts[i]])
			ee[edge->dest] = max(ee[edge->dest], ee[edge->start]+edge->dist);
	for(int i=0; i<M; i++)
		e[i].ee = ee[e[i].start];
	le[D] = ee[D];
	int roadCnt = 0;
	for(int i=0; i<ts.size(); i++)
		for(Edge* edge: pre[ts[i]])
			le[edge->start] = min(le[edge->start], le[edge->dest]-edge->dist);
	for(int i=0; i<M; i++){
		e[i].le = le[e[i].dest] - e[i].dist;
		if(e[i].ee == e[i].le) roadCnt++;
	}
	printf("%d\n%d\n", ee[D], roadCnt);
}