#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M, NtoR[500], RtoN[500], in[500] = {0};
		bool swapped[500][500] = {0};
		vector<int> adj[500];
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			scanf("%d", RtoN+i);
			RtoN[i]--;
			NtoR[RtoN[i]] = i;
		}
		scanf("%d", &M);
		for(int i=0; i<M; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			a--; b--;
			if(NtoR[a] > NtoR[b]) swap(a, b);
			adj[b].push_back(a);
			in[a]++;
			swapped[a][b] = true;
		}
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(i == j) continue;
				if(NtoR[i] < NtoR[j] && !swapped[i][j]){
					adj[i].push_back(j);
					in[j]++;
				}
			}
		}

		queue<int> Q;
		for(int i=0; i<N; i++)
			if(in[i] == 0) Q.push(i);
		bool impossible = false, ambiguous = false;
		int result[500];
		for(int k=0; k<N; k++){
			if(Q.empty()){
				impossible = true;
				break;
			}
			if(Q.size() > 1) ambiguous = true;

			int curr = Q.front();
			Q.pop();
			result[k] = curr;
			for(int next: adj[curr])
				if(--in[next] == 0) Q.push(next);
		}
		if(impossible) puts("IMPOSSIBLE");
		else if(ambiguous) puts("?");
		else{
			for(int i=0; i<N; i++)
				printf("%d ", result[i]+1);
			puts("");
		}
	}
}