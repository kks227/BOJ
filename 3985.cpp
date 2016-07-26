#include <cstdio>
using namespace std;

int main(){
	int L, N, roll[1000]={0}, result=-1, val=-1;
	scanf("%d %d", &L, &N);
	for(int i=1; i<=N; i++){
		int P, K;
		scanf("%d %d", &P, &K);
		if(val < K-P+1){
			val = K-P+1;
			result = i;
		}
		for(int j=P; j<=K; j++)
			if(roll[j] == 0) roll[j] = i;
	}
	printf("%d\n", result);

	result = -1; val = -1;
	for(int i=1; i<=N; i++){
		int cnt = 0;
		for(int j=0; j<L; j++)
			if(roll[j] == i) cnt++;
		if(val < cnt){
			val = cnt;
			result = i;
		}
	}
	printf("%d\n", result);
}