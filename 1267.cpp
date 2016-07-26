#include <cstdio>
using namespace std;

int main(){
	int N, Y=0, M=0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int time;
		scanf("%d", &time);
		Y += (time/30+1)*10;
		M += (time/60+1)*15;
	}
	if(Y == M) printf("Y M %d\n", Y);
	else if(Y < M) printf("Y %d\n", Y);
	else printf("M %d\n", M);
}