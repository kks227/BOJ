#include <cstdio>
#include <cstring>
using namespace std;

int main(){

	int N, len;
	char str[1001];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%s", str);
		len = strlen(str);
		printf("Do-it%s\n", (str[len/2-1] == str[len/2])?"":"-Not");
	}

	return 0;
}