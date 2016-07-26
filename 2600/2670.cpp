#include <cstdio>
using namespace std;

int main(){

	int N;
	double f, max = 0.0, locMax = 1.0, absMax = 1.0;
	bool flag = true;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%lf", &f);
		if(f > 1.0) flag = false;
		if(max < f) max = f;
		locMax *= f;
		if(locMax < 1.0) locMax = 1.0;
		else if(locMax > absMax) absMax = locMax;
	}
	printf("%.3lf\n", flag?max:absMax);

	return 0;
}