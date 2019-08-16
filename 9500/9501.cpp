#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N, D, result = 0;
		scanf("%d %d", &N, &D);
		for(int i = 0; i < N; ++i){
			int v, f, c;
			scanf("%d %d %d", &v, &f, &c);
			if(v*f >= D*c) ++result;
		}
		printf("%d\n", result);
	}
}