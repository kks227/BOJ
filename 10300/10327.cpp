#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_F = 50;
const long long INF = 1e18;

inline int sign(int k){ return k%2 ? -1 : 1; }

int main(){
	long long f[MAX_F] = {0, 1};
	for(int i=2; i<MAX_F; i++)
		f[i] = f[i-1] + f[i-2];

	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N;
		scanf("%d", &N);
		long long a = 1, b = N-1;
		for(int i=2; i<MAX_F; i++){
			if(N%f[i]) continue;
			long long x = N/f[i], y = N/f[i];
			if(y < b || y == b && x < a){
				a = x;
				b = y;
			}
		}

		for(int i=2; f[i+1] < N; i++){
			long long ks = sign(i-1)*N * f[i-1]/f[i+1] + 1;
			if(i%2 == 0 && N*f[i-1]%f[i+1]) ks--;
			long long ke = sign(i-1)*N * f[i]/f[i+2];
			if(i%2 == 0 && N*f[i]%f[i+2]) ke--;
			if(ks > ke) continue;
			long long x = sign(i)*N * f[i-1] + ke * f[i+1];
			long long y = sign(i-1)*N * f[i-2] - ke * f[i];
			if(y < b || y == b && x < a){
				a = x;
				b = y;
			}
		}
		printf("%lld %lld\n", a, b);
	}
}