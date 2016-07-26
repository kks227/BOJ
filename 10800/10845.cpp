#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	queue<int> q;
	for(int i=0; i<N; i++){
		char str[6];
		scanf("%s", str);
		if(strcmp(str, "push")==0){
			int n;
			scanf("%d", &n);
			q.push(n);
		}
		else if(strcmp(str, "pop")==0){
			if(q.empty()) puts("-1");
			else{
				printf("%d\n", q.front());
				q.pop();
			}
		}
		else if(strcmp(str, "size")==0){
			printf("%d\n", q.size());
		}
		else if(strcmp(str, "empty")==0){
			printf("%d\n", q.empty());
		}
		else if(strcmp(str, "front")==0){
			printf("%d\n", q.empty()?-1:q.front());
		}
		else if(strcmp(str, "back")==0){
			printf("%d\n", q.empty()?-1:q.back());
		}
	}
}