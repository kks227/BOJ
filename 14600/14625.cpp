#include <cstdio>
using namespace std;

int main(){
	int H[2], M[2], result = 0, N;
	scanf("%d %d %d %d %d", H, M, H+1, M+1, &N);
	for(int i=H[0]; i<=H[1]; i++)
		for(int j=(i==H[0]?M[0]:0); j<=(i==H[1]?M[1]:59); j++)
			if(i/10==N || i%10==N || j/10==N || j%10==N) result++;
	printf("%d\n", result);
}