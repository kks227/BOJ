#include <cstdio>
using namespace std;

int main(){
	int result = 0;
	char d[3] = {'P', 'E', 'R'};
	for(int i=0; ; i++){
		char c = getchar();
		if(c == '\n') break;
		result += (c != d[i%3]);
	}
	printf("%d\n", result);
}