#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

// map: 0-빈칸, 1-아이템, 2-장애물
// inum: 현재 칸에서 바로 다음에 먹어야 할 아이템 번호
// pos: 번호별 아이템 위치(정렬되어 있음)
int N, M, A, B, map[100][100], inum[100][100], dp[100][100];
P pos[10000];

int getItem(int r, int c){
	int &ret = dp[r][c];
	if(ret != -1) return ret;
	if(map[r][c] == 2) return ret = 0; // 장애물
	if(r == N-1 && c == M-1) return ret = 1;

	ret = 0;
	if(map[r][c] == 1){
		if(r < N-1 && inum[r+1][c] == inum[r][c] + 1) ret += getItem(r+1, c);
		if(c < M-1 && inum[r][c+1] == inum[r][c] + 1) ret += getItem(r, c+1);
	}
	else{
		if(r < N-1 && inum[r+1][c] == inum[r][c]) ret += getItem(r+1, c);
		if(c < M-1 && inum[r][c+1] == inum[r][c]) ret += getItem(r, c+1);
	}
	return ret;
}



int main(){
	scanf("%d %d %d %d", &N, &M, &A, &B);
	for(int i=0; i<A; i++){
		int r, c;
		scanf("%d %d", &r, &c);
		map[r-1][c-1] = 1;
		pos[i] = P(r-1, c-1);
	}
	for(int i=0; i<B; i++){
		int r, c;
		scanf("%d %d", &r, &c);
		map[r-1][c-1] = 2;
	}

	memset(inum, -1, sizeof(inum));
	sort(pos, pos+A);
	if(pos[A-1] != P(N-1, M-1)) pos[A++] = P(N-1, M-1);

	int lowest = -1;
	bool impossible = false;
	for(int i=0; i<A; i++){
		int r0 = pos[i].first, c0 = pos[i].second;
		if(lowest > r0){
			impossible = true;
			break;
		}
		lowest = r0;
		for(int r=r0; r>=0 && inum[r][c0]==-1; r--){
			for(int c=c0; c>=0 && inum[r][c]==-1; c--){
				inum[r][c] = i;
			}
		}
	}
	// 불가능: 모든 아이템을 먹을 수 없음
	if(impossible){
		puts("0");
		return 0;
	}

	memset(dp, -1, sizeof(dp));
	printf("%d\n", getItem(0, 0));
}