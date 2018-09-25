#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
	int R, C, K, map[20][20] = {0};
	scanf("%d %d %d", &R, &C, &K);
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			scanf("%d", &map[i][j]);
	P p[20];
	for(int j=0; j<C; j++){
		int cnt = 0;
		for(int i=R-1; i>=0 && map[i][j]; i--, cnt++);
		p[j] = P(cnt, j);
	}
	sort(p, p+C);

	int D = 0;
	for(int j=0; j<C; j++){
		int cnt = p[j].first;
		D += cnt/2;
		if(cnt % 2) D += 3;
	}
	printf("%d\n", D);
	for(int jj=0; jj<C; jj++){
		int cnt = p[jj].first;
		int j = p[jj].second;
		for(int i=R-1; i>=1 && map[i][j] && map[i-1][j]; i-=2)
			printf("1 %d %d %d\n", j+1, map[i-1][j], map[i][j]);
		if(cnt % 2){
			int k = 1;
			if(map[R-cnt][j] == 1) k++;
			printf("1 %d %d %d\n", j+1, k, map[R-cnt][j]);
			printf("1 %d %d %d\n", j+1, k, k);
			printf("1 %d %d %d\n", j+1, k, k);
		}
	}
}