#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		char P[100001];
		int N;
		deque<int> D;
		scanf("%s %d\n[", P, &N);
		int x = 0;
		while(1){
			char c = getchar();
			if(c >= '0' && c <= '9') x = x*10 + c-'0';
			else{
				if(x > 0) D.push_back(x);
				x = 0;
				if(c == ']') break;
			}
		}
		bool error = false, rev = false;
		for(int i=0; P[i]; i++){
			if(P[i] == 'R') rev = !rev;
			else{
				if(D.empty()){
					error = true;
					break;
				}
				if(rev) D.pop_back();
				else D.pop_front();
			}
		}
		if(error) puts("error");
		else{
			putchar('[');
			if(rev) reverse(D.begin(), D.end());
			for(int i=0; i<D.size(); i++){
				printf("%d", D[i]);
				if(i < D.size()-1) putchar(',');
			}
			puts("]");
		}
	}
}