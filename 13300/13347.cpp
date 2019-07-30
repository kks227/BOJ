#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 20;
const int LOOPS = 1e5;

int main(){
	int N, M;
	vector<int> adj[MAX];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	double p[2][MAX] = {1,}, result = 0;
	bool t = false;
	for(int k = 1; k <= LOOPS; ++k){
		for(int i = 0; i < N; ++i){
			if(p[t][i] == 0 || adj[i].empty()) continue;
			for(int j: adj[i])
				p[!t][j] += p[t][i] / adj[i].size();
			p[t][i] = 0;
		}
		t = !t;
		result += k*p[t][N-1];
		p[t][N-1] = 0;
	}
	printf("%.6lf\n", result);
}