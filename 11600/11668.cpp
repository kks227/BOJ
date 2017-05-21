#include <cstdio>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 1000;
typedef pair<int, int> P;

int dcnt, SN, dfsn[MAX*2], sn[MAX*2];
vector<int> adj[MAX*2];
bool finished[MAX*2];
stack<int> S;

inline int cross(int x1, int y1, int x2, int y2){
	return x1*y2 - x2*y1;
}

inline int ccw(int x1, int y1, int x2, int y2, int x3, int y3){
	int temp = cross(x2-x1, y2-y1, x3-x1, y3-y1);
	if(temp == 0) return 0;
	return (temp > 0 ? 1 : -1);
}

inline bool intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	int p = ccw(x1, y1, x2, y2, x3, y3);
	int q = ccw(x1, y1, x2, y2, x4, y4);
	if(p && q && p == q) return false;
	p = ccw(x3, y3, x4, y4, x1, y1);
	q = ccw(x3, y3, x4, y4, x2, y2);
	if(p && q && p == q) return false;
	return true;
}

inline int oppo(int n){
	return n%2 ? n-1 : n+1;
}

int dfs(int curr){
	dfsn[curr] = ++dcnt;
	S.push(curr);
	int result = dfsn[curr];
	for(int next: adj[curr]){
		if(dfsn[next] == 0) result = min(result, dfs(next));
		else if(!finished[next]) result = min(result, dfsn[next]);
	}
	if(result >= dfsn[curr]){
		sn[curr] = SN++;
		while(1){
			int family = S.top();
			S.pop();
			finished[family] = true;
			if(family == curr) break;
			sn[family] = sn[curr];
		}
	}
	return result;
}



int main(){
	int M, N, w[1000], x1[1000], y1[1000], x2[1000], y2[1000];
	scanf("%d %d", &M, &N);
	for(int i=0; i<M; i++)
		scanf("%d %d", x1+i, y1+i);
	for(int i=0; i<N; i++){
		scanf("%d %d %d", w+i, x2+i, y2+i);
		w[i]--;
		for(int j=0; j<i; j++){
			if(w[i] == w[j]) continue;
			if(intersect(x1[w[i]], y1[w[i]], x2[i], y2[i], x1[w[j]], y1[w[j]], x2[j], y2[j])){
				int p = i*2, q = j*2;
				adj[oppo(q)].push_back(p);
				adj[oppo(p)].push_back(q);
				adj[q].push_back(oppo(p));
				adj[p].push_back(oppo(q));
			}
		}
	}

	for(int i=0; i<N*2; i++)
		if(dfsn[i] == 0) dfs(i);
	bool result = true;
	for(int i=0; i<N; i++){
		if(sn[i*2] == sn[i*2+1]){
			result = false;
			break;
		}
	}
	puts(result ? "possible" : "impossible");
}