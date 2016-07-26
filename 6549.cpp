#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

int hist[100001];

int main(){

	int N, j;
	long long result;
	stack<int> s;
	while(1){
		scanf("%d", &N);
		if(N == 0) break;

		memset(hist, 0, sizeof(int)*100001);
		result = 0;
		for(int i=0; i<N+1; i++){
			if(i<N) scanf("%d", hist+i);
			else hist[i] = 0;
			while(!s.empty() && hist[s.top()] >= hist[i]){
				j = s.top();
				s.pop();
				result = max(result, ((long long)hist[j])*(s.empty()?i:i-s.top()-1));
			}
			s.push(i);
		}

		printf("%lld\n", result);
		while(!s.empty())
			s.pop();
	}

	return 0;
}