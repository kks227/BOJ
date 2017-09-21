#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int H, W, val[500], lmax[500], rmax[500], result = 0;
	scanf("%d %d", &H, &W);
	for(int i=0; i<W; i++)
		scanf("%d", val+i);
	lmax[0] = val[0];
	rmax[W-1] = val[W-1];
	for(int i=1; i<W; i++){
		lmax[i] = max(lmax[i-1], val[i]);
		rmax[W-1-i] = max(rmax[W-i], val[W-1-i]);
	}
	for(int i=1; i<W-1; i++)
		result += max(min(lmax[i], rmax[i]) - val[i], 0);
	printf("%d\n", result);
}