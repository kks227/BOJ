#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int N, adj[20];
bool visited[20];

void DFS(int cur){
	visited[cur] = true;
	int next = adj[cur];
	if(!visited[next]) DFS(next);
}

int main(){
	for(int t=1; ; t++){
		cin >> N;
		if(N == 0) break;
		memset(visited, 0, sizeof(visited));

		string input[20][2];
		for(int i=0; i<N; i++)
			for(int j=0; j<2; j++)
				cin >> input[i][j];
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				if(input[j][0] == input[i][1]){
					adj[i] = j;
					break;
				}
		int result = 0;
		for(int i=0; i<N; i++)
			if(!visited[i]){
				DFS(i);
				result++;
			}
		cout << t << ' ' << result << endl;
	}
}