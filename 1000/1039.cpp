#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int M;

inline int digit(int n, int i){
	for(int k=0; k<i; k++) n /= 10;
	return n%10;
}

inline int swapDigit(int n, int i, int j){
	char S[8];
	sprintf(S, "%d", n);
	swap(S[M-i-1], S[M-j-1]);
	sscanf(S, "%d", &n);
	return n;
}

int main(){
	int N, K, result = -1;
	scanf("%d %d", &N, &K);
	queue<int> Q;
	Q.push(N);
	do{
		M++;
		N /= 10;
	}while(N);
	for(int i=0; i<K; i++){
		int qSize = Q.size();
		bool visited[1000001] = {0};
		for(int j=0; j<qSize; j++){
			int curr = Q.front();
			Q.pop();
			for(int k=0; k<M-1; k++)
				for(int l=k+1; l<M; l++)
					if(l<M-1 || digit(curr, k)){
						int next = swapDigit(curr, k, l);
						if(!visited[next]){
							visited[next] = true;
							Q.push(next);
						}
					}
		}
	}
	while(!Q.empty()){
		result = max(result, Q.front());
		Q.pop();
	}
	printf("%d\n", result);
}