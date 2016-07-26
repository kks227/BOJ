#include <cstdio>
using namespace std;

int main(){
	int t[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10}, result = 0;
	while(1){
		int c = getchar();
		if(c < 0) break;
		result += t[c-'A'];
	}
	printf("%d\n", result);
}