#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t){
		int N;
		scanf("%d", &N);
		printf("Case %d:\n", t);
		for(int i = 1; i <= 6; ++i)
			if(1 <= N-i && N-i <= 6 && i <= N-i) printf("(%d,%d)\n", i, N-i);
	}
}