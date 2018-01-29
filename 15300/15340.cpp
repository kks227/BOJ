#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int C[3] = {30, 35, 40}, D[3] = {40, 30, 20};
	while(1){
		int c, d;
		scanf("%d %d", &c, &d);
		if(c == 0) break;

		int result = 1e9;
		for(int i=0; i<3; i++)
			result = min(C[i]*c+D[i]*d, result);
		printf("%d\n", result);
	}
}