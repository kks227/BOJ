#include <cstdio>
#include <queue>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int A, B;
		scanf("%d %d", &A, &B);
		set<P> S;
		S.insert(P(A, B));
		queue<P> Q;
		Q.push(P(A, B));
		bool success = false;
		for(int i=1; !Q.empty(); i++){
			int qSize = Q.size();
			for(int j=0; j<qSize; j++){
				int a = Q.front().first, b = Q.front().second; Q.pop();
				if(a*2 == b+3 || a+1 == b){
					printf("%d\n", i);
					success = true;
					break;
				}
				if(a*2 < b+3 && S.find(P(a*2, b+3)) == S.end()){
					S.insert(P(a*2, b+3));
					Q.push(P(a*2, b+3));
				}
				if(a+1 < b && S.find(P(a+1, b)) == S.end()){
					S.insert(P(a+1, b));
					Q.push(P(a+1, b));
				}
			}
			if(success) break;
		}
	}
}