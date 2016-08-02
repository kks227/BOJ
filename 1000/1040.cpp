#include <cstdio>
#include <cstring>
using namespace std;

int len, K, dp[20][11][1024][2];
char N[20];

// return value: 1-possible, 0-impossible
int integer(int pos, int remain, int used, bool cmp){
	int &ret = dp[pos][remain][used][cmp];
	if(ret != -1) return ret;
	if(pos == len) return ret = !remain;

	ret = 0;
	for(int d=(cmp?N[pos]-'0':0); d<10; d++){
		bool nextCmp = (cmp && d == N[pos]-'0');
		if(used & 1<<d){ // used digit
			ret |= integer(pos+1, remain, used, nextCmp);
		}
		else{ // unused digit
			if(remain > 0) ret |= integer(pos+1, remain-1, used | 1<<d, nextCmp);
		}
	}
	return ret;
}

void track(int pos, int remain, int used, bool cmp){
	if(pos == len) return;

	for(int d=(cmp?N[pos]-'0':0); d<10; d++){
		bool nextCmp = (cmp && d == N[pos]-'0');
		if(used & 1<<d){ // used digit
			if(integer(pos+1, remain, used, nextCmp)){
				putchar(d+'0');
				track(pos+1, remain, used, nextCmp);
				return;
			}
		}
		else{ // unused digit
			if(remain > 0 && integer(pos+1, remain-1, used | 1<<d, nextCmp)){
				putchar(d+'0');
				track(pos+1, remain-1, used | 1<<d, nextCmp);
				return;
			}
		}
	}
}

int main(){
	scanf("%s %d", N, &K);
	len = strlen(N);
	memset(dp, -1, sizeof(dp));
	// N의 자릿수로는 불가능
	if(!integer(0, K, 0, true)){
		// 자릿수를 늘려가며(len 증가) 가능한지 시도
		while(1){
			strcpy(N, "1000000000000000000");
			len++;
			memset(dp, -1, sizeof(dp));
			if(integer(0, K, 0, true)){
				track(0, K, 0, true);
				break;
			}
		}
	}
	// N의 자릿수로 가능
	else track(0, K, 0, true);
}