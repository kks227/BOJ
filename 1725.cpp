#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
	int N, j, result, hist[100001];
	stack<int> s;
	scanf("%d", &N);
	result = 0;
	for(int i=0; i<N+1; i++){
		if(i<N) scanf("%d", hist+i);
		else hist[N] = 0;
		while(!s.empty() && hist[s.top()] >= hist[i]){
			j = s.top();
			s.pop();
			result = max(result, hist[j]*(s.empty()?i:i-s.top()-1));
		}
		s.push(i);
	}
	printf("%d\n", result);
}