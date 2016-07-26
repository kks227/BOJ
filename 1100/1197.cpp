#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
 
typedef map<int, int> intMap;
typedef pair<int, int> intPair;

#define INF 1000000000000LL
 
class graph{
public:
    graph(int n):size(n){
        len = new intMap[n];
    }
    ~graph(){
        delete[] len;
    }
	void addEdge(int u, int v, int w){
		len[u][v] = w;
		len[v][u] = w;
	}
	long long MST(){
		bool *visited = new bool[size];
		memset(visited, 0, size);
		priority_queue< intPair, vector<intPair>, greater<intPair> > edge;
		int current = 0;
		visited[current] = true;
		for(intMap::iterator iter=len[current].begin(); iter!=len[current].end(); iter++)
			edge.push(intPair(iter->second, iter->first));

		intPair temp;
		bool isThereMoreToGo;
		int cnt;
		long long result = 0;
		for(cnt=0; cnt<size-1; cnt++){
			isThereMoreToGo = false;
			while(1){
				if(edge.empty()) break;
				temp = edge.top();
				edge.pop();
				if(!visited[temp.second]){
					current = temp.second;
					result += (long long)temp.first;
					isThereMoreToGo = true;
					break;
				}
			}
			if(!isThereMoreToGo) break;

			visited[current] = true;
			for(intMap::iterator iter=len[current].begin(); iter!=len[current].end(); iter++)
				if(!visited[iter->first])
					edge.push(intPair(iter->second, iter->first));
		}

		delete[] visited;
		if(cnt < size-1) return INF;
		return result;
	}
private:
    int size;
    intMap *len;
};
 
int main(){
 
    int V, E, A, B, C;
    scanf("%d %d", &V, &E);
    graph gp(V);
    for(int i=0; i<E; i++){
        scanf("%d %d %d", &A, &B, &C);
        gp.addEdge(A-1, B-1, C);
    }
	printf("%lld\n", gp.MST());
 
    return 0;
}