#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

int main(){
	int cnt[26] = {0};
	char c;
	while(scanf("%c", &c) > 0)
		if(islower(c)) cnt[c-'a']++;
	int k = 0;
	for(int i=0; i<26; i++)
		k = max(k, cnt[i]);
	for(int i=0; i<26; i++)
		if(cnt[i] == k) putchar(i+'a');
}