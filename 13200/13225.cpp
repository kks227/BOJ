#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N, cnt = 0;
		scanf("%d", &N);
		for(int i = 1; i <= N; ++i)
			if(N%i == 0) ++cnt;
		printf("%d %d\n", N, cnt);
	}
}