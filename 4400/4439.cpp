#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int N, M, R[100][3];
bool spin[23];

bool dfs(int r){
	if(r == N+1){
		for(int i=0; i<M; i++){
			bool fail = true;
			for(int j=0; j<3; j++){
				int k = abs(R[i][j]);
				if(spin[k] == (R[i][j] > 0)){
					fail = false;
					break;
				}
			}
			if(fail) return false;
		}
		return true;
	}

	if(dfs(r+1)) return true;
	spin[r] = true;
	if(dfs(r+1)) return true;
	spin[r] = false;
	return false;
}

int main(){
	int T, dummy;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d %d", &N, &M);
		bool nullRune = false, missingRing = false, repeatedRing = false;
		for(int i=0; i<M; i++){
			for(int j=0; j<3; j++){
				scanf("%d", &R[i][j]);
				if(R[i][j] == 0) nullRune = true;
				if(abs(R[i][j]) > N) missingRing = true;
				for(int k=0; k<j; k++)
					if(abs(R[i][j]) == abs(R[i][k])) repeatedRing = true;
			}
			scanf("%d", &dummy);
		}
		if(nullRune) puts("INVALID: NULL RING");
		else if(missingRing) puts("INVALID: RING MISSING");
		else if(repeatedRing) puts("INVALID: RUNE CONTAINS A REPEATED RING");
		else puts(dfs(1) ? "RUNES SATISFIED!" : "RUNES UNSATISFIABLE! TRY ANOTHER GATE!");
		fill(spin, spin+23, false);
	}
}