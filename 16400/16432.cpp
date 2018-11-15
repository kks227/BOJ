#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int N;
	bool exist[1000][9] = {false,};
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int m, a;
		scanf("%d", &m);
		for(int j = 0; j < m; ++j){
			scanf("%d", &a);
			exist[i][a-1] = true;
		}
	}
	queue<int> Q;
	bool visited[1000][9] = {false,};
	for(int i = 0; i < 9; ++i){
		if(exist[0][i]){
			visited[0][i] = true;
			Q.push(i);
		}
	}
	int prev[1000][9];
	for(int i = 1; i < N; ++i){
		int qSize = Q.size();
		for(int j = 0; j < qSize; ++j){
			int kind = Q.front(); Q.pop();
			for(int k = 0; k < 9; ++k){
				if(exist[i][k] && k != kind && !visited[i][k]){
					visited[i][k] = true;
					prev[i][k] = kind;
					Q.push(k);
				}
			}
		}
	}

	for(int i = 0; i < 9; ++i){
		if(exist[N-1][i] && visited[N-1][i]){
			vector<int> result(1, i);
			for(int j = N-1, k = i; j > 0; --j){
				k = prev[j][k];
				result.push_back(k);
			}
			for(int j = result.size()-1; j >= 0; --j)
				printf("%d\n", result[j]+1);
			return 0;
		}
	}
	puts("-1");
}