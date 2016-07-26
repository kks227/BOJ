#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Stick{
	int x[2], len;
	Stick(): Stick(0, 0, 0){}
	Stick(int a, int b, int len1): len(len1){
		x[0] = a;
		x[1] = b;
	}
	bool operator <(const Stick& A)const{
		if(x[0] != A.x[0]) return x[0] < A.x[0];
		return x[1] < A.x[1];
	}
};

int main(){
	int N, L, t[100000], d[100000];
	Stick stick[100000];
	scanf("%d %d", &N, &L);
	for(int i=0; i<N; i++){
		scanf("%d %d", t+i, d+i);
		stick[i] = Stick(t[i], d[i], abs(t[i]-d[i])+L);
	}
	sort(t, t+N);
	sort(d, d+N);
	for(int i=0; i<N; i++){
		stick[i].x[0] = lower_bound(t, t+N, stick[i].x[0]) - t;
		stick[i].x[1] = lower_bound(d, d+N, stick[i].x[1]) - d;
	}
	sort(stick, stick+N);

	long long dp[100000][2] = {0}, result = 0;
	for(int i=0; i<N; i++){
		long long T = dp[stick[i].x[0]][0] + stick[i].len;
		long long D = dp[stick[i].x[1]][1] + stick[i].len;
		dp[stick[i].x[0]][0] = max(dp[stick[i].x[0]][0], D);
		dp[stick[i].x[1]][1] = max(dp[stick[i].x[1]][1], T);
		result = max(max(T, D), result);
	}
	printf("%lld\n", result);
}