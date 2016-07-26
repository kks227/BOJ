#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	for(int t=0; t<3; t++){
		char N[9];
		scanf("%s", N);
		int result = 1, len = 1;
		for(int i=1; i<9; i++){
			if(N[i] == N[i-1]) len++;
			else{
				result = max(result, len);
				len = 1;
			}
		}
		printf("%d\n", result);
	}
}