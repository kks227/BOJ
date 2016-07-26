#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, result = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int a, b, c, score;
		scanf("%d %d %d", &a, &b, &c);
		if(a==b && b==c) score = 10000 + a*1000;
		else if(a==b) score = 1000 + a*100;
		else if(b==c) score = 1000 + b*100;
		else if(c==a) score = 1000 + c*100;
		else score = 100*max(a, max(b, c));
		result = max(result, score);
	}
	printf("%d\n", result);
}