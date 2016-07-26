#include <cstdio>
using namespace std;

int main(){
	int N, L, W, H;
	scanf("%d %d %d %d", &N, &L, &W, &H);
	double lo = 0, hi = L*1.1;
	while(hi-lo > 0.00000000001){
		double mid = (lo+hi)/2;
		if(mid==lo || mid==hi) break;
		bool success = true;
		(1.0*(int)(L/mid)*(int)(W/mid)*(int)(H/mid) < N ? hi : lo) = mid;
	}
	printf("%.10lf\n", lo);
}