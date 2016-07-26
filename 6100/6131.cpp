#include <cstdio>
using namespace std;

int main(){
	int N, cnt = 0;
	scanf("%d", &N);
	for(int i=1; i<=500; i++)
		for(int j=1; j<=i; j++)
			if(i*i == j*j+N) cnt++;
	printf("%d\n", cnt);
}