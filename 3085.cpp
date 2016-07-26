#include <cstdio>
#include <algorithm>
using namespace std;

int N;
char map[50][50];

int getMaxCandy(){
	int result = 1;
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
	for(int i=0; i<N; i++)
		for(int j=0; j<N-1; j++){
			swap(map[i][j], map[i][j+1]);
			result = max(result, getMaxCandy());
			swap(map[i][j], map[i][j+1]);
			swap(map[j][i], map[j+1][i]);
			result = max(result, getMaxCandy());
			swap(map[j][i], map[j+1][i]);
		}
	printf("%d\n", result);
}