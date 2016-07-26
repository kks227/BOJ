#include <cstdio>
using namespace std;

int main(){
	while(1){
		char N[1001];
		scanf("%s", N);
		if(N[0] == '0') break;
		int result = 0;
		for(int i=0; N[i]; i++)
			result += N[i]-'0';
		while(result >= 10){
			int temp = result;
			result = 0;
			while(temp){
				result += temp%10;
				temp /= 10;
			}
		}
		printf("%d\n", result);
	}
}