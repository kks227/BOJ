#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	stack<int> s;
	for(int i=0; i<N; i++){
		char str[6];
		scanf("%s", str);
		if(strcmp(str, "push")==0){
			int n;
			scanf("%d", &n);
			s.push(n);
		}
		else if(strcmp(str, "pop")==0){
			if(s.empty()) puts("-1");
			else{
				printf("%d\n", s.top());
				s.pop();
			}
		}
		else if(strcmp(str, "size")==0){
			printf("%d\n", s.size());
		}
		else if(strcmp(str, "empty")==0){
			printf("%d\n", s.empty());
		}
		else if(strcmp(str, "top")==0){
			printf("%d\n", s.empty()?-1:s.top());
		}
	}
}