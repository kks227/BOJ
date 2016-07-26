#include <cstdio>
#include <stack>
using namespace std;

int main(){
	int N, result = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		stack<char> S;
		char word[100001];
		scanf("%s", word);
		for(int i=0; word[i]; i++){
			if(!S.empty() && S.top()==word[i]) S.pop();
			else S.push(word[i]);
		}
		result += S.empty();
	}
	printf("%d\n", result);
}