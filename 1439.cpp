#include <cstdio>
using namespace std;

int main(){
	int prev = -1, cur, cnt = 1;
	while(scanf("%1d", &cur) > 0){
		if(prev != -1 && prev != cur) cnt++;
		prev = cur;
	}
	printf("%d\n", cnt/2);
}