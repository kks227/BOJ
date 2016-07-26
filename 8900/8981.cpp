#include <cstdio>
using namespace std;

int main(){
	int N, Y[30], X[30] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", Y+i);

	int from = 0, cnt;
	bool fail = false;
	for(int i=0; i<N; i++){
		cnt = 0;
		while(X[from] != 0){
			from = (from+1) % N;
			if(++cnt > N){
				fail = true;
				break;
			}
		}
		if(fail) break;
		X[from] = Y[i];
		from = (from+Y[i]) % N;
	}
	if(fail) puts("-1");
	else{
		printf("%d\n", N);
		for(int i=0; i<N; i++)
			printf("%d ", X[i]);
	}
}