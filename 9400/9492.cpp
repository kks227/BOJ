#include <cstdio>
using namespace std;

int main(){
	while(1){
		int N, p, q, cnt = 0;
		char word[1000][81];
		scanf("%d", &N);
		if(N == 0) break;
		for(int i=0; i<N; i++)
			scanf("%s", word[i]);
		p = 0;
		q = N%2 ? N/2+1 : N/2;
		while(cnt < N){
			puts(word[p++]);
			cnt++;
			if(q < N){
				puts(word[q++]);
				cnt++;
			}
		}
	}
}