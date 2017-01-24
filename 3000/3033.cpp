#include <cstdio>
#include <vector>
using namespace std;
const int MOD = 100003;
const int P = 2;

inline int mod(long long n){
	if(n >= 0) return n % MOD;
	return ((-n/MOD+1)*MOD + n) % MOD;
}

int main(){
	int L;
	char W[200001];
	scanf("%d %s", &L, W);

	int lo = 0, hi = L;
	while(lo+1 < hi){
		int mid = (lo+hi)/2;

		int H = 0, power = 1;
		vector<int> pos[MOD];
		bool found = false;
		for(int i=0; i<=L-mid; i++){
			if(i == 0){
				for(int j=0; j<mid; j++){
					H = mod(H + 1LL*W[mid-1-j]*power);
					if(j < mid-1) power = mod(1LL*power*P);
				}
			}
			else H = mod(P*(H - 1LL*W[i-1]*power) + W[i+mid-1]);

			if(!pos[H].empty()){
				for(int p: pos[H]){
					bool same = true;
					for(int j=0; j<mid; j++){
						if(W[i+j] != W[p+j]){
							same = false;
							break;
						}
					}
					if(same){
						found = true;
						break;
					}
				}
			}
			if(found) break;
			else pos[H].push_back(i);
		}
		(found ? lo : hi) = mid;
	}
	printf("%d\n", lo);
}