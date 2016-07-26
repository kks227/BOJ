#include <cstdio>
#include <cstring>
using namespace std;

int main(){

	int N;
	char str1[1001], str2[1001];
	scanf("%d %s %s", &N, str1, str2);
	if(N%2){
		bool flag = true;
		int len = strlen(str1);
		for(int i=0; i<len; i++){
			if(str1[i] == str2[i]){
				flag = false;
				break;
			}
		}
		if(flag) puts("Deletion succeeded");
		else puts("Deletion failed");
	}
	else{
		if(strcmp(str1, str2)) puts("Deletion failed");
		else puts("Deletion succeeded");
	}

	return 0;
}