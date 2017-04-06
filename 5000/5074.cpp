#include <cstdio>
using namespace std;

int main(){
	while(1){
		int h1, m1, h2, m2;
		scanf("%02d:%02d %02d:%02d", &h1, &m1, &h2, &m2);
		if(!(h1 || m1 || h2 || m2)) break;

		int c = (m1+m2 >= 60);
		m1 = (m1 + m2) % 60;
		h1 = (h1 + h2 + c);
		c = h1 / 24;
		h1 %= 24;
		printf("%02d:%02d", h1, m1);
		if(c > 0) printf(" +%d", c);
		puts("");
	}
}