#include <cstdio>
using namespace std;

inline int C2I(char c){ return (c == 'S' ? 0 : (c == 'R' ? 1 : 2)); }

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N;
		char S[10][31];
		bool remain[10];
		scanf("%d", &N);
		for(int i = 0; i < N; ++i){
			scanf("%s", S[i]);
			remain[i] = true;
		}
		for(int k = 0; S[0][k]; ++k){
			int cnt[3] = {0,};
			for(int i = 0; i < N; ++i)
				if(remain[i]) ++cnt[C2I(S[i][k])];
			for(int j = 0; j < 3; ++j){
				if(cnt[j] != 0) continue;
				int win = (j+2)%3, lose = (j+1)%3;
				if(cnt[win] == 0 || cnt[lose] == 0) break;
				for(int i = 0; i < N; ++i)
					if(C2I(S[i][k]) == lose) remain[i] = false;
				break;
			}
		}
		int r1 = -1, r2 = 0;
		for(int i = 0; i < N; ++i){
			if(remain[i]){
				if(r1 == -1) r1 = i;
				else{
					r2 = 1;
					break;
				}
			}
		}
		if(r2) puts("0");
		else printf("%d\n", r1+1);
	}
}