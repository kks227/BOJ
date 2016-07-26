#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

int getRomeValue(char *rome){
	int len = strlen(rome);
	int result = 0;

	for(int i=len-1; i>=0; i--){
		switch(rome[i]){
		case 'I':
			result++;
			break;
		case 'V':
			if(i>0 && rome[i-1]=='I'){
				i--;
				result += 4;
			}
			else result += 5;
			break;
		case 'X':
			if(i>0 && rome[i-1]=='I'){
				i--;
				result += 9;
			}
			else result += 10;
			break;
		case 'L':
			if(i>0 && rome[i-1]=='X'){
				i--;
				result += 40;
			}
			else result += 50;
			break;
		case 'C':
			if(i>0 && rome[i-1]=='X'){
				i--;
				result += 90;
			}
			else result += 100;
			break;
		case 'D':
			if(i>0 && rome[i-1]=='C'){
				i--;
				result += 400;
			}
			else result += 500;
			break;
		case 'M':
			if(i>0 && rome[i-1]=='C'){
				i--;
				result += 900;
			}
			else result += 1000;
			break;
		}
	}

	return result;
}

int main(){

	char A[20], B[20];
	char alp[4][2] = {'I', 'V', 'X', 'L', 'C', 'D', 'M', '?'};
	int sum, cnt = 0;
	scanf("%s %s", A, B);
	sum = getRomeValue(A) + getRomeValue(B);
	printf("%d\n", sum);

	stack<char> rome;
	while(sum){
		if(sum%10 == 9){
			rome.push(alp[cnt+1][0]);
			rome.push(alp[cnt][0]);
		}
		else if(sum%10 >= 5){
			sum -= 5;
			for(int i=0; i<sum%10; i++)
				rome.push(alp[cnt][0]);
			rome.push(alp[cnt][1]);
		}
		else if(sum%10 == 4){
			rome.push(alp[cnt][1]);
			rome.push(alp[cnt][0]);
		}
		else{
			for(int i=0; i<sum%10; i++)
				rome.push(alp[cnt][0]);
		}
		sum /= 10;
		cnt++;
	}
	while(!rome.empty()){
		putchar(rome.top());
		rome.pop();
	}
	puts("");

	return 0;
}