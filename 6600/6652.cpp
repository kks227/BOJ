#include <cstdio>
#include <cstring>
#include <cctype>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 10000;

int main(){
	int R[10];
	fill(R, R+10, -1);
	while(1){
		char E[10001] = {'\0'};
		scanf("%s", E);
		if(E[0] == 'Q'){
			puts("Bye");
			break;
		}

		if(E[0] == 'R'){
			fill(R, R+10, -1);
			puts("Ready");
		}
		else{
			int r = E[0]-'0', temp = 0, sign = 1;
			bool isError = false;
			for(int i = 2; ; ++i){
				if(isdigit(E[i])){
					int k = E[i++]-'0';
					if(R[k] < 0){
						isError = true;
						break;
					}
					temp += sign * R[k];
				}
				else{
					int k = 0;
					for(; isupper(E[i]); ++i){
						switch(E[i]){
						case 'I':
							if(E[i+1] == 'V'){
								k += 4;
								++i;
							}
							else if(E[i+1] == 'X'){
								k += 9;
								++i;
							}
							else k += 1;
							break;

						case 'V':
							k += 5;
							break;

						case 'X':
							if(E[i+1] == 'L'){
								k += 40;
								++i;
							}
							else if(E[i+1] == 'C'){
								k += 90;
								++i;
							}
							else k += 10;
							break;

						case 'L':
							k += 50;
							break;

						case 'C':
							if(E[i+1] == 'D'){
								k += 400;
								++i;
							}
							else if(E[i+1] == 'M'){
								k += 900;
								++i;
							}
							else k += 100;
							break;

						case 'D':
							k += 500;
							break;

						case 'M':
							k += 1000;
						}
					}
					temp += sign * k;
				}

				if(!E[i]) break;
				sign = (E[i] == '-' ? -1 : 1);
			}
			if(isError || temp < 0 || temp > MAX) puts("Error");
			else{
				R[r] = temp;
				printf("%d=", r);
				if(temp == 0) putchar('O');
				else{
					// 1000
					while(temp >= 1000){
						putchar('M');
						temp -= 1000;
					}
					// 100
					if(temp >= 900){
						printf("CM");
						temp -= 900;
					}
					if(temp >= 500){
						putchar('D');
						temp -= 500;
					}
					if(temp >= 400){
						printf("CD");
						temp -= 400;
					}
					while(temp >= 100){
						putchar('C');
						temp -= 100;
					}
					// 10
					if(temp >= 90){
						printf("XC");
						temp -= 90;
					}
					if(temp >= 50){
						putchar('L');
						temp -= 50;
					}
					if(temp >= 40){
						printf("XL");
						temp -= 40;
					}
					while(temp >= 10){
						putchar('X');
						temp -= 10;
					}
					// 1
					if(temp >= 9){
						printf("IX");
						temp -= 9;
					}
					if(temp >= 5){
						putchar('V');
						temp -= 5;
					}
					if(temp >= 4){
						printf("IV");
						temp -= 4;
					}
					while(temp >= 1){
						putchar('I');
						temp -= 1;
					}
				}
				puts("");
			}
		}
	}
}