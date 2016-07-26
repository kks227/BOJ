#include <cstdio>
using namespace std;

int main(){
	int sum = 0;
	for(int i=0; i<4; i++){
		int sec;
		scanf("%d", &sec);
		sum += sec;
	}
	printf("%d\n%d\n", sum/60, sum%60);
}