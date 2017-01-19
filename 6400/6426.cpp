#include <cstdio>
#include <map>
using namespace std;

int main(){
	for(int t=1; ; t++){
		int Z, I, M, L;
		scanf("%d %d %d %d", &Z, &I, &M, &L);
		if(M == 0) break;

		map<int, int> S;
		S[L] = 0;
		for(int i=1; ; i++){
			L = (Z*L+I) % M;
			if(S.find(L) != S.end()){
				printf("Case %d: %d\n", t, i-S[L]);
				break;
			}
			S[L] = i;
		}
	}
}