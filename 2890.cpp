#include <cstdio>
using namespace std;

int main(){
	int R, C;
	char map[50][51];
	scanf("%d %d\n", &R, &C);
	for(int i=0; i<R; i++)
		gets(map[i]);

	int dist[9];
	bool exist[50] = {0};
	for(int i=0; i<R; i++)
		for(int j=C-2; j>0; j--)
			if(map[i][j] != '.'){
				dist[map[i][j]-'1'] = C-j-1;
				exist[C-j-1] = true;
				break;
			}

	for(int i=0; i<9; i++){
		int cnt = 1;
		for(int j=0; j<dist[i]; j++)
			if(exist[j]) cnt++;
		printf("%d\n", cnt);
	}
}