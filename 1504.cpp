#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

typedef map<int, int> intMap;
typedef pair<int, int> intPair;

#define INF 1000000000

class graph{
public:
	graph(int n):size(n){
		len = new intMap[n];
	}
	~graph(){
		delete[] len;
	}
	void addEdge(int u, int v, int w){
		if(len[u].find(v) == len[u].end()){
			len[u][v] = w;
			len[v][u] = w;
		}
		else{
			len[u][v] = min(len[u][v], w);
			len[v][u] = min(len[v][u], w);
		}
	}
	intPair getSpecialShortestPath(int start, int p, int q){
		priority_queue< intPair, vector<intPair>, greater<intPair> > edge;
		unsigned int *dist = new unsigned int[size];
		for(int i=0; i<size; i++)
			dist[i] = INF;
		dist[start] = 0;

		for(intMap::iterator iter=len[start].begin(); iter!=len[start].end(); iter++){
			dist[iter->first] = iter->second;
			edge.push(intPair(iter->second, iter->first));
		}
		
		bool *visited = new bool[size];
		memset(visited, 0, size);
		visited[start] = true;
		
		int u;
		bool isThereMoreToGo;
		for(int i=0; i<size-2; i++){
			if(edge.empty()) break;
			isThereMoreToGo = false;
			while(1){
				u = (edge.top()).second;
				edge.pop();
				if(!visited[u]){
					isThereMoreToGo = true;
					break;
				}
			}
			if(!isThereMoreToGo) break;

			visited[u] = true;

			for(intMap::iterator iter=len[u].begin(); iter!=len[u].end(); iter++){
				if(!visited[iter->first] && (dist[u] + iter->second < dist[iter->first])){
					dist[iter->first] = dist[u] + iter->second;
					edge.push(intPair(dist[iter->first], iter->first));
				}
			}
		}

		intPair result(dist[p], dist[q]);
		delete[] dist;
		delete[] visited;
		return result;
	}
private:
	int size;
	intMap *len;
};

int main(){

	int N, E, a, b, c, P, Q;
	scanf("%d %d", &N, &E);
	graph gp(N);
	for(int i=0; i<E; i++){
		scanf("%d %d %d", &a, &b, &c);
		gp.addEdge(a-1, b-1, c);
	}
	scanf("%d %d", &P, &Q);
	intPair path1 = gp.getSpecialShortestPath(0, P-1, Q-1);
	intPair path2 = gp.getSpecialShortestPath(N-1, P-1, Q-1);
	intPair path3 = gp.getSpecialShortestPath(P-1, Q-1, Q-1);
	int result[3][2] = {
		path1.first, path1.second,
		path2.first, path2.second,
		path3.first, path3.second
	};
	for(int i=0; i<3; i++){
		for(int j=0; j<2; j++){
			if(result[i][j] == INF){
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n", min(result[0][0]+result[1][1], result[0][1]+result[1][0])+result[2][0]);
    return 0;
}