#include <cstdio>
#include <vector>
#include <unordered_set>
#include <map>
#include <algorithm>
using namespace std;
const int MAX = 2000;
const int INF = 1e9 + 1;

class Graph{
public:
	void input(){
		scanf("%d %d", &L, &K);
		M = L-K+1;
		N = 0;
		map<vector<int>, int> H;
		int indegree[MAX] = {0,}, outdegree[MAX] = {0,};
		for(int i = 0; i < M; ++i){
			vector<int> p(K);
			for(int j = 0; j < K; ++j)
				scanf("%d", &p[j]);
			vector<int> v1(p), v2;
			v1.pop_back();
			v2.insert(v2.begin(), p.begin()+1, p.end());
			auto iter = H.find(v1);
			if(iter == H.end()){
				P[N] = v1;
				H[v1] = N++;
			}
			iter = H.find(v2);
			if(iter == H.end()){
				P[N] = v2;
				H[v2] = N++;
			}
			int j = H[v1], k = H[v2];
			++indegree[k];
			++outdegree[j];
			adj[j].insert(k);
		}

		A = B = -1;
		for(int i = 0; i < N; ++i){ // a virtual edge A->B
			if(indegree[i] == outdegree[i] + 1) A = i;
			if(indegree[i] == outdegree[i] - 1) B = i;
		}
		if(A != -1) adj[A].insert(B);
	}

	void solve(){
		EPath.clear();
		Eulerian(0);
		reverse(EPath.begin(), EPath.end());

		vector<int> result;
		if(A == -1) result.insert(result.end(), EPath.begin(), EPath.end() - 1);
		else{
			for(int i = 0; ; ++i){
				if(EPath[i] == A && EPath[i+1] == B){
					result.insert(result.end(), EPath.begin() + i+1, EPath.end() - 1);
					result.insert(result.end(), EPath.begin(), EPath.begin() + i+1);
					break;
				}
			}
		}

		for(int i = 0; i < K-1; ++i)
			printf("%d ", P[result[0]][i]);
		for(int i = 1; i < M+1; ++i)
			printf("%d ", P[result[i]][K-2]);
	}

private:
	int K, L, M, N, A, B;
	vector<int> P[MAX], EPath;
	unordered_multiset<int> adj[MAX];

	void Eulerian(int curr){
		while(!adj[curr].empty()){
			int next = *adj[curr].begin();
			adj[curr].erase(adj[curr].begin());
			Eulerian(next);
		}
		EPath.push_back(curr);
	}
};



int main(){
	Graph G;
	G.input();
	G.solve();
}