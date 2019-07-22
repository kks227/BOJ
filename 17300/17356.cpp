#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int A, B;
	scanf("%d %d", &A, &B);
	printf("%.6lf\n", 1/(pow(10, (B-A)/400.0)+1));
}