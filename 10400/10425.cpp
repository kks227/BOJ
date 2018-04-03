#include <cstdio>
#include <cstring>
#include <unordered_map>
using namespace std;
const int MOD = 1000000009;

int main(){
	int f[3] = {1, 2, };
	unordered_map<int, int> fn;
	fn[0] = 0;
	fn[1] = 2;
	fn[2] = 3;
	for(int i=4; i<=100000; i++){
		f[2] = (f[0] + f[1]) % MOD;
		fn[f[2]] = i;
		f[0] = f[1];
		f[1] = f[2];
	}
	
	int T;
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		char F[21002];
		scanf("%s", F);
		int L = strlen(F), pM = 1, H = 0;
		for(int i=L-1; i>=0; i--){
			H = (H + 1LL*pM*(F[i]-'0')) % MOD;
			pM = 10LL*pM % MOD;
		}
		printf("%d\n", fn[H]);
	}
}