#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int cnt[26];
	memset(cnt, -1, sizeof(cnt));
	char S[101];
	scanf("%s", S);
	for(int i=0; S[i]; i++)
		if(cnt[S[i]-'a']==-1) cnt[S[i]-'a'] = i;
	for(int i=0; i<26; i++)
		printf("%d ", cnt[i]);
}