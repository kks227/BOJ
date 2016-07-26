#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	double A[7] = {9.23076, 1.84523, 56.0211, 4.99087, 0.188807, 15.9803, 0.11193};
	double B[7] = {26.7, 75, 1.5, 42.5, 210, 3.8, 254};
	double C[7] = {1.835, 1.348, 1.05, 1.81, 1.41, 1.04, 1.88};
	for(int t=0; t<T; t++){
		int result = 0;
		for(int i=0; i<7; i++){
			int S;
			scanf("%d", &S);
			result += (int)(A[i]*pow(i%3 ? S-B[i] : B[i]-S, C[i]));
		}
		printf("%d\n", result);
	}
}