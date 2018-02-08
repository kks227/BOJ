#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX = 1e4;

int Am[1000];
vector<int> Bm, adj[1000];
bool visited[1000];

bool dfs(int a){
	visited[a] = true;
	for(int b: adj[a]){
		if(Bm[b] == -1 || !visited[Bm[b]] && dfs(Bm[b])){
			Am[a] = b;
			Bm[b] = a;
			return true;
		}
	}
	return false;
}

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> prime(1, 2);
	bool np[MAX+1] = {true, true};
	for(int i=3; i<=MAX; i+=2){
		if(np[i]) continue;
		prime.push_back(i);
		for(int j=i*i; j<=MAX; j+=i*2)
			np[j] = true;
	}

	int P = 0;
	unordered_map<int, int> DB;
	for(int i=0; i<M; i++){
		int K;
		scanf("%d", &K);
		for(int p: prime){
			if(K == 1) break;
			if(K%p == 0){
				if(DB.find(p) == DB.end()) DB[p] = P++;
				adj[i].push_back(DB[p]);
				do{ K /= p; }while(K%p == 0);
			}
		}
		if(K > 1){
			if(DB.find(K) == DB.end()) DB[K] = P++;
			adj[i].push_back(DB[K]);
		}
	}

	int result = 0;
	fill(Am, Am+M, -1);
	Bm.resize(P); fill(Bm.begin(), Bm.end(), -1);
	for(int i=0; i<M; i++){
		if(Am[i] == -1){
			fill(visited, visited+M, false);
			if(dfs(i)) result++;
		}
	}
	printf("%d\n", result);
}