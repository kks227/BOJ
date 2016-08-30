#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 10000;
const int S = 1;
const int E = 2;
const int INF = 1000000000;

struct Edge{
	int to, c, f;
	Edge *dual;
	Edge(): Edge(-1, 0){}
	Edge(int to1, int c1): to(to1), c(c1), f(0), dual(nullptr){}
	void addFlow(int f1){
		f += f1;
		dual->f -= f1;
	}
};

int main(){
	for(int t=1; ; t++){
		int K, N;
		scanf("%d %d", &K, &N);
		if(K == 0) break;

		vector<Edge*> adj[MAX];
		for(int i=0; i<N; i++){
			Edge *e1, *e2;
			if(i >= 2){
				e1 = new Edge(i*2+1, 1);
				e2 = new Edge(i*2, 0);
				e1->dual = e2;
				e2->dual = e1;
				adj[i*2].push_back(e1);
				adj[i*2+1].push_back(e2);
			}

			while(1){
				char whitespace;
				int j;
				scanf("%d%c", &j, &whitespace);
				j--;
				e1 = new Edge(j*2, 1);
				e2 = new Edge(i*2+1, 0);
				e1->dual = e2;
				e2->dual = e1;
				adj[i*2+1].push_back(e1);
				adj[j*2].push_back(e2);
				if(whitespace == '\n') break;
			}
		}

		bool impossible = false;
		for(int k=0; k<K; k++){
			int prev[MAX];
			fill(prev, prev+MAX, -1);
			Edge *path[MAX] = {nullptr};
			queue<int> Q;
			Q.push(S);

			while(!Q.empty() && prev[E] == -1){
				int curr = Q.front();
				Q.pop();
				for(Edge *e: adj[curr]){
					int next = e->to;
					if(prev[next] == -1 && e->c - e->f > 0){
						prev[next] = curr;
						path[next] = e;
						Q.push(next);
					}
				}
			}
			if(prev[E] == -1){
				impossible = true;
				break;
			}

			for(int i=E; i!=S; i=prev[i])
				path[i]->addFlow(1);
		}
		printf("Case %d:\n", t);
		if(impossible) puts("Impossible");
		else{
			for(int k=0; k<K; k++){
				int prev = -2, curr = S;
				while(curr != E){
					if(prev/2 != curr/2) printf("%d ", curr/2+1);
					prev = curr;
					for(Edge *e: adj[curr]){
						int next = e->to;
						if(e->f == 1){
							e->f = 0;
							curr = next;
							break;
						}
					}
				}
				printf("%d\n", E/2+1);
			}
		}
		puts("");
	}
}