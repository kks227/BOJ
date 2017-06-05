#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		char V[3], op[2];
		double v;
		scanf("%s %s %lf", V, op, &v);
		v = -log10(v);
		printf("%.2lf\n", V[0]=='H' ? v : 14-v);
	}
}