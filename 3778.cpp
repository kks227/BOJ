#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main(){

	int N, cnt[26], result;
	char c;
	scanf("%d", &N);
	getchar();
	for(int i=1; i<=N; i++){
		memset(cnt, 0, sizeof(int)*26);
		result = 0;
		while((c=getchar()) != '\n')
			cnt[c-'a']++;
		while((c=getchar()) != '\n')
			cnt[c-'a']--;
		for(int j=0; j<26; j++)
			result += abs(cnt[j]);
		printf("Case #%d: %d\n", i, result);
	}

	return 0;
}