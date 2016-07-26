#include <cstdio>
#include <cstring>
using namespace std;

int main(){

	bool self[10001];
	memset(self, 1, 10001);
	int temp, sum;
	for(int i=1; i<=10000; i++){
		temp = sum = i;
		while(temp){
			sum += temp%10;
			temp /= 10;
		}
		if(sum <= 10000) self[sum] = false;
	}
	for(int i=1; i<=10000; i++)
		if(self[i]) printf("%d\n", i);

	return 0;
}