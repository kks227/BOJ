#include <cstdio>
using namespace std;

int main(){
	while(1){
		char N[5];
		scanf("%s", N);
		if(N[0] == '0') break;

		int result = 1;
		for(int i=0; N[i]; i++){
			result++;
			if(N[i] == '0') result += 4;
			else if(N[i] == '1') result += 2;
			else result += 3;
		}
		printf("%d\n", result);
	}
}