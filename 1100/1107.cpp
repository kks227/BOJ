#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
const int MAX = 1000000;
const int DEFAULT = 100;

int N, M;
bool broken[10], visited[MAX];
queue<int> Q, wait[7];

void DFS(int pos, int curr){
	for(int i=0; i<10; i++)
		if(!broken[i]){
			int next = curr*10 + i;
			if(next != DEFAULT)
				wait[pos+1].push(next);
			if(pos < 5) DFS(pos+1, next);
		}
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int b;
		scanf("%d", &b);
		broken[b] = true;
	}

	DFS(0, 0);
	wait[0].push(DEFAULT);
	int result;
	for(result=0; !Q.empty() || result<7; result++){
		if(result < 7){
			while(!wait[result].empty()){
				int t = wait[result].front();
				wait[result].pop();
				if(!visited[t]){
					Q.push(t);
					visited[t] = true;
				}
			}
		}
		if(visited[N]) break;

		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int curr = Q.front();
			Q.pop();

			for(int o=-1; o<=1; o+=2){
				int next = curr + o;
				if(0<=next && next<MAX && !visited[next]){
					Q.push(next);
					visited[next] = true;
				}
			}
		}
	}
	printf("%d\n", result);
}