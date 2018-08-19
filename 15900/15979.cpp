#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int p, q;
	scanf("%d %d", &p, &q);
	if(p < 0) p *= -1;
	if(q < 0) q *= -1;
	if(p > q) swap(p, q);
	if(q == 0) puts("0");
	else if(p == 0) printf("%d\n", q>1?2:1);
	else{
		while(q){
			int r = p%q;
			p = q;
			q = r;
		}
		printf("%d\n", p>1?2:1);
	}
}