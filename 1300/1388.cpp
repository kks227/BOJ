#include <cstdio>
using namespace std;

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	char map[100][100];
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<M; j++)
			map[i][j] = getchar();
	}

	int result = 0;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++){
			if(map[i][j] == '-'){
				result++;
				for(int k=j; k<M && map[i][k]=='-'; k++)
					map[i][k] = '/';
			}
			else if(map[i][j] == '|'){
				result++;
				for(int k=i; k<N && map[k][j]=='|'; k++)
					map[k][j] = '/';
			}
		}
	printf("%d\n", result);
}