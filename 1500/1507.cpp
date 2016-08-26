#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

int main(){
	int N, d[20][20];
	bool erased[20][20] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &d[i][j]);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int minD = INF;
			for(int k=0; k<N; k++)
				if(i!=k && j!=k) minD = min(minD, d[i][k]+d[k][j]);
			if(minD < d[i][j]){
				puts("-1");
				return 0;
			}
			if(minD == d[i][j]) erased[i][j] = true;
		}
	}
	int result = 0;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(!erased[i][j]) result += d[i][j];
	printf("%d\n", result/2);
}