#include <cstdio>
#include <vector>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> Cycle;

inline long long C2(long long n){ return n*(n-1)/2; }

int main(){
	int N, M;
	bool adj[200][200] = {0};
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u][v] = adj[v][u] = true;
	}

	vector<Cycle> C;
	for(int i=0; i<N; i++)
		for(int j=i+1; j<N; j++)
			for(int k=j+1; k<N; k++)
				if(adj[i][j] && adj[j][k] && adj[k][i])
					C.push_back(Cycle(i, j, k));

	long long sum1 = 0, sum2 = 0;
	int cnt1[200] = {0}, cnt2[200][200] = {0};
	for(auto c: C){
		int u, v, w;
		tie(u, v, w) = c;
		cnt1[u]++; cnt1[v]++; cnt1[w]++;
		cnt2[u][v]++; cnt2[u][w]++; cnt2[v][w]++;
	}
	for(int i=0; i<N; i++){
		sum1 += C2(cnt1[i]);
		for(int j=i+1; j<N; j++)
			sum2 += C2(cnt2[i][j]);
	}
	printf("%lld\n", sum1 - sum2*2);
}