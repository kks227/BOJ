#include <cstdio>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
const int MAX = 1000001;
const int MAX_P = 100001;

int main(){
	bool np[MAX_P] = {true, true,};
	for(int i = 4; i <= MAX_P; i += 2)
		np[i] = true;
	for(int i = 3; i <= MAX_P; i += 2){
		if(np[i]) continue;
		for(long long j = 1LL*i*i; j <= MAX_P; j += i*2)
			np[j] = true;
	}
	function<int(int)> f[4] = {
		[](int n){ return n/2; },
		[](int n){ return n/3; },
		[](int n){ return min(n+1, MAX-1); },
		[](int n){ return max(n-1, 0); }
	};

	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N, A, B;
		scanf("%d %d %d", &N, &A, &B);

		queue<int> Q;
		Q.push(N);
		bool visited[MAX] = {false,};
		visited[N] = true;
		int result = -1;
		for(int i = 0; result < 0 && !Q.empty(); ++i){
			int qSize = Q.size();
			for(int j = 0; j < qSize; ++j){
				int curr = Q.front(); Q.pop();
				if(A <= curr && curr <= B && !np[curr]){
					result = i;
					break;
				}
				for(int k = 0; k < 4; ++k){
					int next = f[k](curr);
					if(!visited[next]){
						visited[next] = true;
						Q.push(next);
					}
				}
			}
		}
		printf("%d\n", result);
	}
}