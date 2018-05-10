#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	int N, M;
	double p[1000], q[2000];
	scanf("%d %d", &N, &M);
	M += N;
	for(int i=0; i<N; i++)
		p[i] = 10000.0 / N * i;
	for(int i=0; i<M; i++)
		q[i] = 10000.0 / M * i;
	double result = 0;
	for(int i=0; i<N; i++){
		double temp = 10000;
		for(int j=0; j<M; j++)
			temp = min(abs(p[i]-q[j]), temp);
		result += temp;
	}
	printf("%.6lf\n", result);
}