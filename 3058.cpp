#include <cstdio>
using namespace std;

int main(){

	int T;
	scanf("%d", &T);
	int temp, min, sum;
	for(int i=0; i<T; i++){
		min = 100;
		sum = 0;
		for(int j=0; j<7; j++){
			scanf("%d", &temp);
			if(temp%2 == 0){
				sum += temp;
				if(temp < min) min = temp;
			}
		}
		printf("%d %d\n", sum, min);
	}

	return 0;
}