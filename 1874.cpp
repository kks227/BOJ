#include <cstdio>
#include <stack>
using namespace std;

int main(){

	int N, target, pushcnt=1, popcnt=0, resultcnt=0;
	scanf("%d", &N);
	stack<int> s;
	int poporder[100000];
	bool result[200000]; // +는 true, -는 false
	for(int i=0; i<N; i++)
		scanf("%d", poporder+i);

	while(popcnt < N){
		target = poporder[popcnt];
		if(!s.empty() && s.top() == target){
			popcnt++;
			s.pop();
			result[resultcnt++] = false;
		}
		else if(target < pushcnt){
			printf("NO\n");
			return 0;
		}
		else{
			s.push(pushcnt++);
			result[resultcnt++] = true;
		}
	}
	for(int i=0; i<resultcnt; i++)
		printf("%c\n", result[i]?'+':'-');

	return 0;
}