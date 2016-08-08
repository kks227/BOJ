#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		char A[101], B[101];
		scanf("%s %s", A, B);
		int cnt[26] = {0};
		for(int i=0; A[i]; i++) cnt[A[i]-'a']++;
		for(int i=0; B[i]; i++) cnt[B[i]-'a']--;
		bool anagram = true;
		for(int i=0; i<26; i++) if(cnt[i]) anagram = false;
		printf("%s & %s are %sanagrams.\n", A, B, anagram ? "" : "NOT ");
	}
}