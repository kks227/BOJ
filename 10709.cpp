#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int H, W, result[100][100];
	char map[100][100];
	scanf("%d %d", &H, &W);
	for(int i=0; i<H; i++){
		getchar();
		for(int j=0; j<W; j++)
			map[i][j] = getchar();
	}
	memset(result, -1, sizeof(result));
	for(int i=0; i<H; i++)
		for(int j=0; j<W; j++)
			if(map[i][j] == 'c'){
				result[i][j] = 0;
				for(int k=j+1; k<W && map[i][k]!='c'; k++)
					result[i][k] = k-j;
			}
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++)
			printf("%d ", result[i][j]);
		puts("");
	}
}