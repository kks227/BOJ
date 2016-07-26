#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	char s1[4001], s2[4002];
	scanf("%s %s", s1, s2);
	char *S1 = s1, *S2 = s2;
	int len1 = strlen(S1), len2 = strlen(S2);
	if(len1 > len2){
		swap(len1, len2);
		swap(S1, S2);
	}

	int result = 0;
	int tempLen;
	for(int i=1-len1; i<len2; i++){
		tempLen = 0;
		for(int j=(i<0)?-i:0; j<len1 && i+j<len2; j++){
			if(S2[i+j] == S1[j]) tempLen++;
			else{
				result = max(result, tempLen);
				tempLen = 0;
			}
		}
		result = max(result, tempLen);
	}
	printf("%d\n", result);
}