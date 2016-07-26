#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
bool map[25][25], visited[25][25];
vector<int> cnt;

int DFS(int i, int j){
	visited[i][j] = true;
	int ret = 1;
	if(i>0 && !visited[i-1][j] && map[i-1][j]) ret += DFS(i-1, j);
	if(i<N-1 && !visited[i+1][j] && map[i+1][j]) ret += DFS(i+1, j);
	if(j>0 && !visited[i][j-1] && map[i][j-1]) ret += DFS(i, j-1);
	if(j<N-1 && !visited[i][j+1] && map[i][j+1]) ret += DFS(i, j+1);
	return ret;
}

int main(){

	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%1d", &map[i][j]);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(!visited[i][j] && map[i][j])
				cnt.push_back(DFS(i, j));
	sort(cnt.begin(), cnt.end());
	printf("%d\n", cnt.size());
	for(int i=0; i<cnt.size(); i++)
		printf("%d\n", cnt[i]);

	return 0;
}