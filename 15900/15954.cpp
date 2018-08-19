#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int N, K, A[500];
	scanf("%d %d", &N, &K);
	double result = -1;
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	for(int k=K; k<=N; k++){
		for(int i=k-1; i<N; i++){
			double E = 0, V = 0;
			for(int j=0; j<k; j++)
				E += A[i-j];
			E /= k;
			for(int j=0; j<k; j++)
				V += pow(A[i-j]-E, 2.0);
			V /= k;
			if(result < 0 || result > V) result = V;
		}
	}
	printf("%.10lf\n", sqrt(result));
}