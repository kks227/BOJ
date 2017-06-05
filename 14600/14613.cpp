#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	double W, L, D, result[5] = {0};
	unsigned long long F[21] = {1, 1};
	scanf("%lf %lf %lf", &W, &L, &D);
	for(int i=2; i<=20; i++)
		F[i] = F[i-1] * i;
	for(int i=0; i<=20; i++)
		for(int j=0; j<=20-i; j++)
			result[(20-j+i)/10] += pow(W, i)*pow(L, j)*pow(D, 20-i-j)*F[20]/F[i]/F[j]/F[20-i-j];
	for(int i=0; i<5; i++)
		printf("%.8lf\n", result[i]);
}