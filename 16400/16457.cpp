#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 10;
const int MAX_M = 100;

int N, M, K, need[MAX_M][MAX];
bool used[MAX*2];

int quest(int pos, int cnt){
	if(N*2-pos < N-cnt) return 0;

	int result = 0;
	if(pos == N*2){
		for(int i = 0; i < M; ++i){
			bool flag = true;
			for(int j = 0; j < K; ++j){
				if(!used[need[i][j]]){
					flag = false;
					break;
				}
			}
			if(flag) ++result;
		}
		return result;
	}

	result = quest(pos+1, cnt);
	if(cnt < N){
		used[pos] = true;
		result = max(quest(pos+1, cnt+1), result);
		used[pos] = false;
	}
	return result;
}

int main(){
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < M; ++i){
		for(int j = 0; j < K; ++j){
			scanf("%d", &need[i][j]);
			--need[i][j];
		}
	}
	printf("%d\n", quest(0, 0));
}