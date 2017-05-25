#include <cstdio>
using namespace std;
const int INF = 1e9;

int main(){
	int N, result = -1, temp = INF;
	scanf("%d", &N);
	for(int i=1; i*i<=N; i++){
		int j = N/i + !!(N%i);
		if(temp > j-i){
			temp = j-i;
			result = j+i-2;
		}
	}
	if(result < 2) result = 2;
	printf("%d\n", result*2);
}