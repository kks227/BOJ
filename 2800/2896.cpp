#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	double A[3], R[3], p = 1e9;
	for(int i = 0; i < 3; ++i)
		scanf("%lf", A+i);
	for(int i = 0; i < 3; ++i){
		scanf("%lf", R+i);
		p = min(A[i]/R[i], p);
	}
	for(int i = 0; i < 3; ++i)
		printf("%.6lf ", A[i] - R[i]*p);
}