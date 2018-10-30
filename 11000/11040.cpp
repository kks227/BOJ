#include <cstdio>
#include <stack>
using namespace std;

int main(){
	while(1){
		int N;
		scanf("%d\n", &N);
		if(N == 0) break;
		if(N == 1){
			printf("%c\n", getchar());
			continue;
		}

		stack<int> S1;
		stack<char> S2;
		for(int i = 0; i < N; ++i){
			int d = 0;
			char c;
			while(1){
				c = getchar();
				if(c == '.') ++d;
				else break;
			}
			while(d < S1.size()){
				int k = S1.top(); S1.pop(); S2.pop();
				int temp = S1.top(); S1.pop();
				if(S2.top() == '+') S1.push(temp + k);
				else S1.push(temp * k);
			}

			if(c == '+'){
				S1.push(0);
				S2.push('+');
			}
			else if(c == '*'){
				S1.push(1);
				S2.push('*');
			}
			else{
				int k = c-'0';
				int temp = S1.top(); S1.pop();
				if(S2.top() == '+') S1.push(temp + k);
				else S1.push(temp * k);
			}
			getchar();
		}
		while(S1.size() > 1){
			int k = S1.top(); S1.pop(); S2.pop();
			int temp = S1.top(); S1.pop();
			if(S2.top() == '+') S1.push(temp + k);
			else S1.push(temp * k);
		}
		printf("%lld\n", S1.top());
	}
}