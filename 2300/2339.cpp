#include <cstdio>
#include <set>
using namespace std;

int N, arr[20][20];

// 왼쪽 위 (r1, c1), 오른쪽 아래 (r2, c2) 직사각형 영역을 자르는 경우의 수
// way는 1이면 바로 전에 세로로, 2면 바로 전에 가로로 잘랐다는 뜻
int cutting(int r1, int c1, int r2, int c2, int way){
	if(r1==r2 || c1==c2) return 0;

	// 먼저 보석의 수 cnt, 불순물의 수 stein을 센다.
	int cnt = 0, stein = 0;
	set<int> rp, cp;
	for(int i=r1; i<r2; i++){
		for(int j=c1; j<c2; j++){
			if(arr[i][j] == 2) cnt++;
			else if(arr[i][j] == 1){
				rp.insert(i);
				cp.insert(j);
				stein++;
			}
		}
	}
	if(cnt == 0) return 0; // 보석이 없으면 불가능한 경우
	if(cnt == 1) return !stein; // 보석이 1개 있고 불순물이 없으면 가능한 경우
	if(stein == 0) return 0; // 보석이 2개 이상인데 불순물이 없으면 자르기 불가능

	// 가능한 모든 경우를 시도해가며 경우의 수를 더함
	int result = 0;
	// 세로로 자르기
	if(way != 1){
		for(int c: cp){
			bool possible = true;
			for(int i=r1; i<r2; i++){
				if(arr[i][c] == 2){
					possible = false;
					break;
				}
			}
			// 양분한 영역에서 각각 얻은 경우의 수를 곱한다.
			if(possible)
				result += cutting(r1, c1, r2, c, 1) * cutting(r1, c+1, r2, c2, 1);
		}
	}
	// 가로로 자르기
	if(way != 2){
		for(int r: rp){
			bool possible = true;
			for(int i=c1; i<c2; i++){
				if(arr[r][i] == 2){
					possible = false;
					break;
				}
			}
			// 양분한 영역에서 각각 얻은 경우의 수를 곱한다.
			if(possible)
				result += cutting(r1, c1, r, c2, 2) * cutting(r+1, c1, r2, c2, 2);
		}
	}
	return result;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &arr[i][j]);
	int result = cutting(0, 0, N, N, 0);
	printf("%d\n", result ? result : -1);
}