#include <cstdio>
using namespace std;

int main(){
	int result[2] = {0,}, p = 0;
	while(1){
		char c = getchar();
		if(c == '@') ++result[p];
		else if(c == '(') ++p;
		else if(c < 0) break;
	}
	printf("%d %d\n", result[0], result[1]);
}