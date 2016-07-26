#include <cstdio>
using namespace std;
 
int main(){

	int N, result = 0, temp, dif;
	scanf("%d", &N);
	bool flag;
	for(int i=1; i<=N; i++){
		if(i<10){
			result++;
			continue;
		}
		flag = true;
		temp = i;
		temp /= 10;
		dif = i%10 - temp%10;
		while(temp>=10){
			if(dif != temp%10 - temp/10%10){
				flag = false;
				break;
			}
			temp /= 10;
		}
		result += flag;
	}
	printf("%d\n", result);
 
    return 0;
}