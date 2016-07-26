#include <cstdio>
using namespace std;
const int INF = 1000000;

int main(){
	int N, m, M, T, R, result = 0, beat, work = 0;
	scanf("%d %d %d %d %d", &N, &m, &M, &T, &R);
	beat = m;
	while(work < N){
		if(beat+T <= M){
			beat += T;
			work++;
		}
		else{
			beat -= R;
			if(beat < m) beat = m;
		}
		result++;
		if(result == INF) break;
	}
	printf("%d\n", result==INF ? -1 : result);
}