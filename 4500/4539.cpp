#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int x, p = 10;
		scanf("%d", &x);
		while(x >= p){
			int r = x%p / (p/10);
			x -= x%p;
			if(r >= 5) x += p*1;
			p *= 10;
		}
		printf("%d\n", x);
	}
}