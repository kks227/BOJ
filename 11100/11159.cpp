#include <cstdio>
#include <queue>
using namespace std;
const int MOD = 1000000007;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, a[10000], w[10000], cost[10000] = {0}, in[10000] = {0};
		scanf("%d", &N);
		for(int i=1; i<N; i++){
			scanf("%d", a+i);
			in[a[i]]++;
		}
		for(int i=1; i<N; i++)
			scanf("%d", w+i);

		queue<int> Q;
		for(int i=0; i<N; i++){
			if(in[i] == 0){
				Q.push(i);
				cost[i] = 1;
			}
		}
		while(!Q.empty()){
			int curr = Q.front();
			Q.pop();
			if(curr == 0) break;

			int next = a[curr];
			cost[next] = (cost[next] + 1LL*cost[curr]*w[curr]) % (MOD*2);
			if(--in[next] == 0) Q.push(next);
		}
		if(cost[0]%2) printf("%d\n", cost[0]%MOD);
		else puts("FREAK OUT");
	}
}