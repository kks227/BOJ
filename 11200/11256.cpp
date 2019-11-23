#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int J, N, V[MAX];
		scanf("%d %d", &J, &N);
		for(int i = 0; i < N; ++i){
			int r, c;
			scanf("%d %d", &r, &c);
			V[i] = r*c;
		}
		sort(V, V+N);
		for(int i = N-1; i >= 0; --i){
			if(J <= V[i]){
				printf("%d\n", N-i);
				break;
			}
			J -= V[i];
		}
	}
}