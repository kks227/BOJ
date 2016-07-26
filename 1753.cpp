#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
 
typedef map<int, int> intMap;
typedef pair<int, int> intPair;
 
#define INF 100000000
 
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
    void getShortestPath(int start){
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
 
        for(int i=0; i<size; i++){
            if(dist[i] >= INF) printf("INF\n");
            else printf("%d\n", dist[i]);
        }
 
        delete[] dist;
        delete[] visited;
    }
private:
    int size;
    intMap *len;
};
 
int main(){
 
    int V, E, K, u, v, w;
    scanf("%d %d %d", &V, &E, &K);
    graph gp(V);
    for(int i=0; i<E; i++){
        scanf("%d %d %d", &u, &v, &w);
        gp.addEdge(u-1, v-1, w);
    }
    gp.getShortestPath(K-1);
 
    return 0;
}