#include <cstdio>
#include <algorithm>
using namespace std;

int N, pos[12], T;
double dp[13][1<<12];

double balls(int n, int d){ // d: 0(left), 1(right)
	double &ret = dp[n][d];
	if(ret >= 0) return ret;
	if(n == N){
		ret = 0;
		for(int i=0; i<N-1; i++){
			if(d & 1<<i == 0) continue;
			for(int j=i+1; j<N; j++)
				if(d & 1<<j != 0 && pos[j]-pos[i] <= T*2) ret++;
		}
		return ret /= 2;
	}
	return ret = (balls(n+1, d*2)+balls(n+1, d*2+1))/2;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", pos+i);
	sort(pos, pos+N);
	scanf("%d", &T);
	for(int i=0; i<=N; i++)
		fill(dp[i], dp[i]+(1<<N), -1);
	printf("%.10lf\n", balls(0, 0));
}