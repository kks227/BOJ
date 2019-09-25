#include <cstdio>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX = 1001;
const int MAX_K = 30;

int K, M, N, dp[MAX][MAX];
char A[MAX], B[MAX];

int DNA(int a, int b){
	int &ret = dp[a][b];
	if(ret != -1) return ret;
	if(a == M || b == N) return ret = 0;

	ret = 0;
	for(int i = 1; i <= K+1 && a+i < M; ++i)
		for(int j = 1; j <= K+1 && b+j < N; ++j)
			if(A[a+i] == B[b+j]) ret = max(DNA(a+i, b+j), ret);
	return ++ret;
}

int main(){
	unordered_map<char, int> C2I;
	C2I['A'] = 0; C2I['C'] = 1; C2I['G'] = 2; C2I['T'] = 3;
	char I2C[4] = {'A', 'C', 'G', 'T'};
	scanf("%d %d %s %d %s", &K, &M, A, &N, B);
	memset(dp, -1, sizeof(dp));
	int result = -1;
	for(int i = 0; i < M; ++i)
		for(int j = 0; j < N; ++j)
			if(A[i] == B[j]) result = max(DNA(i, j), result);

	queue<int> CQ[4];
	for(int i = 0; i < M; ++i)
		for(int j = 0; j < N; ++j)
			if(A[i] == B[j] && DNA(i, j) == result) CQ[ C2I[A[i]] ].push(i*MAX+j);
	for(int k = 1; k <= result; ++k){
		int qn = -1;
		for(int i = 0; i < 4; ++i){
			if(!CQ[i].empty()){
				qn = i;
				for(int j = i+1; j < 4; ++j)
					while(!CQ[j].empty()) CQ[j].pop();
				break;
			}
		}
		putchar(I2C[qn]);
		if(k == result) break;

		queue<int> &Q = CQ[qn];
		int qSize = Q.size();
		bool visited[MAX][MAX] = {false,};
		for(int i = 0; i < qSize; ++i){
			int a = Q.front()/MAX, b = Q.front()%MAX; Q.pop();
			for(int na = a+1; na-a <= K+1 && na < M; ++na){
				for(int nb = b+1; nb-b <= K+1 && nb < N; ++nb){
					if(A[na] == B[nb] && DNA(na, nb) == result-k && !visited[na][nb]){
						visited[na][nb] = true;
						CQ[ C2I[A[na]] ].push(na*MAX+nb);
					}
				}
			}
		}
	}
}