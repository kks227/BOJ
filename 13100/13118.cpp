#include <cstdio>
using namespace std;

int main(){
	int p[4], x, y, r;
	for(int i=0; i<4; i++)
		scanf("%d", p+i);
	scanf("%d %d %d", &x, &y, &r);
	for(int i=0; i<4; i++){
		if(p[i] == x){
			printf("%d\n", i+1);
			return 0;
		}
	}
	puts("0");
}