#include <cstdio>
#include <cassert>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 100000;
typedef pair<int, int> P;

class SegTree{
public:
	void construct(int vn, vector<int> &v, vector<P> pos[]){
		cnt = v.size();
		size = 2;
		for(; size < cnt*2; size *= 2);
		A.resize(size);
		B.resize(cnt);
		for(int i = 0; i < cnt; ++i){
			A[size/2 + i] = 1;
			B[i] = v[i];
			pos[v[i]].push_back(P(vn, i));
		}
		for(int i = cnt; i < size/2; ++i)
			A[size/2 + i] = 0;
		for(int i = size/2-1; i > 0; --i)
			A[i] = A[i*2] + A[i*2+1];
	}

	int getSize(){ return cnt; }

	void erase(int k){
		B[k] = -1;
		k += size/2;
		A[k] = 0;
		while(k > 1){
			k /= 2;
			A[k] = A[k*2] + A[k*2+1];
		}
		--cnt;
	}

	int getMedian(){
		int node = 1, k = cnt/2;
		while(node < size/2){
			if(A[node*2] <= k){
				k -= A[node*2];
				node = node*2 + 1;
			}
			else node *= 2;
		}
		return B[node - size/2];
	}

	int getSmallest(){
		int node = 1;
		while(node < size/2){
			if(A[node*2] > 0) node *= 2;
			else node = node*2 + 1;
		}
		return B[node - size/2];
	}

private:
	int cnt, size;
	vector<int> A, B;
};

class Graph{
public:
	void input(){
		scanf("%d %d", &N, &M);
		for(int i = 0; i < M; ++i){
			int u, v;
			scanf("%d %d", &u, &v);
			--u; --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}

	void solve(){
		for(int i = 0; i < N; ++i){
			sort(adj[i].begin(), adj[i].end());
			adj[i].resize(unique(adj[i].begin(), adj[i].end()) - adj[i].begin());
			ST[i].construct(i, adj[i], pos);
		}
		fill(visited, visited+N, false);
		mfs(0);
	}

private:
	int N, M;
	vector<int> adj[MAX];
	vector<P> pos[MAX];
	SegTree ST[MAX];
	bool visited[MAX];

	void mfs(int curr){
		printf("%d ", curr+1);
		visited[curr] = true;
		for(auto &p: pos[curr])
			ST[p.first].erase(p.second);
		while(1){
			int k = ST[curr].getSize();
			if(k == 0) break;
			int next = (k%2 ? ST[curr].getMedian() : ST[curr].getSmallest());
			mfs(next);
		}
	}
};



int main(){
	Graph G;
	G.input();
	G.solve();
}