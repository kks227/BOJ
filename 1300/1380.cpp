#include <cstdio>
using namespace std;

int main(){
	for(int t=1; ; t++){
		int N;
		scanf("%d", &N);
		if(N == 0) break;

		char name[100][61];
		getchar();
		for(int i=0; i<N; i++)
			gets(name[i]);
		int cnt[100] = {0};
		for(int i=0; i<N*2-1; i++){
			int n;
			char c;
			scanf("%d %c", &n, &c);
			cnt[n-1]++;
		}
		for(int i=0; i<N; i++)
			if(cnt[i] == 1) printf("%d %s\n", t, name[i]);
	}
}