#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 5000000;

int main(){
	int N, X;
	scanf("%d %d", &N, &X);
	if(X < N || X > N*26) puts("!");
	else{
		char result[MAX+1] = {0,};
		fill(result, result+N, 'A');
		X -= N;
		for(int i = N-1; i >= 0 && X > 0; --i){
			int x = min(X, 25);
			result[i] += x;
			X -= x;
		}
		puts(result);
	}
}