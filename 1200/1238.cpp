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
        if(len[u].find(v) == len[u].end()) len[u][v] = w;
        else len[u][v] = min(len[u][v], w);
    }
	int getLongestDistance(int midpoint){
		int *wayToMid = new int[size];
		int *wayFromMid = new int[size];
		int *currentResult;

		for(int i=0; i<size; i++){
			currentResult = getShortestPathArray(i);
			if(i == midpoint){
				for(int j=0; j<size; j++)
					wayFromMid[j] = currentResult[j];
			}
			else wayToMid[i] = currentResult[midpoint];
			delete[] currentResult;
		}

		int result = 0;
		for(int i=0; i<size; i++)
			result = max(result, wayToMid[i] + wayFromMid[i]);

		delete[] wayToMid;
		delete[] wayFromMid;
		return result;
	}
private:
    int size;
    intMap *len;
	
    int* getShortestPathArray(int start){
        priority_queue< intPair, vector<intPair>, greater<intPair> > edge;
        int *dist = new int[size];
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
            isThereMoreToGo = false;
            while(1){
                if(edge.empty()) break;
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
  
        delete[] visited;
        return dist;
    }
};
    
int main(){
    
    int N, M, X, u, v, w;
    scanf("%d %d %d", &N, &M, &X);
    graph gp(N);
    for(int i=0; i<M; i++){
        scanf("%d %d %d", &u, &v, &w);
        gp.addEdge(u-1, v-1, w);
    }
	printf("%d\n", gp.getLongestDistance(X-1));
    
    return 0;
}