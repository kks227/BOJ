#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <functional>
#include <algorithm>
using namespace std;
typedef pair<int, int> intP;
typedef tuple<int, int, int> intT;
const int MAX = 19; // roundup log(2, 200000)

struct Node{
	bool isLeaf;
	int t, size;
	Node(): isLeaf(true), t(0), size(1){}
	Node(int t1, int s1): isLeaf(false), t(t1), size(s1){}
};

int N, M;
vector<intP> adjG[100000];

Node node[200000];
vector<int> child[200000];
int parent[200000][MAX], depth[200000], uf[200000];

int findUF(int u){
	if(uf[u] < 0) return u;
	return uf[u] = findUF(uf[u]);
}

bool unionUF(int u, int v){
	u = findUF(u);
	v = findUF(v);
	if(u == v) return false;
	// union v to u
	uf[u] += uf[v];
	uf[v] = u;
	return true;
}

void setDepthByDFS(int curr){
	for(int next: child[curr]){
		depth[next] = depth[curr]+1;
		setDepthByDFS(next);
	}
}



int main(){
	scanf("%d %d", &N, &M);
	priority_queue<intT, vector<intT>, greater<intT>> PQ;
	for(int i=0; i<M; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--; b--;
		adjG[a].push_back(intP(b, c));
		adjG[b].push_back(intP(a, c));
		PQ.push(intT(c, a, b));
	}
	for(int i=0; i<N; i++)
		node[i] = Node();

	int curNode = N;
	memset(parent, -1, sizeof(parent));
	memset(uf, -1, sizeof(uf));
	while(!PQ.empty()){
		intT tempT = PQ.top();
		PQ.pop();
		int a = get<1>(tempT);
		int b = get<2>(tempT);
		int c = get<0>(tempT);

		if(findUF(a) != findUF(b)){
			int curr = curNode++;
			int aRoot = findUF(a), bRoot = findUF(b);
			node[curr] = Node(c, node[aRoot].size + node[bRoot].size);
			child[curr].push_back(aRoot);
			child[curr].push_back(bRoot);
			parent[aRoot][0] = parent[bRoot][0] = curr;
			unionUF(curr, aRoot);
			unionUF(curr, bRoot);
		}
	}
	for(int i=0; i<curNode; i++){
		if(parent[i][0] == -1){
			depth[i] = 0;
			setDepthByDFS(i);
		}
	}

	for(int j=0; j<MAX-1; j++)
		for(int i=0; i<=curNode; i++)
			if(parent[i][j] != -1)
				parent[i][j+1] = parent[parent[i][j]][j];

	int Q;
	scanf("%d", &Q);
	for(int i=0; i<Q; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		x--; y--;
		if(findUF(x) != findUF(y)){
			puts("-1");
			continue;
		}

		if(depth[x] < depth[y]) swap(x, y);
		int diff = depth[x] - depth[y];
		for(int j=0; diff; j++){
			if(diff % 2) x = parent[x][j];
			diff /= 2;
		}
		if(x != y){
			for(int j=MAX-1; j>=0; j--){
				if(parent[x][j] != -1 && parent[x][j] != parent[y][j]){
					x = parent[x][j];
					y = parent[y][j];
				}
			}
			x = parent[x][0];
		}
		printf("%d %d\n", node[x].t, node[x].size);
	}
}