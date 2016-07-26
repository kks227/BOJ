#include <cstdio>
using namespace std;

int main(){

	int N, x, y, result[5] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d %d", &x, &y);
		if(x==0 || y==0) result[4]++;
		else if(x>0){
			if(y>0) result[0]++;
			else result[3]++;
		}
		else{
			if(y>0) result[1]++;
			else result[2]++;
		}
	}
	for(int i=0; i<4; i++)
		printf("Q%d: %d\n", i+1, result[i]);
	printf("AXIS: %d\n", result[4]);

	return 0;
}