#include <cstdio>
using namespace std;

int main(){
	int N, days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	scanf("%d", &N);
	int result = 0;
	for(int i = 2019, j = 2; i <= N; ++i){
		for(int k = 0; k < 12; ++k){
			if(j == 0) ++result;
			int temp = days[k];
			if(k == 1){
				if(i%400 == 0) ++temp;
				else if(i%100 == 0);
				else if(i%4 == 0) ++temp;
			}
			j = (j + temp) % 7;
		}
	}
	printf("%d\n", result);
}