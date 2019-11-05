#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <set>
#include <algorithm>
using namespace std;
const int MAX = 6;
typedef pair<int, bool> P;
typedef vector<P> Node;

int main(){
	int N;
	Node s;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int k;
		char c;
		scanf("%d %c", &k, &c);
		s.push_back(P(k-1, c=='-'));
	}
	set<Node> visited;
	visited.insert(s);
	queue<Node> Q;
	Q.push(s);
	for(int result = 0; ; ++result){
		int qSize = Q.size();
		for(int k = 0; k < qSize; ++k){
			Node curr = Q.front(); Q.pop();
			bool flag = true;
			for(int i = 0; i < N; ++i){
				if(curr[i].first != i || curr[i].second){
					flag = false;
					break;
				}
			}
			if(flag){
				printf("%d\n", result);
				return 0;
			}

			for(int i = 1; i <= N; ++i){
				Node next(curr);
				reverse(next.begin(), next.begin()+i);
				for(int j = 0; j < i; ++j)
					next[j].second = !next[j].second;
				if(visited.find(next) == visited.end()){
					visited.insert(next);
					Q.push(next);
				}
			}
		}
	}
}