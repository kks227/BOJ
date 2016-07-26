#include <cstdio>
using namespace std;

int integerLength(long long N){
	int result = 0;
	do{
		N /= 10;
		result++;
	}while(N>0);
	return result;
}

int main(){

	long long A, B, result, ALength, BLength, resultLength;
	int temp, tempLength;
	int printCnt, notPrintCnt;
	int cnt = 1;
	while(1){
		scanf("%lld %lld", &A, &B);
		if(A == 0) break;
		ALength = integerLength(A);
		BLength = integerLength(B);
		resultLength = integerLength(A*B);
		printf("Problem %d\n", cnt);
		for(int i=0; i<resultLength - ALength; i++)
			putchar(' ');
		printf("%lld\n", A);
		for(int i=0; i<resultLength - BLength; i++)
			putchar(' ');
		printf("%lld\n", B);
		for(int i=0; i<resultLength; i++)
			putchar('-');
		putchar('\n');
		
		printCnt = notPrintCnt = 0;
		temp = B;
		for(int i=0; i<BLength; i++){
			if(temp%10 == 0){
				temp /= 10;
				notPrintCnt++;
				continue;
			}
			else if(printCnt==0 && i==BLength-1) break;
			tempLength = integerLength(temp%10 * A);
			for(int j=0; j<resultLength - i - tempLength; j++)
				putchar(' ');
			printf("%lld", temp%10 * A);
			for(int j=0; j<notPrintCnt; j++)
				putchar('0');
			putchar('\n');
			temp /= 10;
			printCnt++;
			notPrintCnt = 0;
		}

		if(printCnt > 0){
			for(int i=0; i<resultLength; i++)
				putchar('-');
			putchar('\n');
		}
		printf("%lld\n", A*B);
		
		cnt++;
	}

	return 0;
}