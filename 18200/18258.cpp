#include <cstdio>
#include <queue>
#include <list>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	queue<int, list<int>> Q;
	for(int i = 0; i < N; ++i){
		char op[6];
		scanf("%s", op);
		if(op[0] == 's'){
			printf("%d\n", Q.size());
		}
		else if(op[0] == 'e'){
			printf("%d\n", Q.empty());
		}
		else if(op[0] == 'f'){
			printf("%d\n", Q.empty()?-1:Q.front());
		}
		else if(op[0] == 'b'){
			printf("%d\n", Q.empty()?-1:Q.back());
		}
		else if(op[1] == 'u'){
			int n;
			scanf("%d", &n);
			Q.push(n);
		}
		else{
			if(Q.empty()) puts("-1");
			else{
				printf("%d\n", Q.front());
				Q.pop();
			}
		}
	}
}