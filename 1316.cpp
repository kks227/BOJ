#include <cstdio>
using namespace std;

int main(){
	int N, result = 0;
	scanf("%d\n", &N);
	for(int i=0; i<N; i++){
		bool exist[26] = {0};
		int c, prev = '\n';
		bool group = true;
		while((c=getchar())>'\n'){
			if(exist[c-'a'] && prev!=c) group = false;
			else exist[c-'a'] = true;
			prev = c;
		}
		result += group;
	}
	printf("%d\n", result);
}