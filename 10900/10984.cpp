#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, sum = 0;
		double ave = 0;
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			int C;
			double G;
			scanf("%d %lf", &C, &G);
			sum += C;
			ave += G*C;
		}
		printf("%d %.1lf\n", sum, ave/sum);
	}
}