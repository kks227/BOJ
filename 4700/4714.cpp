#include <cstdio>
using namespace std;

int main(){
	while(1){
		double f;
		scanf("%lf", &f);
		if(f < 0) break;
		printf("Objects weighing %.2lf on Earth will weigh %.2lf on the moon.\n", f, f*0.167);
	}
}