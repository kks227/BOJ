#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 200000;

struct UnionFind{
	int uf[MAX];
	UnionFind(){ fill(uf, uf+MAX, -1); }
	int find(int a){
		if(uf[a] < 0) return a;
		return uf[a] = find(uf[a]);
	}
	bool merge(int a, int b){
		a = find(a);
		b = find(b);
		if(a == b) return false;
		uf[b] = a;
		return true;
	}
};

int main(){
	int N, Q, p[MAX], q[MAX*2][3];
	UnionFind UF;
	scanf("%d %d", &N, &Q);
	Q += N-1;
	for(int i=1; i<N; i++){
		scanf("%d", p+i);
		p[i]--;
	}
	for(int i=0; i<Q; i++){
		scanf("%d %d", &q[i][0], &q[i][1]);
		q[i][1]--;
		if(q[i][0] == 1){
			scanf("%d", &q[i][2]);
			q[i][2]--;
		}
	}

	stack<bool> result;
	for(int i=Q-1; i>=0; i--){
		if(q[i][0] == 0) UF.merge(q[i][1], p[q[i][1]]);
		else{
			int u = UF.find(q[i][1]), v = UF.find(q[i][2]);
			result.push(u == v);
		}
	}
	while(!result.empty()){
		puts(result.top() ? "YES" : "NO");
		result.pop();
	}
}