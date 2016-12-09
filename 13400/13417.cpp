#include <cstdio>
#include <deque>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N;
		scanf("%d", &N);
		deque<char> D;
		for(int i=0; i<N; i++){
			char c;
			scanf(" %c", &c);
			if(D.empty() || c <= D.front()) D.push_front(c);
			else D.push_back(c);
		}
		for(int i=0; i<N; i++){
			putchar(D.front());
			D.pop_front();
		}
		puts("");
	}
}