#include <cstdio>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 20000;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N, prev[MAX];
		char pc[MAX];
		scanf("%d", &N);
		bool visited[MAX] = {false,};
		queue<int> Q;
		Q.push(1);
		visited[1] = true;
		for(int i = 0; i < 100; ++i){
			int qSize = Q.size();
			for(int j = 0; j < qSize; ++j){
				int curr = Q.front(); Q.pop();
				for(int k = 0; k < 2; ++k){
					int next = (curr*10 + k) % N;
					if(!visited[next]){
						prev[next] = curr;
						pc[next] = k + '0';
						visited[next] = true;
						Q.push(next);
					}
				}
			}
		}

		if(!visited[0]) puts("BRAK");
		else{
			int curr = 0;
			stack<char> result;
			do{
				result.push(pc[curr]);
				curr = prev[curr];
			}while(curr != 1);
			result.push('1');
			while(!result.empty()){
				putchar(result.top());
				result.pop();
			}
			puts("");
		}
	}
}