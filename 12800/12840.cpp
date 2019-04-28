#include <cstdio>
using namespace std;
const int MOD = 60*60*24;

int main(){
	int h, m, s, Q;
	scanf("%d %d %d %d", &h, &m, &s, &Q);
	int t = h*3600 + m*60 + s;
	for(int i = 0; i < Q; ++i){
		int q, c;
		scanf("%d", &q);
		if(q == 3) printf("%d %d %d\n", t/3600, t%3600/60, t%60);
		else{
			scanf("%d", &c);
			if(q == 1) t = (t + c) % MOD;
			else t = (t - c%MOD + MOD) % MOD;
		}
	}
}