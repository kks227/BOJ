#include <cstdio>
using namespace std;
int roff[4] = {1, 0, -1, 0};
int coff[4] = {0, 1, 0, -1};

int main(){
	int N, x = 0, y = 0, cnt = 0, i = 0, j = 0;
	scanf("%d", &N);
	while(1){
		int l = j/2+1;
		if(i+l > N) break;
		x += l*coff[j%4];
		y += l*roff[j%4];
		i += l;
		j++;
	}
	printf("%d %d\n", x+(N-i)*coff[j%4], y+(N-i)*roff[j%4]);
}