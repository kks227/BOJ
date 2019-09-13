#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int K, A, B;
	scanf("%d %d %d", &K, &A, &B);
	printf("%.9lf\n", pow(K, 2.0) - pow((A-B)/2.0, 2.0));
}