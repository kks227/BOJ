#include <cstdio>
#include <algorithm>
using namespace std;
const int START = 1048576;
const int SIZE = START * 2;
const int MOD = 1000000007;

int ST[SIZE];

void update(int node){
	if(node == 1) return;
	ST[node] = 1LL * ST[node*2] * ST[node*2+1] % MOD;
	update(node/2);
}

int product(int node, int ns, int ne, int s, int e){
	if(ne <= s || e <= ns) return 1;
	if(s <= ns && ne <= e) return ST[node];
	int mid = (ns + ne)/2;
	return 1LL * product(node*2, ns, mid, s, e) * product(node*2+1, mid, ne, s, e) % MOD;
}

int main(){
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	fill(ST, ST+SIZE, 1);
	for(int i=0; i<N; i++){
		scanf("%d", ST+START+i);
		update((START+i)/2);
	}
	for(int i=0; i<M+K; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		b--;
		if(a == 1){
			ST[START+b] = c;
			update((START+b)/2);
		}
		else printf("%d\n", product(1, 0, START, b, c));
	}
}