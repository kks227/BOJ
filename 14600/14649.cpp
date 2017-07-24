#include <cstdio>
using namespace std;

int main(){
	int P, N, c[100] = {0,};
	scanf("%d %d", &P, &N);
	for(int i=0; i<N; i++){
		int x, xoff = -1;
		char d;
		scanf("%d %c", &x, &d);
		x--;
		if(d == 'R') xoff = 1;
		for(x+=xoff; x>=0 && x<100; x+=xoff)
			c[x] = (c[x]+1) % 3;
	}
	for(int i=0; i<3; i++){
		int cnt = 0;
		for(int j=0; j<100; j++)
			if(c[j] == i) cnt++;
		printf("%.2lf\n", P*0.01*cnt);
	}
}