#include <cstdio>
using namespace std;
const int limit = 20;

int x, y;
long long x0, y0, p3[limit+1] = {1};

bool dfs(int k){
	if(x == x0 && y == y0) return true;
	if(k > limit) return false;

	x0 += p3[k];
	if(dfs(k+1)) return true;
	x0 -= p3[k];
	y0 += p3[k];
	if(dfs(k+1)) return true;
	y0 -= p3[k];
	return false;
}

int main(){
	scanf("%d %d", &x, &y);
	for(int i=1; i<=limit; i++)
		p3[i] = p3[i-1] * 3;
	printf("%d\n", dfs(0));
}