#include <cstdio>
#include <cstring>
#include <set>
#include <queue>
using namespace std;

int hashChar(char c){
	if(c <= 'Z') return c - 'A';
	else return c - 'a' + 26;
}

char dehashChar(int n){
	if(n < 26) return n + 'A';
	else return n - 26 + 'a';
}

int main(){

	typedef set<int> intSet;
	typedef intSet::iterator setIter;
	typedef pair<char, char> charPair;
	intSet adj[52];

	int N, X, pre, suc;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		getchar();
		pre = hashChar(getchar());
		getchar();
		getchar();
		getchar();
		getchar();
		suc = hashChar(getchar());
		adj[pre].insert(suc);
	}

	queue<charPair> result;
	bool visited[52];
	intSet visitSet;
	int current;
	queue<int> BFSQ;
	for(int i=0; i<52; i++){
		if(adj[i].empty()) continue;

		memset(visited, 0, 52);
		visitSet.clear();
		while(!BFSQ.empty()) BFSQ.pop();

		BFSQ.push(i);
		while(!BFSQ.empty()){
			current = BFSQ.front();
			BFSQ.pop();
			if(visited[current]) continue;
			visited[current] = true;
			for(setIter iter=adj[current].begin(); iter!=adj[current].end(); iter++)
				if(!visited[*iter]) BFSQ.push(*iter);
		}

		for(int j=0; j<52; j++){
			if(i==j || !visited[j]) continue;
			result.push(charPair(dehashChar(i), dehashChar(j)));
		}
	}

	charPair temp;
	printf("%d\n", result.size());
	while(!result.empty()){
		temp = result.front();
		result.pop();
		printf("%c => %c\n", temp.first, temp.second);
	}
	
	return 0;
}