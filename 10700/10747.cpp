#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1000000007;
const int P = 2;

int main(){
	char S[1000001], T[1000001], R[1000001] = {0};
	scanf("%s %s", S, T);
	int L = strlen(T), pos = 0;
	int TH = 0, H[1000001] = {0}, pTL = 1;
	for(int i=0; i<L; i++){
		TH = (1LL*TH*P + T[i]) % MOD;
		pTL = 1LL*pTL*P % MOD;
	}
	for(int i=0; S[i]; i++){
		R[pos++] = S[i];
		H[pos] = (1LL*H[pos-1]*P + S[i]) % MOD;
		if(pos > L) H[pos] = (H[pos] - 1LL*R[pos-L-1]*pTL%MOD + MOD) % MOD;
		if(H[pos] == TH && pos >= L){
			bool same = true;
			for(int j=0; j<L; j++){
				if(T[j] != R[pos-L+j]){
					same = false;
					break;
				}
			}
			if(same) pos -= L;
		}
	}
	R[pos] = '\0';
	puts(R);
}