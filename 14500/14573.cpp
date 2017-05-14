#include <cstdio>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;

inline int mod(long long k){
	if(k >= 0) return k % MOD;
	return (k + (-k/MOD+1)*MOD) % MOD;
}

int main(){
	int a[1000001] = {0, 1, 1}, m = 4, d = 2, r[1000001] = {0, 1, 2};
	for(int i=3; i<=1000000; i++){
		a[i] = 1LL*a[i-1]*m % MOD;
		r[i] = (r[i-1] + a[i]) % MOD;
		m = (m+d) % MOD;
		d = (d*2) % MOD;
	}

	int Q;
	scanf("%d", &Q);
	for(int q=0; q<Q; q++){
		int a1, op;
		scanf("%d %d", &op, &a1);
		if(op == 1){
			int i, j;
			scanf("%d %d", &i, &j);
			printf("%d\n", 1LL*a1*a[min(i, j)] % MOD);
		}
		else if(op == 2){
			int i, j;
			scanf("%d %d", &i, &j);
			int k = max(i, j), result = 0;
			if(k <= 2) result = 0;
			else if(k == 3) result = 2;
			else result = k-1;
			while(a1%2 == 0){
				result++;
				a1 /= 2;
			}
			printf("%d\n", result);
		}
		else if(op == 3){
			int i, j;
			scanf("%d %d", &i, &j);
			printf("%d\n", mod(1LL*a1 * mod(r[j]-r[i-1]) ) );
		}
		else{
			int k;
			scanf("%d", &k);
			printf("%d\n", mod(1LL*a1*a[k]));
		}
	}
}