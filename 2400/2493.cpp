#include <cstdio>
#include <utility>
#include <stack>
using namespace std;
typedef pair<int, int> P;

int main(){
	int N;
	scanf("%d", &N);
	stack<P> s;
	for(int i=1; i<=N; i++){
		int height;
		scanf("%d", &height);
		while(!s.empty() && s.top().second < height) s.pop();
		if(s.empty()) printf("0");
		else printf("%d", s.top().first);
		putchar(i<N?' ':'\n');
		s.push(P(i, height));
	}
}