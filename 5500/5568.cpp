#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N, K, card[10], chosen[4];
bool visited[10];
set<int> result;

void DFS(int used){
	if(used == K){
		int temp = 0;
		for(int i=0; i<K; i++)
			temp = temp * (card[chosen[i]]<10 ? 10 : 100) + card[chosen[i]];
		result.insert(temp);
	}
	else{
		for(int i=0; i<N; i++)
			if(!visited[i]){
				visited[i] = true;
				chosen[used] = i;
				DFS(used+1);
				visited[i] = false;
			}
	}
}

int main(){
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++)
		scanf("%d", card+i);
	DFS(0);
	printf("%d\n", result.size());
}