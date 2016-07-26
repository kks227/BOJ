#include <cstdio>
#include <climits>
using namespace std;

int main(){

	int N, n, max = INT_MIN, locMax = 0, absMax = 0;
	bool flag = true;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &n);
		if(n > 0) flag = false;
		if(max < n) max = n;
		locMax += n;
		if(locMax < 0) locMax = 0;
		else if(locMax > absMax) absMax = locMax;
	}
	printf("%d\n", flag?max:absMax);

	return 0;
}