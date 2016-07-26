#include <cstdio>
using namespace std;

int main(){
	int cnt[26]={0};
	char c;
	while((c=getchar())>0)
		cnt[c-'a']++;
	for(int i=0; i<26; i++)
		printf("%d ", cnt[i]);
}