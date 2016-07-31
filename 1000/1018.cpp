#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int M, N;
	char map[50][50];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<M; j++)
			map[i][j] = getchar();
	}

	// 가능한 모든 위치를 다 시도해 봄
	int result = 64;
	for(int i=0; i<=N-8; i++){
		for(int j=0; j<=M-8; j++){
			int cnt = 0;
			for(int r=0; r<8; r++)
				for(int c=0; c<8; c++)
					cnt += (r%2==c%2?'W':'B')==map[i+r][j+c];
			// cnt: 맨 왼쪽 위 칸이 검은색이라 했을 때 불일치하는 칸 개수
			result = min(result, cnt);
			result = min(result, 64-cnt);
		}
	}
	printf("%d\n", result);
}