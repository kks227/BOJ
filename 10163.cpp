#include <cstdio>
using namespace std;

int main(){

	int N, x, y, w, h, cnt[101] = {0}, map[101][101] = {0};
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d %d %d %d", &x, &y, &w, &h);
		for(int p=x; p<x+w; p++)
			for(int q=y; q<y+h; q++)
				map[q][p] = i;
	}
	for(int i=0; i<101; i++)
		for(int j=0; j<101; j++)
			cnt[map[i][j]]++;
	for(int i=1; i<=N; i++)
		printf("%d\n", cnt[i]);

	return 0;
}