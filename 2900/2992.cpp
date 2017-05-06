#include <cstdio>
using namespace std;

int main(){
	int X, Y, cnt[10] = {0};
	scanf("%d", &X);
	Y = X;
	do{
		cnt[Y%10]++;
		Y /= 10;
	}while(Y);
	for(int i=X+1; i<=999999; i++){
		int temp[10] = {0};
		Y = i;
		do{
			temp[Y%10]++;
			Y /= 10;
		}while(Y);
		bool success = true;
		for(int j=0; j<10; j++){
			if(cnt[j] != temp[j]){
				success = false;
				break;
			}
		}
		if(success){
			printf("%d\n", i);
			return 0;
		}
	}
	puts("0");
}