#include <cstdio>
#include <cstring>
using namespace std;

int main(){

	char A[10001];
	int len, sum = 0;
	scanf("%s", A);
	len = strlen(A);
	for(int i=0; i<len; i++)
		sum += A[i]-'0';

	long long result = 0;
	scanf("%s", A);
	len = strlen(A);
	for(int i=0; i<len; i++)
		result += sum * (A[i]-'0');
	printf("%lld\n", result);

	return 0;
}