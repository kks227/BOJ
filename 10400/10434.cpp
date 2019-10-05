#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 10001;

int main(){
	vector<int> adj[MAX];
	for(int i = 2; i < MAX; ++i){
		int j = 0, k = i;
		while(k > 0){
			j += (k%10)*(k%10);
			k /= 10;
		}
		adj[j].push_back(i);
	}
	bool visited[MAX] = {false, true,};
	queue<int> Q;
	Q.push(1);
	while(!Q.empty()){
		int curr = Q.front(); Q.pop();
		for(int next: adj[curr]){
			if(!visited[next]){
				visited[next] = true;
				Q.push(next);
			}
		}
	}

	bool np[MAX] = {true, true,};
	vector<int> prime(1, 2);
	for(int i = 4; i < MAX; i += 2)
		np[i] = true;
	for(int i = 3; i < MAX; i += 2){
		if(np[i]) continue;
		prime.push_back(i);
		for(int j = i*i; j < MAX; j += i*2)
			np[j] = true;
	}

	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int n, k;
		scanf("%d %d", &n, &k);
		printf("%d %d %s\n", n, k, (!np[k] && visited[k] ? "YES" : "NO"));
	}
}