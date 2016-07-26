#include <cstdio>
#include <cstring>
using namespace std;

int len, cache[201];
char S[201];

int partStringCorrect(int start){
	int& ret = cache[start];
	if(ret != -1) return ret;
	if(start == len) return ret = true;
	if(start+1 == len) return ret = false;

	if(S[start] == '0'){
		if(S[start+1] == '1') return ret = partStringCorrect(start+2);
		else return ret = false;
	}
	else{
		int cnt = 0;
		for(int i=start+1; i<len; i++){
			if(S[i] == '1') break;
			cnt++;
		}
		if(cnt < 2) return ret = false;
		if(start+cnt+1 == len) return ret = false;
		if(start+cnt+2 == len) return ret = true;

		int i;
		for(i=start+cnt+2; i<len; i++){
			if(partStringCorrect(i)) return ret = true;
			if(S[i] == '0') break;
		}
		return ret = i==len;
	}
}

int main(){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%s", S);
		len = strlen(S);
		memset(cache, -1, sizeof(int)*201);
		puts(partStringCorrect(0)?"YES":"NO");
	}
}