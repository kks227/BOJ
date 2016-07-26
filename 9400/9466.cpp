#include <cstdio>
#include <cstring>
using namespace std;

int N, S[100000], cnt;
bool visited[100000], finished[100000];

void DFS(int curr){
	visited[curr] = true;
	int next = S[curr];
	if(visited[next]){
		if(!finished[next]){
			for(int temp=next; temp!=curr; temp=S[temp]) cnt++;
			cnt++;
		}
	}
	else DFS(next);
	finished[curr] = true;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			scanf("%d", S+i);
			S[i]--;
		}
		memset(visited, 0, sizeof(visited));
		memset(finished, 0, sizeof(finished));
		cnt = 0;
		for(int i=0; i<N; i++)
			if(!visited[i]) DFS(i);
		printf("%d\n", N-cnt);
	}
}