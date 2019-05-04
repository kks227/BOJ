#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int q;
		scanf("%d", &q);
		if(q == 1){
			unsigned long long v = 0;
			for(int i = 0; i < 8; ++i){
				int k;
				scanf(i == 7 ? "%d" : "%d.", &k);
				v = v*256 + k;
			}
			printf("%llu\n", v);
		}
		else{
			unsigned long long v;
			scanf("%llu", &v);
			int k[8];
			for(int i = 0; i < 8; ++i){
				k[7-i] = v % 256;
				v /= 256;
			}
			for(int i = 0; i < 8; ++i)
				printf("%d%c", k[i], (i == 7 ? '\n' : '.'));
		}
	}
}