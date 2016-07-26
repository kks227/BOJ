#include <cstdio>
using namespace std;

int main(){
	double prev = -100;
	while(1){
		double curr;
		scanf("%lf", &curr);
		if(curr == 999) break;
		if(prev != -100) printf("%.2lf\n", curr-prev);
		prev = curr;
	}
}