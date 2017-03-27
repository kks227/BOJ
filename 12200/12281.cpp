#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int N, A = 0, B = 0, p[MAX], q[MAX];
		bool owner[MAX];
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			int val;
			scanf("%d", &val);
			if(owner[i] = val%2) p[A++] = val;
			else q[B++] = val;
		}
		sort(p, p+A);
		sort(q, q+B);
		printf("Case #%d:", t);
		A = 0;
		for(int i=0; i<N; i++)
			printf(" %d", (owner[i] ? p[A++] : q[--B]));
		puts("");
	}
}