#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 50;
const int INF = 1e9;

int main(){
	int N, dist[MAX][MAX];
	scanf("%d\n", &N);
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			dist[i][j] = INF;
			if(getchar() == 'Y') dist[i][j] = 1;
		}
		dist[i][i] = 0;
		getchar();
	}
	for(int k = 0; k < N; ++k)
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
	int result = 0;
	for(int i = 0; i < N; ++i){
		int temp = 0;
		for(int j = 0; j < N; ++j)
			if(i != j && dist[i][j] <= 2) ++temp;
		result = max(temp, result);
	}
	printf("%d\n", result);
}