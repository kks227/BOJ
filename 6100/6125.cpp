#include <cstdio>
#include <stack>
using namespace std;

int main(){
	int P, NS, T, p[5000], l[5000], r[5000];
	scanf("%d %d %d", &P, &NS, &T);
	T--;
	for(int i=0; i<NS; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		u--; v--; w--;
		l[u] = v; r[u] = w;
		p[v] = p[w] = u;
	}

	stack<int> S;
	S.push(T);
	while(S.top() != 0)
		S.push(p[S.top()]);
	printf("%d\n", S.size());
	while(!S.empty()){
		printf("%d\n", S.top()+1);
		S.pop();
	}
}