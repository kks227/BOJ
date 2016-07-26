#include <cstdio>
using namespace std;

#define INF -1

int main(){

	int n, m, i, j, max, current;
	scanf("%d %d", &n, &m);
	max = current = m;
	for(int k=0; k<n; k++){
		scanf("%d %d", &i, &j);
		if(current == INF) continue;
		current += (i-j);
		if(current < 0) current = INF;
		else if(max < current) max = current;
	}
	if(current == INF) max = 0;
	printf("%d\n", max);

	return 0;
}