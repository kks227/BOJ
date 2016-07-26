#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int result = 0;
		for(int i=0; i<24; i++){
			int bit;
			scanf("%1d", &bit);
			result <<= 1;
			result += bit;
		}
		printf("%d\n", result);
	}
}