#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <unordered_set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX_V = 100000;
const int MAX_E = 500000;
const int MAX_D = 19;
const int MAX = MAX_V * 2;
typedef pair<int, int> P;
typedef tuple<int, int, int> Edge;

struct BCCNode{
	bool isPoint;
	int ac;
	unordered_set<int> member;
	vector<int> adj;
	BCCNode(): isPoint(false), ac(-1){}
	BCCNode(int ac1): isPoint(true), ac(ac1){}
};

class BlockCutTree{
public:
	int V, E, C, vcNum[MAX_V];
	vector<int> adj[MAX_V];
	Edge edge[MAX_E];
	map<P, int> eNum;
	BCCNode cn[MAX];

	void input(){
		scanf("%d %d", &V, &E);
		for(int i = 0; i < E; ++i){
			int u, v;
			scanf("%d %d", &u, &v);
			edge[i] = Edge(--u, --v, -1);
			eNum[P(u, v)] = eNum[P(v, u)] = i;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}

	void construct(){
		C = dcnt = 0;
		fill(dfsn, dfsn + V, -1);
		for(int i = 0; i < V; ++i){
			if(dfsn[i] < 0) getBCC(i);
			if(adj[i].size() == 1) ap.insert(i);
		}

		for(int u: ap){
			cn[C] = BCCNode(u);
			for(auto v: adj[u]){
				int X = get<2>(edge[eNum[P(u, v)]]);
				cn[C].adj.push_back(X);
				cn[X].adj.push_back(C);
			}
			vcNum[u] = C++;
		}

		memset(cParent, -1, sizeof(cParent));
		fill(cDepth, cDepth + C, -1);
		makeTreeByDFS(0, 0);
		for(int j = 0; j < MAX_D-1; ++j){
			for(int i = 0; i < C; ++i)
				if(cParent[i][j] != -1)
					cParent[i][j+1] = cParent[ cParent[i][j] ][j];
		}
	}

	bool query1(int u, int v, int a, int b){
		int e = get<2>(edge[eNum[P(a, b)]]);
		if(cn[e].member.size() > 2) return true;
		u = vcNum[u];
		v = vcNum[v];
		if(u == v) return true;

		int w = getLCA(u, v);
		if(e == w) return false;
		if(getLCA(w, e) == e) return true;
		return (getLCA(u, e) != e && getLCA(v, e) != e);
	}

	bool query2(int u, int v, int a){
		u = vcNum[u];
		v = vcNum[v];
		a = vcNum[a];
		if(!cn[a].isPoint) return true;
		if(u == v) return true;

		int w = getLCA(u, v);
		if(a == w) return false;
		if(getLCA(w, a) == a) return true;
		return (getLCA(u, a) != a && getLCA(v, a) != a);
	}

private:
	int dcnt, dfsn[MAX], cParent[MAX][MAX_D], cDepth[MAX];
	unordered_set<int> ap;
	stack<int> S; // stack of edge numbers

	int getBCC(int curr, int prev = -1){
		int result = dfsn[curr] = dcnt++;
		for(int next: adj[curr]){
			if(next == prev) continue;

			int en = eNum[P(curr, next)];
			if(dfsn[curr] > dfsn[next]) S.push(en);
			if(dfsn[next] >= 0) result = min(result, dfsn[next]);
			else{
				int temp = getBCC(next, curr);
				result = min(result, temp);
				if(temp >= dfsn[curr]){
					cn[C] = BCCNode();
					while(!S.empty()){
						int en2 = S.top(); S.pop();
						int u = get<0>(edge[en2]), v = get<1>(edge[en2]);
						get<2>(edge[en2]) = C;
						cn[C].member.insert(u);
						cn[C].member.insert(v);
						vcNum[u] = vcNum[v] = C;
						if(en == en2) break;
					}
					if(adj[curr].size() > 1) ap.insert(curr);
					++C;
				}
			}
		}
		return result;
	}

	void makeTreeByDFS(int depth, int curr){
		cDepth[curr] = depth;
		for(int next: cn[curr].adj){
			if(cDepth[next] >= 0) continue;
			cParent[next][0] = curr;
			makeTreeByDFS(depth+1, next);
		}
	}

	int getLCA(int u, int v){
		if(cDepth[u] < cDepth[v]) swap(u, v);
		int diff = cDepth[u] - cDepth[v];

		for(int i = 0; diff > 0; ++i){
			if(diff % 2) u = cParent[u][i];
			diff /= 2;
		}
		if(u != v){
			for(int i = MAX_D-1; i >= 0; --i){
				if(cParent[u][i] != -1 && cParent[u][i] != cParent[v][i]){
					u = cParent[u][i];
					v = cParent[v][i];
				}
			}
			u = cParent[u][0];
		}
		return u;
	}
};



int main(){
	BlockCutTree BCT;
	BCT.input();
	BCT.construct();
	int Q;
	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i){
		int o, u, v, a, b;
		bool result;
		scanf("%d %d %d %d", &o, &u, &v, &a);
		if(o == 1){
			scanf("%d", &b);
			result = BCT.query1(u-1, v-1, a-1, b-1);
		}
		else result = BCT.query2(u-1, v-1, a-1);
		puts(result ? "yes" : "no");
	}
}