#include <cstdio>
#include <cctype>
using namespace std;

int main(){
	bool flag[128] = {false,};
	flag['A'] = flag['E'] = flag['I'] = flag['O'] = flag['U'] = true;
	flag['a'] = flag['e'] = flag['i'] = flag['o'] = flag['u'] = true;
	int T;
	scanf("%d\n", &T);
	for(int t = 0; t < T; ++t){
		int cnt[2] = {0,};
		while(1){
			char c = getchar();
			if(c == '\n') break;
			if(isalpha(c)) ++cnt[flag[c]];
		}
		printf("%d %d\n", cnt[0], cnt[1]);
	}
}