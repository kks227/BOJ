#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	
	char S[1001];
	scanf("%s", S);
	int len = strlen(S);
	int oddResult = len*2-1, evenResult = len*2;
	bool flag;
	for(int i=len/2; i<len; i++){
		flag = true;
		for(int j=0; j<=i && i+j<len; j++){
			if(S[i+j] != S[i-j]){
				flag = false;
				break;
			}
		}
		if(flag){
			oddResult = i*2+1;
			break;
		}
	}
	for(int i=max(1, (len+1)/2); i<len; i++){
		flag = true;
		for(int j=0; j<i && i+j<len; j++){
			if(S[i+j] != S[i-j-1]){
				flag = false;
				break;
			}
		}
		if(flag){
			evenResult = i*2;
			break;
		}
	}
	printf("%d\n", min(oddResult, evenResult));

	return 0;
}