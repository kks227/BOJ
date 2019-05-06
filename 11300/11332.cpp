#include <cstdio>
using namespace std;

int main(){
	int C;
	scanf("%d", &C);
	for(int t = 0; t < C; ++t){
		char S[7] = "";
		int N, T, L;
		scanf("%s %d %d %d", S, &N, &T, &L);
		L *= 1e8;
		bool tle = false;
		if(S[3] == '!'){
			long long cnt = T;
			for(int i = 1; i <= N; ++i){
				cnt *= i;
				if(cnt > L){
					tle = true;
					break;
				}
			}
		}
		else if(S[2] == '2'){
			long long cnt = T;
			for(int i = 0; i < N; ++i){
				cnt <<= 1;
				if(cnt > L){
					tle = true;
					break;
				}
			}
		}
		else{
			long long cnt = N;
			if(S[4] == '2') cnt *= N;
			else if(S[4] == '3') cnt *= 1LL*N*N;
			if(cnt > L) tle = true;
			else if(cnt*T > L) tle = true;
		}
		puts(tle ? "TLE!" : "May Pass.");
	}
}