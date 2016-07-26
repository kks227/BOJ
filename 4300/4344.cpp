#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, score[1000], sum = 0, cnt = 0;
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			scanf("%d", score+i);
			sum += score[i];
		}
		double average = 1.0*sum/N;
		for(int i=0; i<N; i++)
			if(average < score[i]) cnt++;
		printf("%.3f%%\n", 100.0*cnt/N);
	}
}