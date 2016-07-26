#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node{
	int dif, small, k;
	bool team;
	Node(): Node(0, 0, 0){}
	Node(int k1, int d1, int d2){
		k = k1;
		small = min(d1, d2);
		dif = abs(d1 - d2);
		team = d1 > d2;
	}
	bool operator <(const Node &A){
		return dif < A.dif;
	}
};

int main(){
	while(1){
		int N, b[2];
		scanf("%d %d %d", &N, &b[0], &b[1]);
		if(N == 0) break;

		Node node[1000];
		for(int i=0; i<N; i++){
			int K, Da, Db;
			scanf("%d %d %d", &K, &Da, &Db);
			node[i] = Node(K, Da, Db);
		}

		int result = 0;
		sort(node, node+N);
		for(int i=N-1; i>=0; i--){
			int p = min(b[node[i].team], node[i].k);
			result += p * node[i].small;
			b[node[i].team] -= p;
			int q = node[i].k - p;
			result += q * (node[i].small + node[i].dif);
			b[!node[i].team] -= q;
		}
		printf("%d\n", result);
	}
}