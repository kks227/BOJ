#include <cstdio>
using namespace std;

int main(){
	int N, r1 = 0, r2 = 0;
	char map[100][100];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<N; j++)
			map[i][j] = getchar();
	}
	for(int i=0; i<N; i++){
		int cnt = 0;
		for(int j=0; j<N; j++){
			if(map[i][j] == '.') cnt++;
			else{
				if(cnt >= 2) r1++;
				cnt = 0;
			}
		}
		if(cnt >= 2) r1++;
	}
	for(int i=0; i<N; i++){
		int cnt = 0;
		for(int j=0; j<N; j++){
			if(map[j][i] == '.') cnt++;
			else{
				if(cnt >= 2) r2++;
				cnt = 0;
			}
		}
		if(cnt >= 2) r2++;
	}
	printf("%d %d\n", r1, r2);
}