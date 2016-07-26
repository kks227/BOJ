#include <cstdio>
using namespace std;

int main(){

	char N[100001];
	int len, cnt[10] = {0}, sum = 0;
	scanf("%s", N);
	for(len=0; N[len]; len++)
		cnt[N[len]-'0']++;
	for(int i=0; i<10; i++)
		sum += cnt[i]*i;
	if(sum%3 || cnt[0]==0) puts("-1");
	else{
		for(int i=9; i>=0; i--)
			for(int j=0; j<cnt[i]; j++)
				putchar(i+'0');
		puts("");
	}

	return 0;
}