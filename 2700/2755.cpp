#include <cstdio>
using namespace std;

int main(){
	int N, sum = 0, cnt = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		char lec[101], g[3];
		int k, temp = 0;
		scanf("%s %d %s", lec, &k, g);
		temp = (g[0]=='F' ? 0 : 'E'-g[0]) * 10;
		if(g[1] == '+') temp += 3;
		else if(g[1] == '-') temp -= 3;
		sum += temp*k;
		cnt += k;
	}
	printf("%.2lf\n", sum/10.0/cnt+10e-10);
}