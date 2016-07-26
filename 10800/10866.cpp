#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	deque<int> dq;
	for(int i=0; i<N; i++){
		char s[11];
		scanf("%s", s);
		if(strcmp(s, "push_front")==0){
			int n;
			scanf("%d", &n);
			dq.push_front(n);
		}
		else if(strcmp(s, "push_back")==0){
			int n;
			scanf("%d", &n);
			dq.push_back(n);
		}
		else if(strcmp(s, "pop_front")==0){
			if(dq.empty()) puts("-1");
			else{
				printf("%d\n", dq.front());
				dq.pop_front();
			}
		}
		else if(strcmp(s, "pop_back")==0){
			if(dq.empty()) puts("-1");
			else{
				printf("%d\n", dq.back());
				dq.pop_back();
			}
		}
		else if(strcmp(s, "size")==0){
			printf("%d\n", dq.size());
		}
		else if(strcmp(s, "empty")==0){
			printf("%d\n", dq.empty());
		}
		else if(strcmp(s, "front")==0){
			printf("%d\n", dq.empty()?-1:dq.front());
		}
		else if(strcmp(s, "back")==0){
			printf("%d\n", dq.empty()?-1:dq.back());
		}
	}
}