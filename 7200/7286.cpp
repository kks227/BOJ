#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, cnt[1000] = {0};
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			char c;
			int s, e;
			scanf(" %c %d %d", &c, &s, &e);
			for(int j=s; j<e; j++) cnt[j]++;
		}
		for(int i=0; i<1000; i++)
			if(cnt[i] > 0) putchar(cnt[i]-1+'A');
		puts("");
	}
}