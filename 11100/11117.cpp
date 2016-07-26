#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int limit[26] = {0}, W;
		char box[1001];
		scanf("%s %d", box, &W);
		for(int i=0; box[i]; i++)
			limit[box[i]-'A']++;
		for(int i=0; i<W; i++){
			int cnt[26];
			char word[101];
			scanf("%s", word);
			memcpy(cnt, limit, sizeof(cnt));
			bool success = true;
			for(int i=0; word[i]; i++)
				if(--cnt[word[i]-'A'] < 0){
					success = false;
					break;
				}
			puts(success ? "YES" : "NO");
		}
	}
}