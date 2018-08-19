#include <cstdio>
using namespace std;

int main(){
	int cnt[2][6] = {1, 2, 3, 4, 5, 6, 1, 2, 4, 8, 16, 0};
	int prize[2][6] = {500, 300, 200, 50, 30, 10, 512, 256, 128, 64, 32, 0};
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int result = 0;
		for(int i=0; i<2; i++){
			int N, sum = 0;
			scanf("%d", &N);
			if(N == 0) continue;
			for(int j=0; j<6; j++){
				sum += cnt[i][j];
				if(N <= sum){
					result += prize[i][j]*10000;
					break;
				}
			}
		}
		printf("%d\n", result);
	}
}