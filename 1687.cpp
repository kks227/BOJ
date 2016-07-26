#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

int main(){

	int N, M, hist[334] = {0}, result = 0, k;
	scanf("%d %d", &N, &M);
	stack<int> s;
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<M; j++){
			if(getchar() == '0') hist[j]++;
			else hist[j] = 0;
		}
		for(int j=0; j<M+1; j++){
			while(!s.empty() && hist[s.top()] >= hist[j]){
				k = s.top();
				s.pop();
				result = max(result, hist[k]*(s.empty()?j:j-s.top()-1));
			}
			s.push(j);
		}
		while(!s.empty()) s.pop();
	}
	printf("%d\n", result);

	return 0;
}