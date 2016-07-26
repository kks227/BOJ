#include <cstdio>
#include <cstring>
#include <set>
#include <queue>
using namespace std;

typedef set<int> intSet;

class graph{
public:
	graph(int n):size(n){
		adj = new intSet[n];
		visited = new bool[n];
	}
	~graph(){
		delete[] adj;
		delete[] visited;
	}
	void addEdge(int u, int v){
		adj[u].insert(v);
		adj[v].insert(u);
	}
	void DFS(int start){
		cnt = 0;
		memset(visited, 0, size);
		visited[start] = true;

		DFSStep(start);
	}
	void BFS(int start){
		cnt = 0;
		memset(visited, 0, size);
		visited[start] = true;

		int current = start;
		int tempMax;
		queue<int> adjQueue;
		adjQueue.push(start);
		while(!adjQueue.empty()){
			tempMax = adjQueue.size();
			for(int i=0; i<tempMax; i++){
				current = adjQueue.front();
				adjQueue.pop();
				cnt++;
				printf("%d%c", current+1, (cnt<size)?' ':'\n');
				for(intSet::iterator iter=adj[current].begin(); iter!=adj[current].end(); iter++){
					if(!visited[*iter]){
						visited[*iter] = true;
						adjQueue.push(*iter);
					}
				}
			}
		}
	}
private:
	int size;
	intSet *adj;
	bool *visited;
	int cnt;

	void DFSStep(int current){
		cnt++;
		printf("%d%c", current+1, (cnt<size)?' ':'\n');
		for(intSet::iterator iter=adj[current].begin(); iter!=adj[current].end(); iter++){
			if(!visited[*iter]){	
				visited[*iter] = true;
				DFSStep(*iter);
			}
		}
	}
};

int main(){

	int N, M, V, u, v;
	scanf("%d %d %d", &N, &M, &V);
	graph gp(N);
	for(int i=0; i<M; i++){
		scanf("%d %d", &u, &v);
		gp.addEdge(u-1, v-1);
	}
	gp.DFS(V-1);
	gp.BFS(V-1);

    return 0;
}