#include <cstdio>
#include <algorithm>
using namespace std;

int N;
char map[50][50];

// 현재 map에서 얻을 수 있는 최대 사탕 개수
int getMaxCandy(){
	int result = 1;
	// 행 단위로 훑기
	for(int i=0; i<N; i++){
		int cnt = 1;
		for(int j=1; j<N; j++){
			if(map[i][j] == map[i][j-1]) cnt++;
			else{
				result = max(result, cnt);
				cnt = 1;
			}
		}
		result = max(result, cnt);
	}
	// 열 단위로 훑기
	for(int i=0; i<N; i++){
		int cnt = 1;
		for(int j=1; j<N; j++){
			if(map[j][i] == map[j-1][i]) cnt++;
			else{
				result = max(result, cnt);
				cnt = 1;
			}
		}
		result = max(result, cnt);
	}
	return result;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<N; j++)
			map[i][j] = getchar();
	}
	int result = 0;
	// 바꿀 수 있는 모든 경우를 다 바꿔봄
	for(int i=0; i<N; i++){
		for(int j=0; j<N-1; j++){
			// 자기 바로 오른쪽 캔디와 바꿈
			swap(map[i][j], map[i][j+1]);
			result = max(result, getMaxCandy());
			swap(map[i][j], map[i][j+1]);
			// 자기 바로 아래 캔디와 바꿈
			swap(map[j][i], map[j+1][i]);
			result = max(result, getMaxCandy());
			swap(map[j][i], map[j+1][i]);
		}
	}
	printf("%d\n", result);
}