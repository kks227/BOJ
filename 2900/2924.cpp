#include <cstdio>
using namespace std;

int ccnt, next[500000], cn[500000], cs[500000];
bool visited[500000];

void dfs(int curr){
	visited[curr] = true;
	cn[curr] = ccnt;
	cs[cn[curr]]++;
	if(!visited[next[curr]]) dfs(next[curr]);
}

long long gcd(long long p, long long q){
	while(q){
		long long r = p%q;
		p = q;
		q = r;
	}
	return p;
}

long long lcm(long long p, long long q){
	return p/gcd(p, q)*q;
}



int main(){
	int N, C, D;
	long long A, B;
	scanf("%d %lld %lld %d %d", &N, &A, &B, &C, &D);
	for(int i=0; i<N; i++){
		scanf("%d", next+i);
		next[i]--;
	}
	for(int i=0; i<N; i++){
		if(!visited[i]){
			dfs(i);
			ccnt++;
		}
	}

	long long g = 1;
	for(int i=C; i<N-D; i++)
		g = lcm(g, cs[cn[i]]);
	printf("%lld\n", (B-1)/g+1 - (A==1 ? 0 : (A-2)/g+1));
}