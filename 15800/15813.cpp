#include <cstdio>
using namespace std;

int main(){
	int N, result = 0;
	scanf("%d\n", &N);
	for(int i=0; i<N; i++)
		result += getchar()-'A'+1;
	printf("%d\n", result);
}