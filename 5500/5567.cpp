#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main(){

	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	int result = 0;
	queue<int> BFSQ;
	bool visited[500] = {true};
	set<int> adj[500];

	int N, M, a, b;
	cin >> N >> M;
	for(int i=0; i<M; i++){
		cin >> a >> b;
		adj[a-1].insert(b-1);
		adj[b-1].insert(a-1);
	}

	int qSize, curr;
	BFSQ.push(0);
	for(int loop=0; loop<2; loop++){
		qSize = BFSQ.size();
		for(int i=0; i<qSize; i++){
			curr = BFSQ.front();
			BFSQ.pop();
			for(set<int>::iterator iter=adj[curr].begin(); iter!=adj[curr].end(); iter++){
				if(visited[*iter]) continue;
				visited[*iter] = true;
				BFSQ.push(*iter);
				result++;
			}
		}
	}
	cout << result << endl;

	return 0;
}