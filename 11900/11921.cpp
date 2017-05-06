#include <cstdio>

int main(){
	char in[50000000] = {0};
	fread(in, 1, sizeof(in), stdin);
	int N = 0, i;
	long long sum = 0;
	char c;
	for(i=0; in[i]!='\n'; i++)
		N = N*10 + in[i]-'0';
	for(int j=0; j<N; j++){
		int temp = 0;
		for(i++; in[i]!='\n'; i++)
			temp = temp*10 + in[i]-'0';
		sum += temp;
	}
	printf("%d\n%lld\n", N, sum);
}