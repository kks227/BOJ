#include <cstdio>
using namespace std;

int main(){
	int N, M, cnt[100][100] = {0}, result = 0;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for(int x=x1; x<=x2; x++)
			for(int y=y1; y<=y2; y++)
				cnt[x][y]++;
	}
	for(int i=0; i<100; i++)
		for(int j=0; j<100; j++)
			result += (cnt[i][j] > M);
	printf("%d\n", result);
}