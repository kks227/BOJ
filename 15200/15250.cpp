#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 131;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		char S[1000001];
		scanf("%s", S);
		int L = strlen(S);

		int result = 0, s = 0, e = L;
		while(s < e){
			bool success = false;
			int LH = 0, RH = 0, p2 = 1;
			for(int i=1; s+i<=e-i; i++){
				LH = (2*LH + S[s+i-1]) % MOD;
				RH = (RH + p2*S[e-i]) % MOD;
				p2 = p2*2 % MOD;
				if(LH == RH){
					success = true;
					for(int j=0; j<i; j++){
						if(S[s+j] != S[e-i+j]){
							success = false;
							break;
						}
					}
					if(success){
						result += 2;
						s += i;
						e -= i;
						break;
					}
				}
			}
			if(!success){
				result++;
				break;
			}
		}
		printf("%d\n", result);
	}
}