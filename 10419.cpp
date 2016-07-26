#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int d;
		scanf("%d", &d);
		printf("%d\n", (int)((sqrt(1+4*d)-1)/2));
	}
}