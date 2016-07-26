#include <cstdio>
using namespace std;

int main(){

	char S[1001];
	bool result;
	for(int t=1; ; t++){
		int cnt[26] = {0};
		scanf("%s", S);
		if(S[0] >= 'a'){
			for(int i=0; S[i]; i++)
				cnt[S[i]-'a']++;
			scanf("%s", S);
			for(int i=0; S[i]; i++)
				cnt[S[i]-'a']--;
			result = true;
			for(int i=0; i<26; i++){
				if(cnt[i]){
					result = false;
					break;
				}
			}
			printf("Case %d: %s\n", t, result?"same":"different");
		}
		else{
			scanf("%s", S);
			break;
		}
	}

	return 0;
}