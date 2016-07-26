#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <functional>
using namespace std;

typedef pair<int, int> intPair;
typedef map<int, int> intMap;
typedef intMap::iterator mapIter;

int main(){

	int T, N, P, Q, u, v, w, temp, result, resultDist;
	int folk[100], sd[100];
	bool visited[100];
	priority_queue< intPair, vector<intPair>, greater<intPair> > pq;
	intMap dist[100];
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d %d %d", &N, &P, &Q);
		memset(folk, 0, sizeof(folk));
		for(int i=0; i<N; i++){
			scanf("%d", &u);
			folk[--u]++;
		}
		for(int i=0; i<P; i++)
			dist[i].clear();
		for(int i=0; i<Q; i++){
			scanf("%d %d %d", &u, &v, &w);
			dist[u-1][v-1] = dist[v-1][u-1] = w;
		}
		result = -1;
		resultDist = 0x7FFFFFFF;
		for(int start=0; start<P; start++){
			memset(visited, 0, 100);
			for(int i=0; i<P; i++)
				sd[i] = 1000000000;
			visited[start] = true;
			sd[start] = 0;
			while(!pq.empty()) pq.pop();
			for(mapIter iter=dist[start].begin(); iter!=dist[start].end(); iter++){
				sd[iter->first] = iter->second;
				pq.push(intPair(iter->second, iter->first));
			}
			for(int i=0; i<P-2; i++){
				while(1){
					u = pq.top().second;
					pq.pop();
					if(!visited[u]) break;
				}
				visited[u] = true;
				for(mapIter iter=dist[u].begin(); iter!=dist[u].end(); iter++){
					if(visited[iter->first]) continue;
					if(sd[u] + iter->second >= sd[iter->first]) continue;
					sd[iter->first] = sd[u] + iter->second;
					pq.push(intPair(sd[iter->first], iter->first));
				}
			}
			temp = 0;
			for(int i=0; i<P; i++)
				temp += folk[i]*sd[i]*sd[i];
			if(temp < resultDist){
				result = start;
				resultDist = temp;
			}
		}
		printf("%d %d\n", result+1, resultDist);
	}

	return 0;
}