#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int R, C, r[500] = {0}, c[500] = {0}, m = 0, s = 0;
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			int k;
			scanf("%d", &k);
			while(k){
				if(k%10 == 9){
					r[i]++;
					c[j]++;
					s++;
				}
				k /= 10;
			}
		}
	}
	for(int i=0; i<R; i++)
		m = max(m, r[i]);
	for(int i=0; i<C; i++)
		m = max(m, c[i]);
	printf("%d\n", s-m);
}