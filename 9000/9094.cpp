#include <cstdio>
using namespace std;

int main(){

	int T, n, m, a, b, cnt;
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		scanf("%d %d", &n, &m);
		cnt = 0;
		for(a=1; a<n-1; a++)
			for(b=a+1; b<n; b++)
				if( (a*a + b*b + m) % (a*b) == 0 ) cnt++;
		printf("%d\n", cnt);
	}

	return 0;
}