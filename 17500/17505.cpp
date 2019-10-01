#include <cstdio>
using namespace std;
const int MAX = 314159;

int main(){
	int N, p[MAX];
	long long K;
	scanf("%d %lld", &N, &K);
	int s = 0, e = N-1;
	for(int i = N; i > 0; --i){
		if(K >= i-1){
			p[s++] = i;
			K -= i-1;
		}
		else p[e--] = i;
	}
	for(int i = 0; i < N; ++i)
		printf("%d ", p[i]);
}